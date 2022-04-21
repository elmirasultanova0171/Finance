                         //later they will be divided to header files
#include <iostream>
using namespace std;

class Finance {          //parent


public:
    
    double difference;

    virtual void debt_(double& difference) {
       
         
    }

    virtual void Advice() {  
                             //Function overriding 
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

    void debt_(double& difference) {

        bool debt;

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;
        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You are " << difference << " euros in debt." << endl;
        }

    }

    void Advice() {

         


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

 