#pragma once

#include <iostream>

using namespace std;

class Finance {


public:

    double difference;
    bool debt;
    double difference2, apartment, car, new_car;

    virtual void Advice_(double& difference, bool& debt) = 0;

    virtual void Expenditure() = 0;

    void getvalue(double x) {
        difference2 = x;
    }    


};