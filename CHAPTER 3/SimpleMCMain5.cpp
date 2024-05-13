#include "SimpleMC2.h"
#include "DoubleDigital.h"
#include <iostream>

using namespace std;

int main()
{
    double Expiry;
    double Low,Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter Expiry: ";
    cin >> Expiry;

    cout << "Enter Low: ";
    cin >> Low;

    cout << "Enter Up: ";
    cin >> Up;

    cout << "Enter Spot: ";
    cin >> Spot;

    cout << "Enter Vol: ";
    cin >> Vol;

    cout << "Enter r: ";
    cin >> r;

    cout << "Enter No of Paths: ";
    cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low,Up);

    double result = SimpleMonteCarlo2(
        thePayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);


    cout << "the price is: " << result << endl;

    double tmp;

    cin >> tmp;


    return 0;
}