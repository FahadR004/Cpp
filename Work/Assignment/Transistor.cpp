#include <iostream>
#include <cmath>
class Transistor {
    private:
        float channel_length;
        float threshold_voltage;
        float gate_voltage;
        float current_state; 
    public: 
        Transistor(float cl, float tv, float gv, float cs) : channel_length(cl), threshold_voltage(tv), gate_voltage(gv), current_state(cs) {
            std::cout << "Threshold voltage: " << tv << std::endl; 
        };
        void applyGateVoltage(float gv) {
            std::cout << "Applying Gate Voltage: " << gv << " V" << std::endl;
            if (gv > threshold_voltage) {
                current_state = 1;
            } else {
                current_state = 0;
            }
            printCurrentState();
            float drain_current = (0.5) * (0.5) * (std::pow((gv - threshold_voltage), 2));
            std::cout << "Drain Current: " << drain_current << " mA" << std::endl;
        }
        void printCurrentState() {
            if (this->current_state == 1) {
                std::cout << "State: ON" << std::endl;
            } else {
                std::cout << "State: OFF" << std::endl;
            }
        }
};
int main() {
    Transistor transistor(10, 1.0, 0, 0);
    transistor.applyGateVoltage(0.5);
    transistor.applyGateVoltage(1.2);
    return 0;
}