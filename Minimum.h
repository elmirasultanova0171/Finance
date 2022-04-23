#pragma once
#include <iostream>
#include "Finance.h"
using namespace std;

class Minimum : public Finance {

private:

    double h, t, f, o, w;

public:

    Minimum() {

    }

    Minimum(double housing, double transport, double food, double other, double wage) {

        h = housing;
        t = transport;
        f = food;
        o = other;
        w = wage;

    }


    Minimum operator-(Minimum m)
    {
        Minimum temp;

        temp.h = h - m.h;
        temp.t = t - m.t;
        temp.f = f - m.f;
        temp.o = o - m.o;
        temp.w = w - m.w;

        return (temp);
    }

    void Advice_(double& difference, bool& debt) {   //function overriding

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;


        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this month." << endl;
            cout << "Please refer to your expenditures." << endl;
        }

        if (debt == false) {
            cout << "You have saved " << difference << " euros this month";

        }

    }

    void Expenditure() {   //function overriding

        if (h < 0) {
            cout << "You have spent " << h * -1 << " euros more on housing then you could be spending" << endl;
            cout << "If you are a student consider staying in a dorm," <<
                " otherweise you may find rooms with shared commodities for cheaper prices" << endl;
        }

        if (t < 0) {
            cout << "It appears that you have spent " << t * -1 << " euros more on transportation then you could have." << endl;
            cout << "Consider buying a montly ticket for public transportation and avoid ordering a taxi." << endl;
        }

        if (f < 0) {
            cout << "You spend " << f * -1 << " euros more on food than estimated." << endl;
            cout << "Firstly try your best to avoid eating outside. Additionally, avoid expensive grocery stores such as IKI" <<
                " and reduce the purchase of unhealthy or unnecessary products" << endl;
        }

        if (o < 0) {
            cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;
            cout << "This is not a negative showing if you are spending what you have saved in the past." << endl;
        }

        if (w < 0) {
            cout << "You earn less than the estinated minimum wage in Lithuania." << endl;
            cout << "If you are working 40 hours a week consider talking to your employer about the salary." << endl;
        }

        if ((h >= 0) && (t >= 0) && (f >= 0) && (o >= 0) && (w >= 0)) {
            cout << "Congratulations, your expenditure and wage meet the threshold" << endl;
        }


    }
 

};