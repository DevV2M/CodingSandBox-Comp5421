//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_RHOMBUS_H
#define ASSIGNMENT04_RHOMBUS_H

#include "Shape.h"

class Rhombus: public Shape{

public:

    // Constructors
    Rhombus(size_t d, char p = '*', string n = "Rhombus");

    // DTOR
    virtual ~Rhombus() = default;

    // Member-function
    // Computes and returns the shape’s geometric area
    virtual double areaGeo() const override;

    // Member-function
    // Computes and returns the shape’s geometric perimeter
    virtual double perimeterGeo() const override;

    // Member-function
    // Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
    virtual int areaScr() const override;

    // Member-function
    // Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
    virtual int perimeterScr() const override;

    virtual Canvas draw() const override;
};


#endif //ASSIGNMENT04_RHOMBUS_H
