#include <iostream>

class Father {
    public: 
        void intro() {
            std::cout << "I am the father" << std::endl;
        }
    private: 
        void gene1() {
            std::cout << "print" << std::endl;
        }
    protected: 
        void somefunc() {
            std::cout << "protected function" << std::endl;
        }

};

class Mother {
    public:
        void intro() {
            std::cout << "I am the mother" << std::endl;
        }
        void gene2() {
            std::cout << "print" << std::endl;
        }
};

class Child : public Father, public Mother {
    public:
        void intro() {
            std::cout << "I am the child " << std::endl;
        }
};

int main() {
    Child child;

    child.intro();
    child.gene1();
    child.somefunc();
    return 0;
}

