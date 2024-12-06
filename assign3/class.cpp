#include "class.h"
#include <iostream>
MyClass::MyClass() : data(0) {
    std::cout << "Default Constructor" << std::endl;
}

MyClass::MyClass(int data){
    this->data = data;
    std::cout << "Constructor with data" << std::endl;
}

MyClass::~MyClass() {
    std::cout << "Destructor" << std::endl;
}

void MyClass::setData(int data) {
    this->data = data;
}

int MyClass::getData() const {
    return data;
}

bool MyClass::validData(int data) const {
    return data >= 0;
}