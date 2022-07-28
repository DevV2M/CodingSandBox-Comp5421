//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "AcuteTriangle.h"

// Constructors
AcuteTriangle::AcuteTriangle(size_t b, char pen, string name) : Triangle{((b % 2 == 1 ? b : b + 1) + 1) / 2,
                                                                      b % 2 == 1 ? b : b + 1, pen, name} {}

// Member-function
// Computes and returns the shape’s geometric perimeter
double AcuteTriangle::perimeterGeo() const {
    return base + std::sqrt(base * base + 4 * getHeight() * getHeight());
}

// Member-function
// Computes and returns the shape’s screen area, the number of characters forming the textual image of the shape
int AcuteTriangle::areaScr() const { return getHeight() * getHeight(); }

// Member-function
// Computes and returns the shape’s screen perimeter, the number of characters on the borders of the textual image of the shape
int AcuteTriangle::perimeterScr() const { return 4 * (getHeight() - 1); }

Canvas AcuteTriangle::draw() const {
    Canvas can{getHeight(), getWidth(), ' '};
    int right, left, h;
    right = left = h = getHeight();

    for (int i = 0; i < h; i++) {
        for (int k = 0; k <= base; k++) {
            if (k >= left - 1 && k <= right - 1) {
                can.put(i, k, pen);
            }
        }
        left--;
        right++;
    }
    return can;
}