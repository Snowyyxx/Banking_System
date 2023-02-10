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
6 - Valid Pin
*/


class SavingBankAccount{ //Creating a class for bank-accounts;
    int atm_pin,account_number,balance;
    public: // various functions needed for a bare bones atm machine;
    friend class Customer;
    int display_balance();
    int debit();
    int credit();
    int change_pin(); 
    int check_pin(); // new function
    SavingBankAccount (int i_atm_pin,int i_account_number,int i_balance):atm_pin(i_atm_pin),account_number(i_account_number),balance(i_balance){};
    SavingBankAccount(){};
};



int SavingBankAccount::check_pin(){ // removes the need to write if condition again and again!
    int check_pin;
    cout<<"Enter Pin:";
    cin>>check_pin;
    if(atm_pin==check_pin){
        cout<<"Pin entered is correct"<<endl;
        return 6;
    }else{
        cout<<"Entered pin is incorrent"<<endl;
        return 0;
    }
}

int SavingBankAccount::change_pin(){ //Creating a function to change the default pin entered;
    
    if(check_pin()==6){ // checks if the pin entered is correct or not
        cout<<"Enter new pin";
        cin>>atm_pin;
        cout<<"pin has been changed"<<endl;
        return 2; // Pin changed succesfully;
    }
}

int SavingBankAccount::display_balance(){ // displays the current balance in the account;
    
    if(check_pin()==6){ // checks if correct pin is entered;
        cout<<"Available Balance Currently:"<<balance<<endl;
        return 5; // Balance was displayed successfuly;
    } 
}

int SavingBankAccount::credit(){ // credits a certain ammount of money to the account;
    int change;
    if(check_pin()==6){ // checks if the correct pin is enterd by the user;
        cout<<"Available Balance Currently:"<<balance<<endl;
        cout<<"Enter amount to withdraw:";
        cin>>change;
        balance = balance+change; // updates the balances as per the change entered;
        cout<<"Credited Amount:"<<change<<endl;
        cout<<"New Balance:"<<balance<<endl;
        return 4; // Credit was successful;
    } 

}

int SavingBankAccount::debit(){ // debits a certain ammount of money to the account;
    int change;
    if(check_pin()==6){ // checks if the pin entered by the user is valid;
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
}
