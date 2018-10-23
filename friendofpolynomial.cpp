#include "polynomial.h"

polynomial firstDerivative(const polynomial &other)
{
    polynomial temp;
    term newTerm;
    for(unsigned int i = 0; i < other.poly.size(); ++i)
    {
        newTerm.setTerm(
            other[i].getCoeff()*other[i].getPower() ,
            other[i].getPower()-1
            );
        temp.poly.push_back(newTerm);
    }
    return temp;
}


polynomial operator+(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        temp.poly.push_back(x[i]);
    for(unsigned int i = 0; i < y.poly.size(); ++i)
        temp.poly.push_back(y[i]);
    temp.sort();
    temp.combineTerms();
    return temp;
}


polynomial operator-(const polynomial &x, const polynomial &y)
{
    polynomial temp = x + y;
    return temp;
}


polynomial operator*(const polynomial &x, const polynomial &y)
{
    polynomial temp;
    for(unsigned int i = 0; i < x.poly.size(); ++i)
        for(unsigned int j = 0; j < y.poly.size(); ++j)
            temp.poly.push_back(x[i] * y[j]);
    temp.sort();
    temp.combineTerms();
    return temp;
}


//polynomial operator/(const polynomial &x, const polynomial &y)
//{
//    //do this with synthetic division.... hint...
//    //Also, does polynomial need to be changed to support division??
//}


std::ostream& operator<<(std::ostream& out, const polynomial &other)
{
    std::cout << " P << fired\n";

    for(unsigned int i = 0; i < other.poly.size(); ++i)
    {
        if(other[i]!= 0)
        {
            out<<other[i];
        }
    }


    return out;
}


std::istream& operator>>(std::istream& in, polynomial &p)
{
    std::cout << " P >> fired\n";

    term temp;
    while(in>>temp)
        p.poly.push_back(temp);
    p.sort();
    p.combineTerms();
    return in;
}
