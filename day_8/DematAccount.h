#include<iostream>
using namespace std;
#include<vector>
#include"stocks.h"



class DematAccount{
    int balance,pin;
    vector<Stock> stockvector;

    public:
    void buy_stocks();
    void sell_stocks();
    void display_stocks();
    void display_balance();
    DematAccount(){};
    void OpenDematAccount(int i_balance,int i_pin);
};

void DematAccount::display_balance(){
    cout<<"balance:"<<balance<<endl;
}


void DematAccount::OpenDematAccount(int i_balance,int i_pin){
    balance = i_balance;
    pin = i_pin;
    cout<<"Demat Account created succesfully"<<endl;
}

void DematAccount::buy_stocks(){

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
        class Stock new_object;
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

void DematAccount::display_stocks(){
    for(Stock i :stockvector){
        int count =0;
        cout<<endl;
        cout<<"Details for "<<count<<". stock";
        cout<<endl;
        cout<<"Name of Stock: "<<i.name<<endl;
        cout<<"Selling Price of Stock: "<<i.currentprice<<endl;
        cout<<"Number Of Stocks Available:"<<i.numberofstocks<<endl;
        count++;
    }
}


void DematAccount::sell_stocks(){
    cout<<"Current Balance"<<balance<<endl;
    cout<<endl;
    display_stocks();
    cout<<"Which stock do you want to sell? ";
    int sell_sno;
    int position =0 ;
    cin>>sell_sno;
    cout<<"How Many do you want to sell?";
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
    display_stocks();
    cout<<"New Balance:"<<balance<<endl;
}

