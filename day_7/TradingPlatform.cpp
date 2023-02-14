#include<iostream>
using namespace std;
#include<vector>
#include"Customer.h"



vector<Customer> Add_Customer(vector<Customer>CustomerVector){
//    static int count=0;
    class Customer object_new;
    CustomerVector.push_back(object_new);
    CustomerVector.back().Create_Customer();    
    return CustomerVector;
}

int main(){
    vector <Customer> CustomerVector;
    CustomerVector = Add_Customer(CustomerVector);
    CustomerVector.back().CustomerAccountArray[0].display_balance();
    CustomerVector.back().CustomerAccountArray[0].credit();
    CustomerVector.back().CustomerAccountArray[0].display_balance();
}
