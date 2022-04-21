                         //later they will be divided to header files
#include <iostream>
using namespace std;

class Finance {          //parent


public:
    
    double difference;

    virtual void debt_(double& difference) {
       
         
    }

    virtual void Advice() {  
                              
    }


};

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

    void debt_(double& difference) {   //function overriding

        bool debt;

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;
        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << "ˆ more than you have earned this year." << endl; //more profound
            cout << "Please refer to the advice below." << endl;
        }

    }

    void Advice() {   //function overriding

        if (h < 0) {
            cout << "You spend " << h * -1 << "ˆ more on housing then you could be spending" << endl;
            cout << "If you are a student consider staying in a dorm," <<
                " otherweise you may find rooms with shared commodities for cheaper prices" << endl;
        }

        if (t < 0) {
            cout << "It appears that you spend " << t * -1 << "ˆ more on transportation then you could have." << endl;
            cout << "Consider buying a montly ticket for public transportation and avoid ordering a taxi." << endl;
        }

        if (f < 0) {
            cout << "You spend " << f * -1 << "ˆ more on food than estimated." << endl;
            cout << "Firstly try your best to avoid eating outside. Additionally, avoid expensive grocery stores such as IKI" <<
                " and reduce the purchase of unhealthy or unnecessary products" << endl;
        }

        if (o < 0) {
            cout << "You have spent " << o * -1 << "ˆ more on other purchases then estimated." << endl;
            cout << "This is not a negative showing if you are spending what you have saved in the past." << endl;
        }

        if (w < 0) {
            cout << "You earn less than the estinated minimum wage in Lithuania." << endl;
            cout << "If you are working 40 hours a week consider talking to your employer about the salary." << endl;
        }


    }
    
    /*void show() {
        cout << h<<"h "<<t<<"t "<<f<<"f "<<o<<"o "<<w<<"w ";
    }*/


};

int main()
{
    double h1, t1, f1, o1, w1;
 
    //standarts

    Minimum MIN_standart(140, 29, 250, 130, 650);

    //Intro

    cout << "instert text";

    cin >> h1 >> t1 >> f1 >> o1 >> w1;   //these inputs set limits

    //Execute

    if (w1 <= 775) {  //For Minimum

        Minimum MY_money(h1, t1, f1, o1, w1);
        
        Minimum r;
            
        r = MIN_standart - MY_money;
        
        r.Advice();
    }




}

 