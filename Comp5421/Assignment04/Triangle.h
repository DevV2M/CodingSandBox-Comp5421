//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_TRIANGLE_H
#define ASSIGNMENT04_TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape {
protected:
    int base;
public:
    // CTOR
    Triangle(size_t h, size_t w, char p = '*', string n = "Triangle");

    // DTOR
    virtual ~Triangle() = default;

    // Member-function
    // Computes and returns the shape’s geometric area
    double areaGeo() const;
};


#endif //ASSIGNMENT04_TRIANGLE_H
