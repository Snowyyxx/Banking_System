
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
    SavingBankAccount *saving_account_array;
    SavingBankAccount *create_account_array(SavingBankAccount * saving_account_array);
    vector<Customer> Add_Customer(vector<Customer>customervector);

};

SavingBankAccount* Customer::create_account_array(SavingBankAccount * saving_account_array){
    for(int i =0 ;i<customernumberofSBaccounts;i++){
        saving_account_array++;
    }
}

vector<Customer> Customer::Add_Customer(vector<Customer>customervector){
//    static int count=0;
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
        i+1==1?cout<<"Enter details for "<< i+1<<"st "<<"account"<<endl:cout<<"Enter details for"<< i+1<<"th "<<"account"<<endl;
        cout<<"ATM Pin: "; // inputting the valuee of customer array
        cin>>customervector.back().saving_account_array[i].atm_pin;
        cout<<"Account Number: ";
        cin>>customervector.back().saving_account_array[i].account_number;
        cout<<"Balance: ";
        cin>>customervector.back().saving_account_array[i].balance;
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


