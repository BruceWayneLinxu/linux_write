#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED
class Car;
class House {
 private:
    int x_;
 public:
    friend class Car;
    House(int val):x_(val) {}
    void TestCar(Car & f);
    ~House(){}
};
#endif // HOUSE_H_INCLUDED
