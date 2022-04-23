#pragma once

#include <iostream>

using namespace std;

class Finance {           


public:
    
    double difference;  
    bool debt;

    virtual void Advice_(double& difference, bool& debt) = 0;

    virtual void Expenditure() = 0;

//protected:
    double difference2;
    void getvalue(double x) {
        difference2 = x;
    }

   

};