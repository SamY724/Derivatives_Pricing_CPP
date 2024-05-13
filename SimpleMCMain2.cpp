/*
requires
    PayOff1.cpp
    Random1.cpp
    SimpleMC.cpp
*/

#include "SimpleMC.h"
#include <iostream>

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter Expiry: ";
    cin >> Expiry;

    cout << "Enter Strike: ";
    cin >> Strike;

    cout << "Enter Spot: ";
    cin >> Spot;

    cout << "Enter Vol: ";
    cin >> Vol;

    cout << "Enter r: ";
    cin >> r;

    cout << "Enter No of Paths: ";
    cin >> NumberOfPaths;

    const PayOff callPayOff(Strike, PayOff::call);
    const PayOff putPayOff(Strike, PayOff::put);


    const double call_result = SimpleMonteCarlo2(
        callPayOff, Expiry, Spot, Vol, r, NumberOfPaths
    );

    const double put_result = SimpleMonteCarlo2(
        putPayOff, Expiry, Spot, Vol, r, NumberOfPaths
    );

    cout<<"The Prices are "<< call_result
                           << "for the call, and "
                           << put_result
                           << " for the put\n";

    double tmp;
    cin >> tmp;

    return 0;
}