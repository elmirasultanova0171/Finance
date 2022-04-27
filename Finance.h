#pragma once

#include <iostream>

using namespace std;

class IFinance {

public:

    virtual void Expenditure() = 0;

    virtual void getvalue(double x, double a, double c) = 0;
};
 
class Finance :public IFinance {

public:

    double difference;
    bool debt;
    double difference2, apartment, car;

    void Advice_(double& difference, bool& debt) {
        cout << "Advice on savings" << endl;
     }

     void Expenditure() {
         cout << "Expenditure "<<endl;
     }

    void getvalue(double x, double a, double c) {
       difference2=x;
       apartment = a;
       car = c;
    }    


};