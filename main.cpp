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
double term(double x, int n, int max)
{
    int i;
    double sum = x;

    for (i = 1; max >= i; i++)
        sum += x / i;

    return sum;
}

double mySin(double x)
{
    int i, sign = 1, maxPower = (int)x*21;
    double sum;

    for (i = 0; maxPower > i; i++, sign = -sign)
        sum = sum + sign * term(x, 2 * i + 1, maxPower);


    return sum;
}

double myCos(double x)
{

    return 0;
}

double myExp(double x)
{

    return 0;
}


int main() {

    double x;
    char more = 'y';
    do {
        cout << "\n\t\tInput X: ";
        cin  >> x;

        cout << "\n\t\t\t\tLibraryResult" << "\t\tMyResult";

        cout << "\nsin(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << mySin(x)
             << "\t\t\t" << setw(7) << setprecision(6) << sin(x);

        cout << "\ncos(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << myCos(x)
             << "\t\t\t" << setw(7) << setprecision(6) << cos(x);

        cout << "\nsin(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << myExp(x)
             << "\t\t\t" << setw(7) << setprecision(6) << exp(x);


        cout << "\n\t\tDo more (Y/N) ? ";
        cin  >> more;
    } while (more == 'y' || more == 'Y');


    return 0;
}