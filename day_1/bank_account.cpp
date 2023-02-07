#include<iostream>
using namespace std;

class bank_account{

    private:
    int atm_pin,account_number,balance;

    public:
    void display_balance();
    void update_balance();
    void change_pin();
    bank_account (int i_atm_pin,int i_account_number,int i_balance):atm_pin(i_atm_pin),account_number(i_account_number),balance(i_balance){};

};



void bank_account::change_pin(){
    int check;
    cout<<"Enter Current Pin:";
    cin>>check;
    if(atm_pin==check){
        cout<<"Enter new pin";
        cin>>atm_pin;
        cout<<"pin has been changed"<<endl;
    }
     else{
        cout<<"Invalid Pin";
    }
}

void bank_account::display_balance(){
    int check_pin;
    cout<<"Enter Pin:";
    cin>>check_pin;
    if(check_pin==atm_pin){
        cout<<"Available Balance Currently:"<<balance<<endl;
    } else{
        cout<<"Invalid Pin";
    }
}

void bank_account::update_balance(){
    int check_pin,i,change;
    cout<<"Enter Pin:";
    cin>>check_pin;
    
    if(check_pin==atm_pin){
        cout<<"Available Balance Currently:"<<balance<<endl;
        cout<<"Press 1 for credit and 2 for debit:";
        cin>>i;
        if(i==1){
            cout<<"Enter amount to add:";
            cin>>change;
            balance = balance+change;
            cout<<"New balance:"<<balance;
        } 
        if(i==2){
            cout<<"Enter amount to withdraw:";
            cin>>change;
            if(balance>change)
            {
                balance = balance-change;
                cout<<"New balance:"<<balance;
            }
            else{
                cout<<"Not enough money";
            }
        }  
        if(i!=1&&i!=2){
            cout<<"Not a valid option";
        }
    }
     else{
        cout<<"Invalid Pin";
    }
}


int main()
{
    class bank_account b1(9103,123456,10000); // pin = 9103;
    b1.display_balance();
    b1.update_balance();
    b1.display_balance();
    b1.change_pin();
    b1.display_balance();
}