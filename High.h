#pragma once
#include <iostream>
#include "Finance.h"
using namespace std;

class High : public Finance {

private:

    double h, t, f, o, w;

public:



    High() {

    }

    High(double housing, double transport, double food, double other, double wage) {

        h = housing;
        t = transport;
        f = food;
        o = other;
        w = wage;


    }


    High operator-(High m)
    {
        High temp;

        temp.h = h - m.h;                 //comparisons
        temp.t = t - m.t;
        temp.f = f - m.f;
        temp.o = o - m.o;
        temp.w = w - m.w;

        return (temp);
    }

    void Advice_(double& difference, bool& debt) {

        //change

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";


        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;

        }
        int years = (45000 / difference2) / 12;
        int years_h = (16666 / difference2);    //years to buy a house

        cout << " If you would spend as much as the estimated Upper Medium wage individual you can save " << difference2 << " per month.";
        cout << " This makes " << difference2 * 12 << " euros in one year." << endl;
        if (years > 0) {
            cout << " This means that if this money is saved carefully you may purchase a new car after "
                << years + 1 << " years." << endl;
        }
        else {
            cout << "This means that if this money is saved carefully you may purchase a new car in less than a year" << endl;
        }

        if (difference2 > 3995) {
            if (years > 0) {
                cout << " You may purchase an apartment after "
                    << years_h + 1 << " years." << endl;
            }
            else {
                cout << "You may purchase an apartment in less than a year" << endl;
            }
        }


    }

    void Expenditure() {   //function overriding

        if (debt == false) {

            if (difference > 1550) {
                cout << "Congratulations, you did not overspend." << endl;

                if (h > 0) {
                    cout << "You spent less than the standart expenditure on housing, you could be spending " << h
                        << " euros more." << endl;
                }

                if (t > 0) {
                    cout << "You spent less than the standart expenditure on transport, you could be spending " << t
                        << " euros more." << endl;
                }

                if (f > 0) {
                    cout << "You spent less than the standart expenditure on food, you could be spending " << f
                        << " euros more." << endl;
                }

                if (o > 0) {
                    cout << "You spent less than the standart expenditure on other necessities, you could be spending " << o
                        << " euros more." << endl;
                }

            }

            if ((h > 0) && (t > 0) && (f > 0) && (o > 0) && (difference < 1550)) {
                cout << "Congratulations, you did not overspend, however you could save more." << endl;

                if (h < 0) {
                    cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

                }

                if (t < 0) {
                    cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

                }

                if (f < 0) {
                    cout << "You spent " << f * -1 << " euros more on food than estimated." << endl;

                }

                if (o < 0) {
                    cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

                }

            }
        }
        else {
            if (h < 0) {
                cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

            }

            if (t < 0) {
                cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

            }

            if (f < 0) {
                cout << "You spent " << f * -1 << " euros more on food than estimated." << endl;

            }

            if (o < 0) {
                cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

            }
        }

    }

};