#include "PayOff1.h"
#include <algorithm>


using std::max;

//constructs payoff object (functor now) with strike price and the options type (call or put)
PayOff::PayOff(double Strike_, OptionType TheOptionsType_) 
:
    Strike(Strike_), TheOptionsType(TheOptionsType_)
{
}

//method to calculate payoff
double PayOff::operator ()(double spot) const
{

    switch (TheOptionsType)
    {
    case call:
    //calcing for a call option
        return max(spot-Strike, 0.0);

    case put:
    //calcing for a put option
        return max(Strike-spot, 0.0);

    default:
    //handle unexpected error from undefined type
        throw("unknown option type found. ");    
    }
}