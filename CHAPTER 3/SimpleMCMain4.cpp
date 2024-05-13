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

    unsigned long optionType;

    cout << "Enter 0 for call, otherwise put: ";
    cin >> optionType;

    PayOff* thePayOffPtr;

    if(optionType == 0)
        thePayOffPtr = new PayOffCall(Strike);
    else
        thePayOffPtr = new PayOffPut(Strike);

    double result = SimpleMonteCarlo2(
        *thePayOffPtr,
        Expiry,
        Spot,
        Vol,
        r,
        NumberOfPaths);


    cout << "the price is: " << result << endl;

    double tmp;

    cin >> tmp;

    delete thePayOffPtr;

    return 0;
}