//
// Created by Vithu Maheswaran on 2022-07-06.
//

#ifndef ASSIGNMENT03_QUAD_H
#define ASSIGNMENT03_QUAD_H

#include <array>
#include <iostream>

using std::ostream;
using std::istream;

class Quad {
private:
    std::array<double, 4> quad{};

    double max(std::vector<double>& list);

public:
    static constexpr double tolerance{1.0E-6}; // C++17 and later

    Quad get() const;

    void set(const Quad &);

    Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0);

    Quad() = delete;

    Quad(const Quad &other) = default;

    Quad(Quad &&other) = default;

    Quad &operator=(const Quad &other) = default;

    Quad &operator=(Quad &&other) = default;

    virtual ~Quad() = default;

    /** Overload the Compound Assignment Operators **/

    // Quad+=Quad
    Quad& operator +=(const Quad &other);

    // Quad-=Quad
    Quad& operator -=(const Quad &other);

    // Quad*=Quad
    Quad& operator *=(const Quad &other);

    // Quad/=Quad
    Quad& operator /=(const Quad &other);

    // Quad+=double
    Quad& operator +=(double x);

    // Quad-=double
    Quad& operator -=(double x);

    // Quad*=double
    Quad& operator *=(double x);

    // Quad/=double
    Quad& operator /=(double x);

    /** Overload the Basic Arithmetic Binary Operators **/
    // Quad + Quad
    friend Quad operator+(const Quad& lhs, const Quad& rhs);

    // Quad - Quad
    friend Quad operator-(const Quad& lhs, const Quad& rhs);

    // Quad * Quad
    friend Quad operator*(const Quad& lhs, const Quad& rhs);

    // Quad / Quad
    friend Quad operator/(const Quad& lhs, const Quad& rhs);

    // Quad + double
    friend Quad operator+(const Quad& lhs, double x);

    // Quad - double
    friend Quad operator-(const Quad& lhs, double x);

    // Quad * double
    friend Quad operator*(const Quad& lhs, double x);

    // Quad / double
    friend Quad operator/(const Quad& lhs, double x);

    // double + Quad
    friend Quad operator+(double x,const Quad& rhs);

    // double - Quad
    friend Quad operator-(double x,const Quad& rhs);

    // double * Quad
    friend Quad operator*(double x,const Quad& rhs);

    // double / Quad
    friend Quad operator/(double x,const Quad& rhs);

    /** Overload the Relational and Equality operators **/

    // Quad == Quad
    friend bool operator==(const Quad& lhs,const Quad& rhs);

    // Quad != Quad
    friend bool operator!=(const Quad& lhs,const Quad& rhs);

    // Quad < Quad
    friend bool operator<(const Quad& lhs,const Quad& rhs);

    // Quad <= Quad
    friend bool operator<=(const Quad& lhs,const Quad& rhs);

    // Quad > Quad
    friend bool operator>(const Quad& lhs,const Quad& rhs);

    // Quad >= Quad
    friend bool operator>=(const Quad& lhs,const Quad& rhs);

    /** Overload the Unary Increment and Decrement Operators **/

    // +Quad
    Quad operator+();

    //pre-increment ++Quad
    Quad& operator ++();

    //post-increment Quad++
    Quad operator ++(int);

    // -Quad
    Quad operator-();

    //pre-decrement --Quad
    Quad& operator --();

    //post-decrement Quad--
    Quad operator --(int);

    /** Overload the Subscript Operator[], both const and non-const Versions **/

    const double& operator[](int index) const;

    double& operator[](int index);

    /** Turn Objects of Quad Into Function Objects **/

    // Returns the largest coordinate values of the invoking Quad object.
    double operator()();

    // Returns the i’th coordinate value of the invoking Quad object.
    double operator()(size_t i);

    // Returns the larger of the i’th and j’th coordinate values of the invoking Quad object.
    double operator()(size_t i, size_t j);

    // Returns the largest of the i’th, j’th, and k’th coordinate values of the invoking Quad object.
    double operator() (size_t i, size_t j, size_t k);

    // Returns the largest of the i’th, j’th, k’th, and l’th coordinate values of the invoking Quad object.
    double operator() (size_t i, size_t j, size_t k, size_t l);

    /** Overload the extraction (input) operator>> for reading a Quad object from an Input Stream **/
    friend ostream& operator<<(ostream&, const Quad&);

    /** Overload the insertion (output) operator<< for a writing Quad object to an Output Stream **/
    friend istream & operator >>(istream & in, Quad & quad);

    /** absoluteValue() member function **/
    // Computes and returns the absolute value of the invoking object.
    double absoluteValue() const;

    /** inverse() member function **/
    // Computes and returns the inverse of the invoking Quad object.
    Quad inverse() const;
};



#endif //ASSIGNMENT03_QUAD_H
