#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

struct UserRecord {
    string name;
    int ID;
    double weight;
    double height;
    double BMI;
    string result;
};
     
void Menu();
void BMI();
double CalcBMI(double weight, double height);
string BMIresult(double BMI);
void searchUsr();

const int MaxUsr=100;
UserRecord USR[MaxUsr];
int Usrcount = 0 ;

int main (){

   
    int numfMn;
    cout << "\n===========================================" << endl;
    cout << "            BMI Calculater           "<<endl;
    cout << endl;
 do {
          Menu();
          cin >> numfMn;

        if (numfMn == 1) {
          BMI();
          cout<< "================="<<endl;
        }
        else if (numfMn == 2) {
          searchUsr();
        }
        else if (numfMn == 3) {
            cout << " Thank you for using the program !" << endl;
            break;
        }
        else {
            cout << " INVALID OPTION ! " << endl;
        }   
    }while (true);


}



void Menu()
{
    cout << " Main Menu : " << endl;
    cout << " 1- Calculate BMI " << endl;
    cout << " 2- Search for user" << endl;
    cout << " 3- Exit " << endl;
    cout << " Choose an option : ";
}

void BMI(){

    string choise ="";
    cout<<endl;
    cout << "-Enter your name --> ";
    cin.ignore();
    getline(cin,USR[Usrcount].name); 
    cout << "-Enter your ID --> ";
    cin >> USR[Usrcount].ID;
    cout << "-Enter your weight (kg) --> ";
    cin >> USR[Usrcount].weight;
    cout << "-Enter your height (cm) --> ";
    cin >>USR[Usrcount].height;
    
    USR[Usrcount].BMI = CalcBMI(USR[Usrcount].weight , USR[Usrcount].height ) ;
    USR[Usrcount].result = BMIresult( USR[Usrcount].BMI );

    
    cout << " BMI: " << USR[Usrcount].BMI << endl;
    cout << " Result --> " << USR[Usrcount].result << endl;
    Usrcount++;
    
}

double CalcBMI(double weight, double height)
{
    return weight / pow(height/100, 2)  ;
}

string BMIresult(double BMI){
     
  if (BMI < 16)        return "Severely underweight";
  else if (BMI < 18.5) return "Underweight";
  else if (BMI < 25)   return "Normal weight (Healthy)";
  else if (BMI < 30)   return "Overweight";
  else if (BMI < 35)   return "Obesity Class I";
  else if (BMI < 40)   return "Obesity Class II";
  else                 return "Obesity Class III";

}

void searchUsr(){
    cout<<endl;
    int ID;
    bool found = false;

    if ( Usrcount == 0){
        cout << " No one has used it before. "<<endl;
    }
    
    cout << " Please yor ID : ";
    cin >> ID;
    for ( int i = 0 ; i <= Usrcount ; i++ ){
        if ( ID == USR[i].ID ){
            found = true ;
            cout << " Hello " << USR[i].name <<", Welcome back "<< endl;
            cout << " Your previous BMI Calc "<<endl;
            cout << " Weight: " << USR[i].weight << " (kg)" << endl;
            cout << " Height: " << USR[i].height << " (m)" << endl;
            cout << " BMI: " << USR[i].BMI << endl;
            cout << " Result: " << USR[i].result << endl;
            cout<<endl;
            cout<<"==========================================="<<endl;
            break;
        }
    }
    if (!found){
        cout << " USER NOT FOUND " <<endl;
    }
}