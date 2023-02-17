#include<iostream>
using namespace std;
#include<vector>
#include"Customer.h"

vector<Customer> create_customer(vector<Customer> customervector){
    Customer dummy_object;
    customervector = dummy_object.Add_Customer(customervector);    // adding customer;
    return customervector;
}


int main()

{
    // argument : customervector.back().demataccountvector
    vector <Customer> customervector;
    customervector = create_customer(customervector);
    customervector.back().savingbankaccountvector[1].display_balance();
}


