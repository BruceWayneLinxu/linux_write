#ifndef BUS_H_INCLUDED
#define BUS_H_INCLUDED
#include "car.h"
class Bus : public Car {
 private:
    double z_;
 public:
    Bus(int val, double dval): Car(val),z_(dval) {}
    ~Bus(){}
};
#endif // BUS_H_INCLUDED
