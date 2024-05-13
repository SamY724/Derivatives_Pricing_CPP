#include "SimpleMC2.h"
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

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    double resultCall = SimpleMonteCarlo2(
        callPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);

    double resultPut = SimpleMonteCarlo2(
        putPayOff,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);

    cout << "the prices are: "
         << resultCall
         << " for the call and: "
         << resultPut
         << " for the put\n"
         << endl;

    double tmp;

    cin >> tmp;

    return 0;
}