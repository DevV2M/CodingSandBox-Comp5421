//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_ACUTETRIANGLE_H
#define ASSIGNMENT04_ACUTETRIANGLE_H

#include "Triangle.h"

class AcuteTriangle: public Triangle{

public:

    // Constructors
    AcuteTriangle(size_t b, char p = '*', string n = "Wedge");

    // DTOR
    virtual ~AcuteTriangle() = default;

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


#endif //ASSIGNMENT04_ACUTETRIANGLE_H
