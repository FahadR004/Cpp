#include <iostream>

class Engine {
    public: 
        Engine() {
            std::cout << "Engine created" << std::endl;
        }
};


class Car {
    private:    
        Engine engine; // Aggregation main aapne pointer banaya tha
    public: 
        Car() {
            std::cout << "Car created";
        }

};

int main () {
    Car car;
}