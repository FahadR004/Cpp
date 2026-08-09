#include <iostream>
#include <vector>
#include <chrono>

// While propagation delay is fixed in real world and I could have defined it as a constant for each gate, I have calculated the delay of each gate by measuring time of the specific logical operation performed in code, which can give varying results on different machines.

class LogicGate {
    public:
        std::string gate_name;
        int num_inputs;
        int output;
        float delay;
        // A pure virtual function is declared with a 0
        virtual void evaluateOutput() = 0;
        // This makes the class an abstract class which cannot be instantiated 
};

class AND_Gate : public LogicGate {
    public:
        int input_A, input_B;
        AND_Gate() {
            gate_name = "AND Gate";
            num_inputs = 2;
        }
        void evaluateOutput() override {
            std::cout << gate_name << std::endl;
            std::cout << "Input A = ";
            scanf("%d", &input_A);
            std::cout << "Input B = ";
            scanf("%d", &input_B);
            auto start = std::chrono::steady_clock::now();
            output = (input_A && input_B); 
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            delay = elapsed.count();
            std::cout << "Output = " << output << std::endl;
        }
};

class OR_Gate : public LogicGate {
    public:
        int input_A, input_B;
        OR_Gate() {
            gate_name = "OR Gate";
            num_inputs = 2; 
        }
        void evaluateOutput() override {
            std::cout << gate_name << std::endl;
            std::cout << "Input A = ";
            scanf("%d", &input_A);
            std::cout << "Input B = ";
            scanf("%d", &input_B);
            auto start = std::chrono::steady_clock::now();
            output =  (input_A || input_B);
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            delay = elapsed.count();
            std::cout << "Output = " << output << std::endl;
        }
};

class NOT_Gate : public LogicGate {
    public:
        int input_A;
        NOT_Gate() {
            gate_name = "NOT Gate";
            num_inputs = 1;
        }
        void evaluateOutput() override {
            std::cout << gate_name << std::endl;
            std::cout << "Input A = ";
            scanf("%d", &input_A);
            auto start = std::chrono::steady_clock::now();
            output = !input_A;
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            delay = elapsed.count();
            std::cout << "Output = " << output << std::endl;
        }
};

class XOR_Gate : public LogicGate {
    public:
        XOR_Gate() {
            gate_name = "XOR Gate";
            num_inputs = 2;
        }
        void evaluateOutput() override {
            std::cout << gate_name << std::endl;
            int input_A, input_B;
            std::cout << "Input A = ";
            scanf("%d", &input_A);
            std::cout << "Input B = ";
            scanf("%d", &input_B);
            auto start = std::chrono::steady_clock::now();
            output = (input_A != input_B);
            auto end = std::chrono::steady_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
            delay = elapsed.count();
            std::cout << "Output = " << output << std::endl;
        }
};


int main() {
    std::vector<LogicGate*> arr; 
    AND_Gate and_gate;
    OR_Gate or_gate;
    XOR_Gate xor_gate;
    NOT_Gate not_gate;

    arr.push_back(&and_gate);
    arr.push_back(&or_gate);
    arr.push_back(&xor_gate);
    arr.push_back(&not_gate);

    for (LogicGate* gate : arr) {
        gate->evaluateOutput();
    }

    for (LogicGate* gate : arr) {
        std::cout << "Last Output of Gate " << gate->gate_name << ": " << gate->output << std::endl;
        std::cout << "Gate Delay: " << gate->delay << std::endl;

    }
}