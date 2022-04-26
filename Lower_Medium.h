#pragma once
#include <iostream>
#include "Finance.h"
using namespace std;

class Lower_Medium : public Finance {
private:

    double h, t, f, o, w;

public:


    Lower_Medium() {

    }

    Lower_Medium(double housing, double transport, double food, double other, double wage) {

        h = housing;
        t = transport;
        f = food;
        o = other;
        w = wage;


    }


    Lower_Medium operator-(Lower_Medium m)
    {
        Lower_Medium temp;

        temp.h = h - m.h;                 //comparisons
        temp.t = t - m.t;
        temp.f = f - m.f;
        temp.o = o - m.o;
        temp.w = w - m.w;

        return (temp);
    }

    void Advice_(double& difference, bool& debt) {


        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month" << endl;

        }
        else {
            debt = true;

            cout << "You have spent " << difference*-1 << " euros more than you have earned this month." << endl;
            cout << "Please refer to your expenditures." << endl;

        }
        if (difference2>difference) {
            cout << " If you would spend as much as the estimated Minimum wage individual you can save " << difference2 << " per month.";
            cout << " This makes " << difference2 * 12 << " euros in one year." << endl;
        }
        else {
            cout << " This makes " << difference2 * 12 << " euros in one year." << endl;
        }

    }

    void Expenditure() {   //function overriding

        if (h < 0) {
            cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

        }

        if (t < 0) {
            cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

        }

        if (f < 0) {
            cout << "You spend " << f * -1 << " euros more on food than estimated." << endl;

        }

        if (o < 0) {
            cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

        }

        if ((h >= 0) && (t >= 0) && (f >= 0) && (o >= 0)) {
            cout << "Congratulations, you did not overspend";
        }




    }
};