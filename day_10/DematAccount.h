#include<iostream>
using namespace std;
#include<vector>
#include"stocks.h"



class DematAccount{
    int balance,pin;
    vector<Stock> stockvector;
    public: 
    void buy_stocks(vector <DematAccount> demataccountvector); // demataccountvector as input;
    int check_account_open(vector <DematAccount> demataccountvector);
    void sell_stocks(vector <DematAccount> demataccountvector);
    void display_stocks(vector <DematAccount> demataccountvector);
    void display_balance(vector <DematAccount> demataccountvector);
    DematAccount(){};
    void OpenDematAccount(int i_balance,int i_pin);
};

void DematAccount::display_balance(vector <DematAccount> demataccountvector){
    if(check_account_open(demataccountvector)==7){
    cout<<"balance:"<<balance<<endl;
}
    else{
        cout<<"Account not open"<<endl;
    }
}

int DematAccount::check_account_open(vector <DematAccount> demataccountvector){
    if(demataccountvector.size()>0){
        return 7;
    }
}

void DematAccount::OpenDematAccount(int i_balance,int i_pin){
    balance = i_balance;
    pin = i_pin;
    cout<<"Demat Account created succesfully"<<endl;
}

void DematAccount::buy_stocks(vector <DematAccount> demataccountvector){
    if(check_account_open(demataccountvector)==7){
    Stock new_object;
    string temp_name;
    int temp_currentprice,temp_numberofstocks;
    cout<<"Name of Stock you want to buy: ";    
    cin>>temp_name;
    cout<<"Price of the stock: ";
    cin>>temp_currentprice;
    cout<<"How many stocks do you want to buy: ";
    cin>>temp_numberofstocks;
    int price=temp_currentprice*temp_numberofstocks;
    if(balance>price){

        balance = balance - price;
        new_object.name = temp_name;
        new_object.currentprice = temp_currentprice;
        new_object.numberofstocks = temp_numberofstocks;
        stockvector.push_back(new_object);
        cout<<"Stock Bought Succesfully"<<endl;

    }
    else {
        cout<<"Not enough balance"<<endl;
    }
    }
    else{
        cout<<"Account not open"<<endl;
    }
}

void DematAccount::display_stocks(vector <DematAccount> demataccountvector){
    if(check_account_open(demataccountvector)==7){
    for(Stock i :stockvector){
        int count =0;
        cout<<endl;
        cout<<"Details for "<<count+1<<". stock";
        cout<<endl;
        cout<<"Name of Stock: "<<i.name<<endl;
        cout<<"Selling Price of Stock: "<<i.currentprice<<endl;
        cout<<"Number Of Stocks Available: "<<i.numberofstocks<<endl;
        count++;
    }
    }
    else{
        cout<<"Account not open<<"<<endl;
    }
}


void DematAccount::sell_stocks(vector <DematAccount> demataccountvector){
    if(check_account_open(demataccountvector)==7){
    cout<<"Current Balance"<<balance<<endl;
    cout<<endl;
    display_stocks(demataccountvector);
    cout<<"Which stock do you want to sell? ";
    int sell_sno;
    int position =0 ;
    cin>>sell_sno;
    cout<<"How Many do you want to sell(Select Serial Number): ";
    int numberofstockstosell;
    cin>>numberofstockstosell;
    //cout<<stockvector.at(sell_sno-1).name;
    vector<Stock>::iterator ptr; // pointer to a vector
    for(ptr = stockvector.begin();ptr<stockvector.end();ptr++){
        if(position==sell_sno-1){
           balance = balance+(stockvector.at(sell_sno-1).currentprice*numberofstockstosell);
           stockvector.at(sell_sno-1).numberofstocks=stockvector.at(sell_sno-1).numberofstocks-numberofstockstosell;
           if(stockvector.at(sell_sno-1).numberofstocks==0){
            stockvector.erase(ptr);
           }
        }
        position++;
    }
    cout<<endl;
    display_stocks(demataccountvector);
    cout<<"New Balance:"<<balance<<endl;
    }
    else{
        cout<<"Account not open"<<endl;
    }
}

