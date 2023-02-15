#include<iostream>
using namespace std;
#include<vector>
#include"Customer.h"
vector <Customer> customervector;

void create_customer(){
    Customer dummy_object;
    customervector = dummy_object.Add_Customer(customervector);    // adding customer;
}

int main(){

    create_customer();
    customervector.back().demat_Account.buy_stocks();
    //customervector.back().demat_Account.sell_stocks();
    //customervector.back().demat_Account.display_balance();
    //customervector.back().demat_Account.buy_stocks();
    //customervector.back().demat_Account.sell_stocks();
}

