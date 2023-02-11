
#include"SavingBank.h" // Created header file for SavingBankAccount class; 
class Customer{
    public:
    int CustomerNumberOfAccounts; // Customer detail etc.... 
    string CustomerName;
    int CustomerAge; 
    SavingBankAccount CustomerAccountArray[]; // This means that if a structure contains only a flexible array member, it will have no size and cannot be used to allocate memory or create instances of the structure. To work around this limitation, you can add one or more other members to the structure, even if they are not needed for your specific use case.
    void Create_Customer();
    Customer(){};
};

void Customer::Create_Customer(){
    
    cout<<"Enter Your Name: ";
    cin>>CustomerName;
    cout<<endl<<"Enter Your Age: ";
    cin>>CustomerAge;
    cout<<endl<<"Enter the number of accounts you would like to open: ";
    cin>>CustomerNumberOfAccounts; 
    for(int i =0;i<CustomerNumberOfAccounts;i++){ // Constructor -> num_accounts,name,age ;
        cout<<"Enter Detail for "<<i+1<<"th"<<" account:"<<endl;
        cout<<"ATM Pin for "<<i+1<<"th"<<" account: "; // inputting the valuee of customer array
        cin>>CustomerAccountArray[i].atm_pin;
        cout<<endl<<"Account Number for "<<i+1<<"th"<<" account";
        cin>>CustomerAccountArray[i].account_number;
        cout<<endl<<"Balance for "<<i+1<<"th"<<" account";
        cin>>CustomerAccountArray[i].balance;
    }
}