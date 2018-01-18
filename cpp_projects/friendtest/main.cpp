#include <iostream>
#include "car.h"
#include "house.h"
#include "bus.h"

int main() {
    House bob(4);
    Car tom(5);
    tom.TestHouse(bob);
    bob.TestCar(tom);
    Bus road1(1,'b');
    road1.TestHouse(bob);
    bob.TestCar(road1);
    return 0;
}