#include <iostream>
#include "fraction.h"
#include "term.h"
#include "polynomial.h"

using namespace std;

void getFrac(string title, fraction &frac);
void output(fraction x, fraction y, char op);
void getTerm(string title, term &t);
void getPoly(string title, polynomial &p);

int main()
{

//    fraction x = 2.5;
//    cout << x << endl;
//    fraction y(2.5);
//    cout << y << endl;
//    fraction z(2.50);
//    cout << z << endl;

//    term a(2,2), b(2,2);
//    cout << a << " "<< b << endl;
//    cout << a + b << endl;
//    cout << a - b << endl;
//     term a, b;

//     getTerm("Please enter your first term: ", a);
//     getTerm("Please enter your second term: ", b);
//     cout << a << " "<< b << endl;
//     cout << a + b << endl;
//     cout << a - b << endl;
//     cout << a / b << endl;
//     cout << a * b << endl;




//    term a(-3,2), b(2,2);
    polynomial c, d;
    getPoly("Please enter your first polynomial", c);
    getPoly("Please enter your first polynomial", d);


    cout << "This is c: "<< c << endl;
    cout << "This is d: " << d << endl;
    cout << "This is c + d: " << c + d << endl;
    cout << "This is c - d: " << c - d << endl;
    cout << "This is c * d: " << c * d << endl;

//         getTerm("Please enter your first term: ", a);
//         getTerm("Please enter your second term: ", b);
//         cout << a << " "<< b << endl;
//         cout << a + b << endl;
//         cout << a - b << endl;
//         cout << a / b << endl;
//         cout << a * b << endl;


    return 0;
}

void getPoly(string title, polynomial &p)
{
    cout<<title;
    cin>>p;
    cout<<"You entered: "<<p<<endl;
}

void getTerm(string title, term &t)
{
    cout<<title;
    cin>>t;
    cout<<"You entered: "<<t<<endl;
}

void getFrac(string title, fraction &frac)
{
    cout<<title;
    cin>>frac;
    cout<<"You entered: "<<frac<<endl;
}

void output(fraction x, fraction y, char op)
{
    fraction z;
    switch(op)
    {
        case '+' : z = x + y;
                   break;
        case '-' : z = x - y;
                   break;
        case '*' : z = x * y;
                   break;
        case '/' : z = x / y;
    }
    cout<<x<<" "<<op<<" "<<y<<" = "<<z<<endl;
}
