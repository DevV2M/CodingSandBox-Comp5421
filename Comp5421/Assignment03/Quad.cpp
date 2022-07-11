//
// Created by Vithu Maheswaran on 2022-07-06.
//

#include "Quad.h"
#include <string>
#include <vector>
#include <sstream>

using std::endl;
using std::cout;
using std::istream;
using std::ostream;
using std::max;

// Accessors
Quad Quad::get() const {
    return *this;
}

// Mutators
void Quad::set(const Quad &other) {
    for (size_t i{}; i < quad.size(); i++) {
        quad[i] = other.quad[i];
    }
}

// Normal CTOR
// Default values: double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0
Quad::Quad(double x1, double x2, double x3, double x4) : quad{x1, x2, x3, x4} {}

/** Overload the Compound Assignment Operators **/

// Quad+=Quad
Quad& Quad::operator+=(const Quad &other) {
    for (size_t i{}; i < quad.size(); i++) {
        quad[i] += other.quad[i];
    }
    return *this;
}

// Quad-=Quad
Quad& Quad::operator-=(const Quad &other) {
    for (size_t i{}; i < quad.size(); i++) {
        quad[i] -= other.quad[i];
    }
    return *this;
}

// Quad*=Quad
Quad& Quad::operator*=(const Quad &other) {

    double x0 = quad[0] * other.quad[0] + quad[1] * other.quad[3];
    double x1 = quad[0] * other.quad[1] + quad[1] * other.quad[2];
    double x2 = quad[3] * other.quad[1] + quad[2] * other.quad[2];
    double x3 = quad[3] * other.quad[0] + quad[2] * other.quad[3];

    quad[0] = x0;
    quad[1] = x1;
    quad[2] = x2;
    quad[3] = x3;

    return *this;
}

// Quad/=Quad
Quad& Quad::operator/=(const Quad &other) {
    *this *= other.inverse();
    return *this;
}

// Quad+=double
Quad& Quad::operator+=(double x) {
    for (size_t i{}; i < 4; i++) {
        quad[i] += x;
    }
    return *this;
}

// Quad-=double
Quad& Quad::operator-=(double x) {
    for (size_t i{}; i < 4; i++) {
        quad[i] -= x;
    }
    return *this;
}

// Quad*=double
Quad& Quad::operator*=(double x) {
    for (size_t i{}; i < 4; i++) {
        quad[i] *= x;
    }
    return *this;
}

// Quad/=double
Quad& Quad::operator/=(double x) {

    if (x == 0) throw std::exception(); // dividing by zero, throws error

    *this *= (1 / x); // X/alpha = X*alpha^-1
    return *this;
}

/** Overload the Basic Arithmetic Binary Operators **/
// Quad + Quad
Quad operator+(const Quad &lhs, const Quad &rhs) {
    Quad temp{lhs};
    return temp += rhs;
}

// Quad - Quad
Quad operator-(const Quad &lhs, const Quad &rhs) {
    Quad temp{lhs};
    return temp -= rhs;
}

// Quad * Quad
Quad operator*(const Quad &lhs, const Quad &rhs) {
    Quad temp{lhs};
    return temp *= rhs;
}

// Quad / Quad
Quad operator/(const Quad &lhs, const Quad &rhs) {
    Quad temp{lhs};
    return temp /= rhs;
}

// Quad + double
Quad operator+(const Quad &lhs, double x) {
    Quad temp{lhs};
    return temp += x;
}

// Quad - double
Quad operator-(const Quad &lhs, double x) {
    Quad temp{lhs};
    return temp -= x;
}

// Quad * double
Quad operator*(const Quad &lhs, double x) {
    Quad temp{lhs};
    return temp *= x;
}

// Quad / double
Quad operator/(const Quad &lhs, double x) {
    Quad temp{lhs};
    return temp /= x;
}

// double + Quad
Quad operator+(double x, const Quad &rhs) {
    return rhs + x;
}

// double - Quad
Quad operator-(double x, const Quad &rhs) {
    return -(rhs - x);
}

// double * Quad
Quad operator*(double x, const Quad &rhs) {
    return rhs * x;
}

// double / Quad
Quad operator/(double x, const Quad &rhs) {
    Quad quadInv{rhs.inverse()};
    return x * quadInv;
}

/** Overload the Relational and Equality operators **/

// Quad == Quad
bool operator==(const Quad &lhs, const Quad &rhs) {
    Quad quadDif{lhs - rhs};
    if (quadDif.absoluteValue() <= Quad::tolerance)
        return true;
    else
        return false;
}

