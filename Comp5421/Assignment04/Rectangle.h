//
// Created by Vithu Maheswaran on 2022-07-11.
//

#ifndef ASSIGNMENT04_RECTANGLE_H
#define ASSIGNMENT04_RECTANGLE_H


#include "Shape.h"

class Rectangle: public Shape {

public:

    // Constructors

    Rectangle(int height, int width, char pen = '*', string name = "Rectangle");

    // DTOR
    virtual ~Rectangle() = default;

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


#endif //ASSIGNMENT04_RECTANGLE_H
