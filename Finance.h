#pragma once

#include <iostream>

using namespace std;

class Finance {           


public:
    
    double difference, difference2;
    bool debt;

    virtual void Advice_(double& difference, bool& debt) = 0;

    virtual void Expenditure() = 0;

    void getvalue(double x) {
        difference2 = x;
    }

   

};