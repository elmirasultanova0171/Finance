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

        int years = (car / difference) / 12;
        int years_h = (apartment / difference) / 12;
        int years2 = (car / difference2) / 12;
        int years_h2 = (apartment / difference2) / 12;

        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month."<<endl;
            cout << " This makes " << difference * 12 << " euros in one year." << endl;
            if (years > 0) {
                cout << " This means that if this money is saved carefully you may purchase a new car after "
                    << years + 1 << " years/year." << endl;
            }
            else {
                cout << "This means that if this money is saved carefully you may purchase a new car in less than a year." << endl;
            }
 
                if (years_h > 0) {
                    cout << " You may purchase an apartment after "
                        << years_h + 1 << " years/year." << endl;
                }
                else {
                    cout << "You may purchase an apartment in less than a year." << endl;
                }

        }

        else {
            debt = true;

           
            cout << "You have spent " << difference*-1 << " euros more than you have earned this month." << endl;
            cout << "Please refer to your expenditures." << endl;

        }
        

        if (difference2 > difference) {
            cout << " If you would spend as much as the estimated Upper Medium wage individual you can save " << difference2 << " per month.";
            cout << " This makes " << difference2 * 12 << " euros in one year." << endl;
            if ((years - years2 != 0)&& (years - years2 > 0)) {
                cout << " This means that with spending less you may purchase a new car " << years - years2 << " years/year earlier." << endl;
            }
            if ((years_h - years_h2 != 0)&&(years_h - years_h2 >0)) {
                cout << " You may purchase an apartment " << years_h - years_h2 << " years/year earlier." << endl;
            }
        }
                
            
        
        


    }

    void Expenditure() {   //function overriding

        if (debt == false) {

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

        else {
            if (h < 0) {
                cout << "You spent " << h * -1 << " euros more on housing than you could be spending" << endl;

            }

            if (t < 0) {
                cout << "It appears that you spend " << t * -1 << " euros more on transportation than you could have." << endl;

            }

            if (f < 0) {
                cout << "You spent " << f * -1 << " euros more on food than estimated." << endl;

            }

            if (o < 0) {
                cout << "You have spent " << o * -1 << " euros more on other purchases than estimated." << endl;

            }
        }

    }

};