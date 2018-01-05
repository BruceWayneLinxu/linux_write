/******************************************************************************************
 * Shape.h
 * Created on:      5-Jan-2018 17:25:28
 * Original author: linx
 * Computer Science & Technology, Linx
 * Copyright (c) 2018-2020. All rights reserved.
 ******************************************************************************************/
#include <iostream>

#define PI 3.14

struct Point {
    double x;
    double y;
};

struct Circle {
    double radius;
};

struct Rectangle {
    Point leftbottom;
    Point righttop;
};


template <typename T>
class Shape {
 public:
    Shape() {}
    virtual ~Shape() {}
    virtual double CalcPerimeter() = 0;
    void SetPara(T *value) {
        this->para_ = value;
    }
 protected:
    T *para_;
    double perimeter;
};


class CircleShape : public Shape<Circle> {
 public:
    CircleShape() {}
    ~CircleShape() {}

    double CalcPerimeter() {
        perimeter = PI * this->para_->radius * 2;
        return perimeter;
    }
};

class RectangleShape : public Shape<Rectangle> {
 public:
    RectangleShape() {}
    ~RectangleShape() {}

    double CalcPerimeter() {
        double width = this->para_->righttop.y - this->para_->leftbottom.y;
        double length = this->para_->righttop.x - this->para_->leftbottom.x;
        perimeter = (width + length) * 2;
        return perimeter;
    }
};

int main() {
    Circle circle_data;
    circle_data.radius = 3.0;
    Rectangle rectangle_data;
    rectangle_data.righttop.x = 9.0;
    rectangle_data.righttop.y = 15.0;
    rectangle_data.leftbottom.x = 2.0;
    rectangle_data.leftbottom.y = 3.0;

    Shape<Rectangle> *rectshape = new RectangleShape();
    rectshape->SetPara(&rectangle_data);
    std::cout << rectshape->CalcPerimeter() << std::endl;
    delete rectshape;

    Shape<Circle> *cirshape = new CircleShape();
    cirshape->SetPara(&circle_data);
    std::cout << cirshape->CalcPerimeter() << std::endl;
    delete cirshape;

    return 0;
}
