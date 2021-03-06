                          
#include <iostream>
#include <vector>
#include "Finance.h"
#include "Minimum.h"
#include "Lower_Medium.h"
#include "Upper_Medium.h"
#include "High.h"

 
using namespace std;


int main()
{
    double h1, t1, f1, o1, w1;
    int count=0;

    vector<double> MIN_V {140, 29, 230, 130, 534};    //values in vectors 0 is housing, 1 is transport
    vector<double> LM_V{350, 29, 420, 200, 1000};     //2 is food, 3 is other and 4 is salary
    vector<double> UM_V{500, 300, 600, 300, 1700};     //All deafult values are listed here so they can be changed easily
    vector<double> H_V{2500, 950, 1000, 1700, 6150};

    double car=30000, ncar=45000, apartment=200000;

    Minimum MIN_standart( MIN_V[0], MIN_V[1], MIN_V[2], MIN_V[3], MIN_V[4]);
    Lower_Medium LM_standart(LM_V[0], LM_V[1], LM_V[2], LM_V[3], LM_V[4]);
    Upper_Medium UM_standart(UM_V[0], UM_V[1], UM_V[2], UM_V[3], UM_V[4]);
    High H_standart(H_V[0], H_V[1], H_V[2], H_V[3], H_V[4]);

   

    cout << "Hello, this program will give you financial advice based on your wage and how you spend."
        <<endl<<"Please remember that this program assumes that your wage is not less than "<<MIN_V[4]
        <<" euros (please write your wage after tax),"
        <<" you have a full time job and you only spend on yourself (you do not look after family)."
        <<endl<<"Additionally, when information on how you could spend is given remember, "
        <<"it is based on standart expenditure and should be applied after overspendings (if any) are reduced. "<<endl;

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
        cout << "Enter the monthly expenditure on food ";
        cin >> f1;
        if (f1 >= 0) {
            count++;
        }
        cout << "Enter the expenditure in other necessities ";
        cin >> o1;
        if (o1 >= 0) {
            count++;
        }
        cout << "Enter your monthly wage (after taxation) ";
        cin >> w1;
        if (w1 >= MIN_V[4]) {
            count++;
        }
        if (count < 5) {
            cout << "The values you have entered are invalid. Please review." << endl;
        }
    } 
    

    if (w1 >= MIN_V[4] && w1<=LM_V[4]) {  //For Minimum

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

        My_money1.getvalue(diff, apartment, car);

        comp1 = LM_standart - My_money1;
      
        My_money1.Advice_(My_money1.difference, My_money1.debt);
        comp1.Expenditure();

    }

    if (w1 > UM_V[4] && w1 <= H_V[4]) { //For Upper Middle

        Upper_Medium My_money2(h1, t1, f1, o1, w1);


        double diff2;
          diff2 = w1 - 230 - 420 - 29 - 350;

            My_money2.getvalue(diff2, apartment, car);
           
      
        Upper_Medium comp2;

        comp2 = UM_standart - My_money2;

        My_money2.Advice_(My_money2.difference, My_money2.debt);
        comp2.Expenditure();

    }
    if (w1 >= H_V[4]) { //For High

        High My_money3(h1, t1, f1, o1, w1);
         

        double diff3;
        diff3 = w1 - 300 - 600 - 305 - 500;

        My_money3.getvalue(diff3, apartment, ncar);
  
        High comp3;

        comp3 = H_standart - My_money3;

        My_money3.Advice_(My_money3.difference, My_money3.debt);
        comp3.Expenditure();

    }
    cout << endl;
    cout << "The standart values used for comparison." << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << " Minimal income" << endl;
    cout<< "Housing " << MIN_V[0] <<" euros"<< endl;
    cout << "Transportation " << MIN_V[1] << " euros" << endl;
    cout << "Food " << MIN_V[2] << " euros" << endl;
    cout << "Other " << MIN_V[3] << " euros" << endl;
    cout << "Wage range " << MIN_V[4] << "-" << LM_V[4]-1 << " euros" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Lower Medium income" << endl;
    cout << "Housing " << LM_V[0] << " euros" << endl;
    cout << "Transportation " << LM_V[1] << " euros" << endl;
    cout << "Food " << LM_V[2] << " euros" << endl;
    cout << "Other " << LM_V[3] << " euros" << endl;
    cout << "Wage range " << LM_V[4] << "-" << UM_V[4]-1 << " euros" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Upper Medium income" << endl;
    cout << "Housing " << UM_V[0] << " euros" << endl;
    cout << "Transportation " << UM_V[1] << " euros" << endl;
    cout << "Food " << UM_V[2] << " euros" << endl;
    cout << "Other " << UM_V[3] << " euros" << endl;
    cout << "Wage range " << UM_V[4] << "-" << H_V[4]-1 << " euros" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "High income" << endl;
    cout << "Housing " << H_V[0] << " euros" << endl;
    cout << "Transportation " << H_V[1] << " euros" << endl;
    cout << "Food " << H_V[2] << " euros" << endl;
    cout << "Other " << H_V[3] << " euros" << endl;
    cout << "Wage range " << H_V[4] << "- infinity" << " euros" << endl;
    cout << "-----------------------------------------------------" << endl;
 
}

 