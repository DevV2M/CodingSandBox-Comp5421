//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "Rectangle.h"

Rectangle::Rectangle(int h, int w, char p, string n): Shape(p,n,h,w){}

// Member-function
// Computes and returns the shape’s geometric area
double Rectangle::areaGeo() const { return height * width; }

// Member-function
// Computes and returns the shape’s geometric perimeter
double Rectangle::perimeterGeo() const { return 2 * (height + width); }

// Member-function
// Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
int Rectangle::areaScr() const { return areaGeo(); }

// Member-function
// Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
int Rectangle::perimeterScr() const { return perimeterGeo()-4;}

Canvas Rectangle::draw() const {
    Canvas can{height,width,' '};
    for(size_t i = 0; i < height; i++){
        for(size_t k = 0; k < width; k++){
            can.put(i ,k ,pen);
        }
    }
    return can;
}
