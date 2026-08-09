#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

class Wire {
    private:
        int wire_id;
        int x1, y1; // Start Coordinates
        int x2, y2; // End Coordinates
        std::string metal_layer;
    public:
        Wire(int id, int x1, int y1, int x2, int y2, std::string metal_layer) : wire_id(id), x1(x1), y1(y1), x2(x2), y2(y2), metal_layer(metal_layer) {
        };
        int getX1() {
            return x1;
        }
        int getY1() {
            return y1;
        }
        int getX2() {
            return x2;
        }
        int getY2() {
            return y2;
        }
        std::string getLayer()  const {
            return metal_layer;
        }
        // I don't need setters in this problem so I didn't initialize them
};

class DesignRuleChecker {
    public:
        bool getDRCReport(std::vector<Wire> grid, Wire new_wire) {
            bool violation_found = false;
            for (size_t i = 0; i < grid.size(); i++) {
               if (checkViolation(grid[i], new_wire)) {
                   violation_found = true;
               }
            }
            return violation_found;
        }
        double getDistances(Wire wire1, Wire wire2) {
            int a_xmin = std::min(wire1.getX1(), wire1.getX2());
            int a_xmax = std::max(wire1.getX1(), wire1.getX2());
            int b_xmin = std::min(wire2.getX1(), wire2.getX2());
            int b_xmax = std::max(wire2.getX1(), wire2.getX2());

            int a_ymin = std::min(wire1.getY1(), wire1.getY2());
            int a_ymax = std::max(wire1.getY1(), wire1.getY2());
            int b_ymin = std::min(wire2.getY1(), wire2.getY2());
            int b_ymax = std::max(wire2.getY1(), wire2.getY2());    

            // Find gap in x
            // x-shadow is x1 and x2 coordinates of wireA and wireB
            // 0, a_min - b_max, b_min - a_max
            int gap_x = std::max({0, a_xmin - b_xmax, b_xmin - a_xmax});
            // Find gap in y
            int gap_y = std::max({0, a_ymin - b_ymax, b_ymin - a_ymax});

            if (gap_x == 0 || gap_y == 0) {
                return std::max(gap_x, gap_y);
            } 
            return std::sqrt(static_cast<double>(gap_x) * gap_x + static_cast<double>(gap_y) * gap_y);        
        }

        bool checkViolation(const Wire& wire1, const Wire& wire2) {
            if (wire1.getLayer() != wire2.getLayer()) {
                std::cout << "  Different layers (" << wire1.getLayer() << " vs " 
                        << wire2.getLayer() << ") - overlap allowed, skipping check." << std::endl;
                return false;  // never a violation across layers
            }

            double distance = getDistances(wire1, wire2);
            if (distance < 5) {
                std::cout << "Violation Found!" << std::endl;
                std::cout << "Actual Spacing = " << distance << " Units" << std::endl;
                return true;
            } else {
                std::cout << "No Violation Found" << std::endl;
                return false;
            }
        }
      
};

class LayoutGrid {
    public: 
        std::vector<Wire> grid;
        DesignRuleChecker DRC;

        void addWire(int id, int x1, int y1, int x2, int y2, std::string metal_layer) {
            Wire new_wire(id, x1, y1, x2, y2, metal_layer);
            if (!grid.empty()) {
                DRC.getDRCReport(grid, new_wire);
            }
            grid.push_back(new_wire);
            std::cout << "Wire " << id << " Added!" << std::endl;
        }
};

int main() {
    LayoutGrid layout;
 
    std::cout << "=== Test 1: Parallel overlap case (expect VIOLATION, distance = 3) ===" << std::endl;
    layout.addWire(1, 0, 0, 0, 100, "Metal1");   // Wire A: vertical, x=0, y:0->100
    layout.addWire(2, 3, 40, 3, 60, "Metal1");   // Wire B: vertical, x=3, y:40->60 (3 units away, overlapping y-range)
 
    std::cout << "=== Test 2: Diagonal, no-overlap case (expect OK, distance ~= 12.81) ===" << std::endl;
    LayoutGrid layout2;
    layout2.addWire(3, 0, 0, 10, 0, "Metal1");    // Wire C: horizontal, y=0, x:0->10
    layout2.addWire(4, 20, 8, 20, 15, "Metal1");  // Wire D: vertical, x=20, y:8->15
    
    std::cout << "=== Test 4: Wires far apart (expect OK) ===" << std::endl;
    LayoutGrid layout4;
    layout4.addWire(5, 0, 0, 5, 0, "Metal1");
    layout4.addWire(6, 0, 50, 5, 50, "Metal1");   // 50 units away in y

    std::cout << "=== Test 5: Same coordinates, DIFFERENT layers (expect OK, overlap allowed) ===" << std::endl;
    LayoutGrid layout6;
    layout6.addWire(7, 0, 0, 0, 100, "Metal1");
    layout6.addWire(8, 0, 0, 0, 100, "Metal2");   // identical coordinates, distance would be 0, but different layer
 
    std::cout << "=== Test 6: Same coordinates, SAME layer (expect VIOLATION, true overlap) ===" << std::endl;
    LayoutGrid layout7;
    layout7.addWire(9, 0, 0, 0, 100, "Metal1");
    layout7.addWire(10, 0, 0, 0, 100, "Metal1");   // identical coordinates, same layer -> must be flagged
 
 
}