#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff //payoff class
{
    public: //public component
        enum OptionType {call,put}; //call to buy or put to sell the option
        PayOff(double Strike_, OptionType TheOptionsType_); //PayOff function taking strike price, option type, and
        double operator()(double Spot) const; // overloaded main method

    private:
        double Strike; //strike price of option, does not need to be adjusted by the class at any point
        OptionType TheOptionsType; // specified option type
};
#endif