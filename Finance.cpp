                         //later they will be divided to header files
#include <iostream>
#include <vector>

using namespace std;

class Finance {          //parent


public:
    
    double difference;
    bool debt;

    virtual void debt_(double& difference, bool& debt) = 0;

    virtual void Advice() = 0;

 ///protected:

    
   

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

    void debt_(double& difference, bool &debt) {   //function overriding
         
        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            
        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl; 
            cout << "Please refer to the advice below." << endl;
        }

        if (debt == false) {
            cout << "You have saved " << difference << " euros this month";
            if (difference >= 100) {
                cout << "It is more than the estimated amount of savings for your wage range";
            }
            if (difference < 100) {
                cout << "It is " << 100 - difference << " euros less than the estimated savings, you may"
                    << " refer to the information below to improve these results.";
            }
        }

    }

    void Advice() {   //function overriding

        if (h < 0) {
            cout << "You spend " << h * -1 << " euros more on housing then you could be spending" << endl;
            cout << "If you are a student consider staying in a dorm," <<
                " otherweise you may find rooms with shared commodities for cheaper prices" << endl;
        }

        if (t < 0) {
            cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;
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
            cout << "Congratulations, your expenditure and wage meet the threshold"<<endl;
        }


    }
    
    /*void show() {
        cout << h<<"h "<<t<<"t "<<f<<"f "<<o<<"o "<<w<<"w ";
    }*/


};

class Lower_Medium {
private:

    double h, t, f, o, w;

public:

    double difference;
    bool debt;

    Lower_Medium() {

    }

    Lower_Medium(double housing, double transport, double food, double other, double wage) {

        h = housing;
        t = transport;
        f = food;
        o = other;
        w = wage;

    }

    Lower_Medium operator-(Lower_Medium m)
    {
        Lower_Medium temp;

        temp.h = h - m.h;                 //comparisons
        temp.t = t - m.t;
        temp.f = f - m.f;
        temp.o = o - m.o;
        temp.w = w - m.w;

        return (temp);
    }

    void debt_(double& difference, bool &debt) {    

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;
            cout << "You have saved " << difference << " euros this month.";
        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;
        }

    }

    void Advice() {   //function overriding

        if (h < 0) {
            cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;
            
        }

        if (t < 0) {
            cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;
             
        }

        if (f < 0) {
            cout << "You spend " << f * -1 << " euros more on food than estimated." << endl;
            
        }

        if (o < 0) {
            cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;
             
        }

        if (w < 0) {
            cout << "You earn less than the estinated minimum wage in Lithuania." << endl;
             
        }



    }
};

int main()
{
    double h1, t1, f1, o1, w1;
   // vector<int>* v = new vector<int>;
 
    //standarts

    Minimum MIN_standart(140, 29, 250, 130, 650);
    Lower_Medium LM_standart(350, 29, 420, 230, 1200);

    //Intro

    cout << "Hello, this program will give you financial advice based on your wage and how you spend if you live in Lithuania."
        <<"Please remember that this program assumes you have a full time job and you only spend on yourself (you do not look after family)"
        <<"Additionally, remember to enter all values in Euros."<<endl;

    cout << "Enter your monthly housing costs (or rent) ";
    cin >> h1;
    cout << "Enter the monthly transportation costs ";
    cin >> t1;
    cout << "Enter the montly expenditure on food ";
    cin >> f1;
    cout << "Enter the expenditure in other nessesities ";
    cin >> o1;
    cout << "Enter your mothly wage ";
    cin >> w1;
    

    // set some limits for the inputs

    if (w1 <= 775) {  //For Minimum

        Minimum MY_money(h1, t1, f1, o1, w1);
        
        Minimum comp;
            
        comp = MIN_standart - MY_money;

        MY_money.debt_(MY_money.difference, MY_money.debt);
        
        comp.Advice();
    }

    if (w1 > 775 && w1 <= 1700) { //For Lower Middle

        Lower_Medium My_money1(h1, t1, f1, o1, w1);

        Lower_Medium comp1;

        comp1 = LM_standart - My_money1;
        My_money1.debt_(My_money1.difference, My_money1.debt);
        comp1.Advice();

        cout << "There is possibility for you to save more." << endl;
        cout << "Enter 1 if you would like your results to be compared to minimum standart, otherweise press any other number" << endl;
        int n;
        cin >> n;
        if (n == 1) {

        }
    }




}

 