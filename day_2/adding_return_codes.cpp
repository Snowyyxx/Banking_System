#include<iostream>
using namespace std;

/*
Return Codes:
0 - Invalid Pin
1 - Not Enough money
2 - Pin was changed successfuly
3 - Successful Debit
4 - Successful Credit
5 - Balance was displayed successfuly
*/

class bank_account{ //Creating a class for bank-accounts;

    private:
    int atm_pin,account_number,balance;

    public: // various functions needed for a bare bones atm machine;
    int display_balance();
    int debit();
    int credit();
    int change_pin();
    bank_account (int i_atm_pin,int i_account_number,int i_balance):atm_pin(i_atm_pin),account_number(i_account_number),balance(i_balance){};

};



int bank_account::change_pin(){ //Creating a function to change the default pin entered;
    int check;
    cout<<"Enter Current Pin:";
    cin>>check;
    if(atm_pin==check){ // checks if the pin entered is correct or not
        cout<<"Enter new pin";
        cin>>atm_pin;
        cout<<"pin has been changed"<<endl;
        return 2; // Valid Pin;
    }
     else{
        cout<<"Invalid Pin"<<endl;
        return 0; // Pin entered was invalid
    }
}

int bank_account::display_balance(){ // displays the current balance in the account;
    int check_pin;
    cout<<"Enter Pin:";
    cin>>check_pin;
    if(check_pin==atm_pin){ // checks if correct pin is entered;
        cout<<"Available Balance Currently:"<<balance<<endl;
        return 5; // Balance was displayed successfuly;
    } else {
        cout<<"Invalid Pin"<<endl;
        return 0; // Pin entered was invalid
    }
}

int bank_account::credit(){ // credits a certain ammount of money to the account;
    int check_pin,change;
    cout<<"Enter Pin:";
    cin>>check_pin;
    if(check_pin==atm_pin){ // checks if the correct pin is enterd by the user;
        cout<<"Available Balance Currently:"<<balance<<endl;
        cout<<"Enter amount to withdraw:";
        cin>>change;
        balance = balance+change; // updates the balances as per the change entered;
        cout<<"Credited Amount:"<<change<<endl;
        cout<<"New Balance:"<<balance<<endl;
        return 4; // Credit was successful;
        } 
    else{
        cout<<"Invalid Pin"<<endl;
        return 0;// Pin entered was invalid
    }
}

int bank_account::debit(){ // debits a certain ammount of money to the account;
    int check_pin,change;
    cout<<"Enter Pin:";
    cin>>check_pin;
    if(check_pin==atm_pin){ // checks if the pin entered by the user is valid;
        cout<<"Available Balance Currently:"<<balance<<endl;
        cout<<"Enter amount to withdraw:";
        cin>>change; 
        if(balance>change) // checks if the amount to be withdrawed is lesser than the amount in the bank account
        {
            balance = balance-change; // debits the balance as per the change entered;
            cout<<"New balance:"<<balance<<endl;
            return 3; // Debit was Successful 
        }
        else{
            cout<<"Not enough money"<<endl;
            return 1; // Not Enough Money
        }
    }  
     else{
        cout<<"Invalid Pin"<<endl;
        return 0; // Pin entered was invalid
    }
}

int main()
{
    class bank_account b1(9103,123456,10000); // pin = 9103;
    int check;
    check = b1.display_balance();
    cout<<"return code:"<<check;

}