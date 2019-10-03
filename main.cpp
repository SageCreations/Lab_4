/*
 * Edward Cruz, October 1, 2019
 * Lab_4, Compare library result sin(x), cos(x) and exp(x) with my calculation for them.
 * My output should be looks like the following. You can NOT use power(x,n) and fact(n)
 * functions to implement your sine, cosine, or exponential functions.
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//power and factorial function
double term(double x, int factorial)
{
    int i;
    double sum = 1.0;

    for (i = factorial; i > 0; i--)
        sum *= x / i;


    return sum;
}

double mySin(double x)
{
    int i, sign = 1, maxPower = (int)(abs(x))*21;
    double sum = 0.0;

    for (i = 0; maxPower >= i; i++, sign = -sign)
        sum += sign * term(x, 2 * i + 1);

    return sum;
}

double myCos(double x)
{
    int i, sign = 1, maxPower = (int) (abs(x)) * 21;
    double sum = 0.0;

    for (i = 0; maxPower >= i; i++, sign = -sign)
        sum += sign * term(x, 2 * i);

    return sum;
}

double myExp(double x)
{
    int i, maxPower = (int)(abs(x))*21;
    double sum = 1.0;

    for (i = 1; maxPower >= i; i++)
        sum += term(x, i);

    return sum;
}


int main() {

    double x;
    char more = 'y';
    do {
        cout << "\n\t\tInput X: ";
        cin  >> x;

        cout << "\n\t\tLibraryResult" << "\tMyResult";

        cout << fixed;
        cout << "\nsin(" << setw(6) << setprecision(2 ) << x << ")"
             << "\t" << setw(11) << setprecision(6 ) << sin(x)
             << "\t" << setw(8) << setprecision(6) << mySin(x);

        cout << "\ncos(" << setw(6) << setprecision(2) << x << ")"
             << "\t" << setw(11) << setprecision(6) << cos(x)
             << "\t" << setw(8) << setprecision(6) << myCos(x);

        cout << "\nexp(" << setw(6) << setprecision(2) << x << ")"
             << "\t" << setw(11) << setprecision(6) << exp(x)
             << "\t" << setw(8) << setprecision(6) << myExp(x);


        cout << "\n\t\tDo more (Y/N) ? ";
        cin  >> more;
    } while (more == 'y' || more == 'Y');


    return 0;
}