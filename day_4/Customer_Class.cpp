#include<iostream>
using namespace std;

#include"SBA_Class.h" // Created header file for SavingBankAccount class; 
class Customer{
    public:
    int NumberOfAccounts; // Customer detail etc.... 
    string CustomerName;
    int CustomerAge; 
    class SavingBankAccount customer_accounts[]; // This means that if a structure contains only a flexible array member, it will have no size and cannot be used to allocate memory or create instances of the structure. To work around this limitation, you can add one or more other members to the structure, even if they are not needed for your specific use case.
    Customer(int i_NumberOfAccounts,string i_name,int i_age):NumberOfAccounts(i_NumberOfAccounts),CustomerAge(i_age),CustomerName(i_name){
        for(int i =0;i<NumberOfAccounts;i++){ // Constructor -> num_accounts,name,age ;
            cout<<"Enter Detail for "<<i+1<<"th"<<" account:"<<endl;
            cout<<"ATM Pin for "<<i+1<<"th"<<" account: "; // inputting the valuee of customer array
            cin>>customer_accounts[i].atm_pin;
            cout<<endl<<"Account Number for "<<i+1<<"th"<<" account";
            cin>>customer_accounts[i].account_number;
            cout<<endl<<"Balance for "<<i+1<<"th"<<" account";
            cin>>customer_accounts[i].balance;
        }
}
};
int main()
{
    class Customer c1(2,"aditya",19); // creating customer object
    c1.customer_accounts[1].display_balance(); // accessing the array of accounts of customer object so one customer object has a array for it self;
}