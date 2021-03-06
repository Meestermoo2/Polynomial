#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <fstream>
#include <vector>
#include "term.h"
#include "fraction.h"

class polynomial
{
    public:
        polynomial();
        ~polynomial();
        polynomial(const term &other);
        polynomial(const polynomial &other);
        polynomial& operator=(const polynomial &other);
        polynomial& operator+=(const polynomial &other);
        polynomial& operator-=(const polynomial &other);
        polynomial& operator/=(const polynomial &other);
        polynomial& operator*=(const polynomial &other);
        fraction operator()(const fraction &other);
        term operator[](unsigned int index) const;
        term& operator[](unsigned int index);

        friend
        polynomial firstDerivative(const polynomial &other);

        friend
        polynomial operator+(const polynomial &x, const polynomial &y);

        friend
        polynomial operator-(const polynomial &x, const polynomial &y);

        friend
        polynomial operator*(const polynomial &x, const polynomial &y);

        friend
        std::ostream& operator<<(std::ostream& out, const polynomial &p);

        friend
        std::istream& operator>>(std::istream& in,  polynomial &p);

     private:
        std::vector<term> poly;

        void copy(const polynomial &other);
        void sort();
        void combineTerms();
};

#endif // POLYNOMIAL_H
