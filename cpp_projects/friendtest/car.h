#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
class House;
class Car {
 private:
    int y_;
 public:
    Car(int val):y_(val) {}
    ~Car(){}
    friend class House;
    void TestHouse(House & t);
};

#endif // CAR_H_INCLUDED
