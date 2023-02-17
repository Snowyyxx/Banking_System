
#include"SavingBank.h" // Created header file for SavingBankAccount class; 
#include"DematAccount.h"
#include<vector>
class Customer{
    public:
    Customer(){};
    int customernumberofSBaccounts; // Customer detail etc.... 
    string customername;
    int customerage; 
    vector <DematAccount> demataccountvector;
    vector <SavingBankAccount> savingbankaccountvector;
    vector<Customer> Add_Customer(vector<Customer>customervector);

};



vector<Customer> Customer::Add_Customer(vector<Customer>customervector){
    static int count=0;
    Customer new_customer;
    int i;
    cout<<endl<<"Do you want to open a saving banks account? Press 1 for Yes: ";
    cin>>i;
    if(i==1){
    customervector.push_back(new_customer);
    cout<<"Enter Your Name: ";
    cin>>customervector.back().customername;
    cout<<"Enter Your Age: ";
    cin>>customervector.back().customerage;
    cout<<"How many accounts do you want to open: ";
    cin>>customervector.back().customernumberofSBaccounts;
    for(int i =0;i<customervector.back().customernumberofSBaccounts;i++){ // Constructor -> num_accounts,name,age ;
        class SavingBankAccount new_account;
        //savingbankaccountvector.push_back(new_account);
        i+1==1?cout<<"Enter details for "<< i+1<<"st "<<"account"<<endl:cout<<"Enter details for"<< i+1<<"th "<<"account"<<endl;
        cout<<"ATM Pin: "; // inputting the valuee of customer array
        cin>>new_account.atm_pin;
        cout<<"Account Number: ";
        cin>>new_account.account_number;
        cout<<"Balance: ";
        cin>>new_account.balance;
        customervector.back().savingbankaccountvector.insert(customervector.back().savingbankaccountvector.begin()+i,new_account);
        cout<<"Saving Bank Account created Succesfully";
    }
    }
    int j;
    cout<<"Do you want to open a Demat Account? Press 1 for yes: ";
    cin>> j;
    if(j==1){

        Customer new_customer;
        customervector.push_back(new_customer);
        cout<<"Enter Your Name: ";
        cin>>customervector.back().customername;
        cout<<"Enter Your Age: ";
        cin>>customervector.back().customerage;
        DematAccount new_object;
        customervector.back().demataccountvector.push_back(new_object);
        int d_balance,d_pin;
        cout<<"Balance you want to add: ";
        cin>>d_balance;
        cout<<"Pin you want to use: ";
        cin>>d_pin;
        customervector.back().demataccountvector.back().OpenDematAccount(d_balance,d_pin);
    } else{
        cout<<"Account not created"<<endl;
    }

    return customervector;
}


