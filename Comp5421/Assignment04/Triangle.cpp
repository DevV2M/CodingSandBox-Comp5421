//
// Created by Vithu Maheswaran on 2022-07-11.
//

#include "Triangle.h"

Triangle::Triangle(size_t h, size_t w, char p, string n) : Shape{p, n, h, w} {}

// Member-function
// Computes and returns the shape’s geometric area
double Triangle::areaGeo() const { return getHeight() * base / 2.0; }