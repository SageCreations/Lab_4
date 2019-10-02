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
double term(double x, int factorial, bool isExp)
{
    int i;
    double sum = 0;
    if (!isExp){
        for (i = factorial-1; i > 0; i--)
            sum = x * sum / i;
    }
    else {
        for (i = factorial-1; i > 0; i--)
            sum = 1 + (x * sum) / i;
    }


    return sum;
}

double mySin(double x)
{
    int i, sign = 1, maxPower = (int)x*21;
    double sum;

    for (i = 0; maxPower > i; i++, sign = -sign)
        sum += sign * term(x, 2 * i + 1, false);

    return sum;
}

double myCos(double x)
{
    int i, sign = 1, maxPower = (int)x*21;
    double sum;

    for (i = 1; maxPower >= i; i++, sign = -sign)
        sum += sign * term(x, 2 * i, false);

    return sum;
}

double myExp(double x)
{
    int i, maxPower = (int)x*21;
    double sum;

    for (i = 1; maxPower >= i; i++)
        sum = term(x, i, true);

    return sum;
}


int main() {

    double x;
    char more = 'y';
    do {
        cout << "\n\t\tInput X: ";
        cin  >> x;

        cout << "\n\t\t\tLibraryResult" << "\t\t\tMyResult";

        cout << "\nsin(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << mySin(x)
             << "\t\t\t" << setw(7) << setprecision(6) << sin(x);

        cout << "\ncos(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << myCos(x)
             << "\t\t\t" << setw(7) << setprecision(6) << cos(x);

        cout << "\nexp(" << setw(5) << x << ")"
             << "\t\t" << setw(11) << myExp(x)
             << "\t\t\t" << setw(7) << setprecision(6) << exp(x);


        cout << "\n\t\tDo more (Y/N) ? ";
        cin  >> more;
    } while (more == 'y' || more == 'Y');


    return 0;
}