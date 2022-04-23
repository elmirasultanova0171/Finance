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

    double h, t, f, o, w, difference2;

public:

    double difference;
    bool debt;

    void getvalue(double x) {
        difference2 = x;
    }

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

       // Lower_Medium min_money(140, 29, 250, 130, w);

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";
            if (difference >= 171) {                                                          //n s
                cout << "It is more than the estimated amount of savings for your wage range";
            }
            if (difference < 171) {                                                           //n s
                cout << "It is " << 171 - difference << " euros less than the estimated savings" << endl;

            }

        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;
            
        }

        cout << " If you would spend as much as the estimated Minimum wage individual you can save " << difference2 << " per month.";
        cout << " This makes " << difference2 * 12 << " euros in one year."<<endl;

 
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

        if ((h > 0) && (t > 0) && (f > 0) && (o > 0)) {
            cout << "Congratulations, you did not overspend";
         }




    }
};

class Upper_Medium {
private:

    double h, t, f, o, w;

public:

    double difference, difference2;
    bool debt;

    void getvalue(double x) {
        difference2 = x;
    }

    Upper_Medium() {

    }

    Upper_Medium(double housing, double transport, double food, double other, double wage) {

        h = housing;
        t = transport;
        f = food;
        o = other;
        w = wage;


    }


    Upper_Medium operator-(Upper_Medium m)
    {
        Upper_Medium temp;

        temp.h = h - m.h;                 //comparisons
        temp.t = t - m.t;
        temp.f = f - m.f;
        temp.o = o - m.o;
        temp.w = w - m.w;

        return (temp);
    }

    void debt_(double& difference, bool& debt) {

          //change

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";
            if (difference >= 295) {                                                          //n s
                cout << "It is more than the estimated amount of savings for your wage range";
            }
            if (difference < 295) {                                                           //n s
                cout << " It is " << 295 - difference << " euros less than the estimated savings" << endl;

            }

        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;

        }
        int years = (36000 / difference2) / 12;
        cout << " If you would spend as much as the estimated Lower Medium wage individual you can save " << difference2 << " per month.";
        cout << " This makes " << difference2 * 12 << " euros in one year."<<endl;
        if (years > 0) {
            cout << " This means that if this money is saved carefully you may purchase a decent car after "
                << years+1 << " years." << endl;
        }
        else {
            cout << "This means that if this money is saved carefully you may purchase a decent car in less than a year"<< endl;
        }


    }

    void Advice() {   //function overriding

        if (h < 0) {
            cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

        }
        else {
            cout <<"You spent less than the standart expenditure on housing, you could be spending "<< h 
                << " euros more." << endl;
        }

        if (t < 0) {
            cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

        }
        else {
            cout << "You spent less than the standart expenditure on transport, you could be spending " << t
                << " euros more." << endl;
        }

        if (f < 0) {
            cout << "You spend " << f * -1 << " euros more on food than estimated." << endl;

        }
        else {
            cout << "You spent less than the standart expenditure on food, you could be spending " << f
                << " euros more." << endl;
        }

        if (o < 0) {
            cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

        }
        else {
            cout << "You spent less than the standart expenditure on other necessities, you could be spending " << o
                << " euros more." << endl;
        }

        if ((h > 0) && (t > 0) && (f > 0) && (o > 0)) {
            cout << "Congratulations, you did not overspend" << endl;
        }




    }
};

int main()
{
    double h1, t1, f1, o1, w1;
    int count=0;
   // vector<int>* v = new vector<int>;
 
    //standarts

    Minimum MIN_standart(140, 29, 250, 130, 650);
    Lower_Medium LM_standart(350, 29, 420, 200, 1200);
    Upper_Medium UM_standart(500, 350, 600, 300, 2000);

    //Intro

    cout << "Hello, this program will give you financial advice based on your wage and how you spend if you live in Lithuania."
        <<"Please remember that this program assumes that your wage is not less than 550 euros, you have a full time job and"
        <<"you only spend on yourself(you do not look after family)"
        <<"Additionally, remember to enter all values in Euros."<<endl;

    for (int i=0; count < 5; i++ ) {
        count = 0;
        cout << "Enter your monthly housing costs (or rent) ";
        cin >> h1;
        if (h1 >= 0) {
            count++;
        }
        cout << "Enter the monthly transportation costs ";
        cin >> t1;
        if (t1 >= 0) {
            count++;
        }
        cout << "Enter the montly expenditure on food ";
        cin >> f1;
        if (f1 >= 0) {
            count++;
            cout << 1;
        }
        cout << "Enter the expenditure in other nessesities ";
        cin >> o1;
        if (o1 >= 0) {
            count++;
        }
        cout << "Enter your mothly wage ";
        cin >> w1;
        if (w1 >= 550) {
            count++;
        }
        if (count < 5) {
            cout << "The values you have entered are invalid. Please review and enter valid values." << endl;
        }
    } 
    

    if (w1 <= 1000) {  //For Minimum

        Minimum MY_money(h1, t1, f1, o1, w1);
        
        Minimum comp;
            
        comp = MIN_standart - MY_money;

        MY_money.debt_(MY_money.difference, MY_money.debt);
        
        comp.Advice();
    }

    if (w1 > 1000 && w1 <= 2000) { //For Lower Middle

        Lower_Medium My_money1(h1, t1, f1, o1, w1);
        
        Lower_Medium comp1;

        double diff = w1 - (130 + 250 + 29 + 140);

        My_money1.getvalue(diff);

        comp1 = LM_standart - My_money1;
      
        My_money1.debt_(My_money1.difference, My_money1.debt);
        comp1.Advice();

    }

    if (w1 > 2000 && w1 <= 7000) { //For Upper Middle

        Upper_Medium My_money2(h1, t1, f1, o1, w1);


        //Upper_Medium mid_money(350, 29, 420, 230, w1);
        double diff2 = w1 - (230 + 420 + 29 + 350);
            My_money2.getvalue(diff2);

        Upper_Medium comp2;

        comp2 = UM_standart - My_money2;

        My_money2.debt_(My_money2.difference, My_money2.debt);
        comp2.Advice();

    }




}

 