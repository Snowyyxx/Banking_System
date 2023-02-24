#include<iostream>
using namespace std;
#include<vector>
#include"Customer.h"
#include "plog/Log.h"

vector<Customer> create_customer(vector<Customer> customervector) {
    Customer dummy_object;
    customervector = dummy_object.Add_Customer(customervector);    // adding customer;
    return customervector;
}


int main()

{
    // argument : customervector.back().demataccountvector
    vector <Customer> customervector;
    customervector = create_customer(customervector);
    customervector.back().demataccountvector.back().buy_stocks(customervector.back().demataccountvector);
    customervector.back().demataccountvector.back().sell_stocks(customervector.back().demataccountvector);

}


