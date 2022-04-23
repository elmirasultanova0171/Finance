                         //later they will be divided to header files
#include <iostream>
#include <vector>

using namespace std;

class Finance {           


public:
    
    double difference;
    bool debt;

    virtual void Advice_(double& difference, bool& debt) = 0;

    virtual void Expenditure() = 0;

   

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

    void Advice_(double& difference, bool &debt) {   //function overriding
         
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
             
        }

    }

    void Expenditure() {   //function overriding

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

    void Advice_(double& difference, bool &debt) { 

       // Lower_Medium min_money(140, 29, 250, 130, w);

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";

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

    void Expenditure() {   //function overriding

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

    void Advice_(double& difference, bool& debt) {

          //change

        difference = w - (o + f + t + h);
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";
             

        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;

        }
        int years = (30000 / difference2) / 12;
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

    void Expenditure() {   //function overriding

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
 
class High {

private:

    double h, t, f, o, w;

public:

    double difference, difference2;
    bool debt;

    void getvalue(double x) {
        difference2 = x;
    }

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
        if (difference > 0) {
            debt = false;

            cout << "You have saved " << difference << " euros this month";
             

        }
        else {
            debt = true;

            difference = difference * -1;

            cout << "You spent " << difference << " euros more than you have earned this year." << endl;
            cout << "Please refer to the advice below." << endl;

        }
        int years = (45000 / difference2) / 12;
        int years_h = (16666 / difference2);    //years to buy a house

        cout << " If you would spend as much as the estimated Upper Medium wage individual you can save " << difference2 << " per month.";
        cout << " This makes " << difference2 * 12 << " euros in one year." << endl;
        if (years > 0) {
            cout << " This means that if this money is saved carefully you may purchase a new car after "
                << years + 1 << " years." << endl;
        }
        else {
            cout << "This means that if this money is saved carefully you may purchase a new car in less than a year" << endl;
        }

        if (difference2 > 3995) {
            if (years > 0) {
                cout << " You may purchase an apartment after "
                    << years_h + 1 << " years." << endl;
            }
            else {
                cout << "You may purchase an apartment in less than a year" << endl;
            }
        }


    }

    void Expenditure() {   //function overriding

        if (debt == false) {

            if (difference > 1550) {
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

            if ((h > 0) && (t > 0) && (f > 0) && (o > 0) && (difference < 1550)) {
                cout << "Congratulations, you did not overspend, however you could save more." << endl;

                if (h < 0) {
                    cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

                }

                if (t < 0) {
                    cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

                }

                if (f < 0) {
                    cout << "You spent " << f * -1 << " euros more on food than estimated." << endl;

                }

                if (o < 0) {
                    cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

                }

            }
        }
        else {
            if (h < 0) {
                cout << "You spent " << h * -1 << " euros more on housing then you could be spending" << endl;

            }

            if (t < 0) {
                cout << "It appears that you spend " << t * -1 << " euros more on transportation then you could have." << endl;

            }

            if (f < 0) {
                cout << "You spent " << f * -1 << " euros more on food than estimated." << endl;

            }

            if (o < 0) {
                cout << "You have spent " << o * -1 << " euros more on other purchases then estimated." << endl;

            }
        }

    }

};


int main()
{
    double h1, t1, f1, o1, w1;
    int count;

    vector<double> MIN_V {140, 29, 230, 130, 534};
    vector<double> LM_V{350, 29, 420, 200, 1000};
    vector<double> UM_V{500, 300, 600, 300, 1700};
    vector<double> H_V{2500, 950, 1000, 1700, 5700};

    Minimum MIN_standart( MIN_V[0], MIN_V[1], MIN_V[2], MIN_V[3], MIN_V[4]);
    Lower_Medium LM_standart(LM_V[0], LM_V[1], LM_V[2], LM_V[3], LM_V[4]);
    Upper_Medium UM_standart(UM_V[0], UM_V[1], UM_V[2], UM_V[3], UM_V[4]);
    High H_standart(H_V[0], H_V[1], H_V[2], H_V[3], H_V[4]);


    cout << "Hello, this program will give you financial advice based on your wage and how you spend if you live in Lithuania."
        <<"Please remember that this program assumes that your wage is not less than 534 euros (approximately minimum wage minus tax), you have a full time job and"
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
        if (w1 >= MIN_V[4]) {
            count++;
        }
        if (count < 5) {
            cout << "The values you have entered are invalid. Please review and enter valid values." << endl;
        }
    } 
    

    if (w1 <= LM_V[4]) {  //For Minimum

        Minimum MY_money(h1, t1, f1, o1, w1);
        
        Minimum comp;
            
        comp = MIN_standart - MY_money;

        MY_money.Advice_(MY_money.difference, MY_money.debt);
        
        comp.Expenditure();
    }

    if (w1 > LM_V[4] && w1 <= UM_V[4]) { //For Lower Middle

        Lower_Medium My_money1(h1, t1, f1, o1, w1);
        
        Lower_Medium comp1;

        double diff;

        diff = w1 - 130 - 250 - 29 - 140;

        My_money1.getvalue(diff);

        comp1 = LM_standart - My_money1;
      
        My_money1.Advice_(My_money1.difference, My_money1.debt);
        comp1.Expenditure();

    }

    if (w1 > UM_V[4] && w1 <= H_V[4]) { //For Upper Middle

        Upper_Medium My_money2(h1, t1, f1, o1, w1);


        double diff2;
          diff2 = w1 - 230 - 420 - 29 - 350;

            My_money2.getvalue(diff2);

        Upper_Medium comp2;

        comp2 = UM_standart - My_money2;

        My_money2.Advice_(My_money2.difference, My_money2.debt);
        comp2.Expenditure();

    }
    if (w1 >= H_V[4]) { //For High

        High My_money3(h1, t1, f1, o1, w1);
         

        double diff3;
        diff3 = w1 - 300 - 600 - 305 - 500;

        My_money3.getvalue(diff3);

        High comp3;

        comp3 = H_standart - My_money3;

        My_money3.Advice_(My_money3.difference, My_money3.debt);
        comp3.Expenditure();

    }




}

 