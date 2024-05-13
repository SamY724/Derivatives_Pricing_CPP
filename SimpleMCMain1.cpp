// requires Random1.cpp
#include "Random1.h"
#include <iostream>
#include <cmath>

//namespace type beat
using namespace std;

//function declaration
double SimpleMonteCarlo1(
    double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths,
    string optionType
);


// driver
int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    string optionType;

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

    cout << "option type: ";
    cin >> optionType;

    double result = SimpleMonteCarlo1(
        Expiry,
        Strike,
        Spot,
        Vol,
        r,
        NumberOfPaths,
        optionType);

    cout << "The price is: \n" << result;

    double tmp;
    cout<< "\n";
    cin >> tmp;

    return 0;
}

// black scholes parameters
double SimpleMonteCarlo1(
    double Expiry,
    double Strike,
    double Spot,
    double Vol,
    double r,
    unsigned long NumberOfPaths,
    string optionType)

// calculations
{
    double variance = Vol * Vol * Expiry;   // variance calculation
    double rootVariance = sqrt(variance);   // square rooted variance
    double itoCorrection = -0.5 * variance; // adjustment term for the drift of the log

    double movedSpot = Spot * exp(r * Expiry + itoCorrection); // movedspot
    double thisSpot;
    double runningSum = 0;


    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller(); // calculates gaussian
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff;

        if (optionType == "put") {
            thisPayoff = Strike - thisSpot;
        }else {thisPayoff = thisSpot - Strike;}

        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff; // adds the current payoff of the path to the running sum
    }

    double mean = runningSum / NumberOfPaths; // averages the runningsum by paths
    mean *= exp(-r * Expiry);                 // weighting of the mean
    return mean;
}