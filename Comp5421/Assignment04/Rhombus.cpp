//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "Rhombus.h"

// Constructors
Rhombus::Rhombus(size_t d, char p, string n) : Shape{p, n,d % 2 == 1 ? d : d + 1,d % 2 == 1 ? d : d + 1} {}

// Member-function
// Computes and returns the shape’s geometric area
double Rhombus::areaGeo() const { return height * width / 2.0; }

// Member-function
// Computes and returns the shape’s geometric perimeter
double Rhombus::perimeterGeo() const { return 2 * std::sqrt(2) * height; }

// Member-function
// Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
int Rhombus::areaScr() const {
    int n = width / 2;    // floor rounding
    return 2 * n * (n + 1) + 1;
}

// Member-function
// Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
int Rhombus::perimeterScr() const { return 2 * (height - 1); }

Canvas Rhombus::draw() const {
    Canvas can{getHeight(),getWidth(),' '};

    int right, left, h;
    right = left = h = getHeight() / 2;
    int i;
    for (i = 0; i <= h; i++) {
        for (int k = 0; k < getHeight(); k++) {
            if (k >= left && k <= right) {
                can.put(i,k,pen);
            }
        }
        left--;
        right++;
    }
    left = 1;
    right = getHeight() - 2;
    for (; i < getHeight(); i++) {
        for (int k = 0; k < getHeight(); k++) {
            if (k >= left && k <= right) {
                can.put(i,k,pen);
            }
        }
        left++;
        right--;
    }
    return can;
}