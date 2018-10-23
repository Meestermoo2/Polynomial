#include "term.h"

term::term(char v)
{
//    std::cout << "single argument constructor term was fired" << std::endl;
    coeff = power = 0;
    variable = v;
}

term::term(const fraction &c, const fraction& p)
{
//    std::cout << "dual argument constructor term was fired" << std::endl;
    power = p;
    coeff = c;
}

term::~term()
{
//    std::cout << "deconstructor term was fired" << std::endl;
    coeff = power = 0;
    variable = ' ';
}

term::term(const term& other)
{
//    std::cout << "copy constructor term was fired" << std::endl;
    copy(other);
}

term& term::operator=(const term& other)
{
//    std::cout << "assignment operator term was fired" << std::endl;
    if(this != &other)
        copy(other);
    return *this;
}


fraction term::getPower()
{
    return power;
}

fraction term::getCoeff()
{
    return coeff;
}

void term::setTerm(const fraction &c, const fraction p)
{
//    std::cout << "set term was fired" << std::endl;
    power = p;
    coeff = c;
}


term& term::operator*=(const term& other)
{
    return (*this = *this * other);
}

term& term::operator/=(const term& other)
{
    return (*this = *this / other);
}

term& term::operator+=(const term& other)
{
    term temp = *this + other;
    if(temp != 0)
        *this = temp;
    return *this;
}

term& term::operator-=(const term& other)
{
    term temp = *this - other;
    if(temp != 0)
        *this = temp;
    return *this;
}

fraction term::evaluate(const fraction& other)
{
//   std::cout << "evaluate was fired" << std::endl;
   return coeff * (other^power);
}

fraction term::operator()(const fraction& other)
{
   return evaluate(other);
}


void term::copy(const term &other)
{
//    std::cout << "copy constructor term was fired" << std::endl;
    coeff = other.coeff;
    power = other.power;
}
