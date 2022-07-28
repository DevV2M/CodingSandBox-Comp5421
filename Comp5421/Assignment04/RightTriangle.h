//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_RIGHTTRIANGLE_H
#define ASSIGNMENT04_RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle: public Triangle{

public:

    // Constructors
    RightTriangle(size_t b, char p = '*', string n = "Ladder");

    // DTOR
    virtual ~RightTriangle() = default;


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


#endif //ASSIGNMENT04_RIGHTTRIANGLE_H
