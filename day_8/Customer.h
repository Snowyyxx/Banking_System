
#include"SavingBank.h" // Created header file for SavingBankAccount class; 
#include"DematAccount.h"
class Customer{
    public:
    Customer(){};
    int customernumberofaccounts; // Customer detail etc.... 
    string customername;
    int customerage; 
    DematAccount demat_Account;
    SavingBankAccount saving_account_array[]; // This means that if a structure contains only a flexible array member, it will have no size and cannot be used to allocate memory or create instances of the structure. To work around this limitation, you can add one or more other members to the structure, even if they are not needed for your specific use case.
    vector<Customer> Add_Customer(vector<Customer>customervector);

};


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
    cout<<endl;
    cin>>customervector.back().customernumberofaccounts;
    for(int i =0;i<customervector.back().customernumberofaccounts;i++){ // Constructor -> num_accounts,name,age ;
        i+1==1?cout<<"Enter details for "<< i+1<<"st "<<"account"<<endl:cout<<"Enter details for"<< i+1<<"th "<<"account"<<endl;
        cout<<"ATM Pin: "; // inputting the valuee of customer array
        cin>>customervector.back().saving_account_array[i].atm_pin;
        cout<<"Account Number: ";
        cin>>customervector.back().saving_account_array[i].account_number;
        cout<<endl<<"Balance: ";
        cin>>customervector.back().saving_account_array[i].balance;
    }
    int j;
    cout<<"Do you want to open a Demat Account? Press 1 for yes: ";
    cin>> j;
    if(j==1){
        int d_balance,d_pin;
        cout<<"Balance you want to add: ";
        cin>>d_balance;
        cout<<"Pin you want to use: ";
        cin>>d_pin;
        customervector.back().demat_Account.OpenDematAccount(d_balance,d_pin);
    }

    return customervector;
}


}