#include <iostream>

class Animal {
public:
    virtual void bark() {
        std::cout << "bark bark bark ..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark()  {
        std::cout << "Wang Wang Wang ..." << std::endl;
    }
};

class Cat : public  Animal {
public:
    void bark() {
        std::cout << "Miao miao miao ..." << std::endl;
    }
};

class Meow : public Animal {
public:
    void bark() {
        std::cout << "Mou mou mou ..." << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    Meow meow;

//    void* arr[3] = {&dog, &cat, &meow};
    Animal* arr[3] = {&dog, &cat, &meow};
    for (int i = 0; i < 3; i++) {
//        if (i == 0) {
//            ((Dog*)arr[i])->bark();
//        }
//        if (i == 1) {
//            ((Cat*)arr[i])->bark();
//        }
//        if (i == 2) {
//            ((Meow*)arr[i])->bark();
//        }
        arr[i]->bark();
    }


    return 0;
}