// Quad != Quad
bool operator!=(const Quad &lhs, const Quad &rhs) {
    return !(lhs == rhs);
}

// Quad < Quad
bool operator<(const Quad &lhs, const Quad &rhs) {
    return ((lhs.absoluteValue() < rhs.absoluteValue()) && (lhs != rhs));
}

// Quad <= Quad
bool operator<=(const Quad &lhs, const Quad &rhs) {
    return (lhs < rhs || lhs == rhs);
}

// Quad > Quad
bool operator>(const Quad &lhs, const Quad &rhs) {
    return rhs < lhs;
}

// Quad >= Quad
bool operator>=(const Quad &lhs, const Quad &rhs) {
    return !(lhs < rhs);
}

/** Overload the Unary Increment and Decrement Operators **/

// +Quad
// @return Unary Plus
Quad Quad::operator+() {
    return *this;
}

//pre-increment ++Quad
Quad &Quad::operator++() {
    *this += 1;
    return *this;
}

//post-increment Quad++
Quad Quad::operator++(int) {
    Quad temp{*this};
    *this += 1;
    return temp;
}

// -Quad
// @return Unary Minus
Quad Quad::operator-() {
    return *this*(-1.0);
}

//pre-decrement --Quad
Quad &Quad::operator--() {
    *this -= 1;
    return *this;
}

//post-decrement Quad--
Quad Quad::operator--(int) {
    Quad temp{*this};
    *this -= 1;
    return temp;
}

/** Overload the Subscript Operator[], both const and non-const Versions **/

const double &Quad::operator[](int index) const {
    if (index < 1 || index > 4) throw std::out_of_range("index out of range"); // Index invalid.
    return quad[index - 1];
}

double &Quad::operator[](int index) {
    if (index < 1 || index > 4) throw std::out_of_range("index out of range"); // Index invalid.
    return quad[index - 1];
}

/** Turn Objects of Quad Into Function Objects **/

// Returns the largest coordinate values of the invoking Quad object.
double Quad::operator()() {
    double max{quad[0]};
    for (double x: quad) {
        if (max < x) max = x;
    }
    return max;
}

// Returns the i’th coordinate value of the invoking Quad object.
double Quad::operator()(size_t i) {
    return (*this)[i]; // Out of bound error handled by subscript operator
}

// Returns the larger of the i’th and j’th coordinate values of the invoking Quad object.
double Quad::operator()(size_t i, size_t j) {
    return std::max({(*this)[i],(*this)[j]});
}

// Returns the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object.
double Quad::operator()(size_t i, size_t j, size_t k) {
return std::max({(*this)[i],(*this)[j],(*this)[k]});
}

// Returns the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object.
double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
    return (*this)();
}

/** Overload the insertion operator<< for a writing Quad object to an Output Stream **/
ostream &operator<<(ostream &out, const Quad &aQuad) {
    out << "[" << aQuad[1] << ", " << aQuad[2] << ", " << aQuad[3] << ", " << aQuad[4] << "]";
    return out;
}

/** Overload the extraction (input) operator>> for reading a Quad object from an Input Stream **/
// >>
istream &operator>>(istream &in, Quad &quad) {

    std::string line;
    std::string num;
    getline(in, line);
    std::vector<double> nlist;
    std::istringstream is(line);
    while (is >> num) {
        nlist.push_back(stod(num));
    }
    auto it = nlist.begin();
    quad.quad[0] = *it;
    it++;
    quad.quad[1] = *it;
    it++;
    quad.quad[2] = *it;
    it++;
    quad.quad[3] = *it;
    it++;
    return in;
}

/** absoluteValue() member function **/
// Computes and returns the absolute value of the invoking object.
double Quad::absoluteValue() const {
    double absVal{};
    for (double val: quad) { // val is a copy, not a reference
        if (val < 0) {
            val *= -1;
        }
        absVal += val;
    }
    return absVal;
}

/** inverse() member function **/
// Computes and returns the inverse of the invoking Quad object.

Quad Quad::inverse() const {

    double beta = quad[0] * quad[2] - quad[1] * quad[3];

    // prevent 1/0
    if (beta == 0) throw std::exception();

    double betaInv = 1.0 / beta;

    Quad temp{this->quad[2], -1.0 * this->quad[1], this->quad[0], -1 * this->quad[3]};
    temp *= betaInv;

    return temp;
}