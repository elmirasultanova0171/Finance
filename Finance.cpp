                         //later they will be divided to header files
#include <iostream>
using namespace std;

class Finance {          //parent


public:
    
    double difference;

    virtual bool debt_(double& difference) {
       
        return false;
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

        if (h - m.h < 0) {
            temp.h = h - m.h;
        }
        if (t - m.t < 0) {
            temp.t = t - m.t;
        }
        if (f - m.f < 0) {
            temp.f = f - m.f;
        }

        return (temp);
    }

    bool debt_(double& difference) {

        difference = w - (o + f + t + h);
        if (difference > 0) {
            return false;
        }
        else {
            return true;
        }

    }

    void Advice() {

        bool debt = debt_(difference);

        if (debt == true) {
            difference = difference * -1;

            cout << "You are " << difference << " euros in debt." << endl;
        }



    }
    
    void show() {
        cout << h<<"h "<<t<<"t "<<f<<"f "<<o<<"o "<<w<<"w ";
    }


};

int main()
{
    double h1, t1, f1, o1, w1;
    bool debt1;

    cout << "instert text";

    cin >> h1 >> t1 >> f1 >> o1 >> w1;

    if (w1 <= 775) {

        Minimum money(h1, t1, f1, o1, w1);
        Minimum st(1, 2, 1, 4, 1);
        Minimum r;
            //money.Advice();
        r = st < money;
        r.show();
    }


}

 