/******************************************************************************************
 * Shape.h
 * Created on:      5-Jan-2018 17:25:28
 * Original author: linx
 * Computer Science & Technology, Linx
 * Copyright (c) 2018-2023. All rights reserved.
 ******************************************************************************************/

#include <iostream>

class Base {
 protected:
    int i;
 public:
    explicit Base(int a)     { i = a; }
    virtual void display()
    { std::cout << "I am Base class object, i = " << i << std::endl; }
};

class Derived : public Base {
    int j;
 public:
    explicit Derived(int a, int b) : Base(a) { j = b; }
    void display() {
        std::cout << "I am Derived class object, i = "
        << i << ", j = " << j << std::endl;
    }
};

// Global method, Base class object is passed by value
void somefunc(Base obj) {
    obj.display();
}


// Global method, Base class object is passed by pointer
void somefuncpointer(Base *obj) {
    obj->display();
}


int main() {
    Base b(33);
    Derived d(45, 56);
    somefunc(b);
    somefunc(d);  // Object Slicing, the member j of d is sliced off
    Base *p = new Derived(78, 89);
    somefuncpointer(p);
    delete p;
    return 0;
}
/*
https://www.geeksforgeeks.org/object-slicing-in-c/
*/
