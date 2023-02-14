#include<iostream>
using namespace std;
#include<vector>




class Stock{
    public:
    string name;
    int CurrentPrice,NumberOfStocks;

};

class DematAccount{
    int balance,pin;
    vector<Stock> StockVector;
    public:
    void buy_stocks();
    void sell_stocks();
    void display_stocks();
    DematAccount(int i_balance,int i_pin):balance(i_balance),pin(i_pin){};    
};


void DematAccount::buy_stocks(){
    Stock new_object;
    string temp_name;
    int temp_currentprice,temp_numberofstocks;
    cout<<"Name of Stock you want to buy? ";    
    cin>>temp_name;
    cout<<"Price of the stock? ";
    cin>>temp_currentprice;
    cout<<"How many stocks do you want to buy? ";
    cin>>temp_numberofstocks;
    int price; 
    price = temp_currentprice*temp_numberofstocks;
    if(balance>price){
        balance=balance - price;
        StockVector.push_back(new_object);
        StockVector.back().name = temp_name;
        StockVector.back().NumberOfStocks=temp_numberofstocks;
        StockVector.back().CurrentPrice =temp_currentprice;
        cout<<"Stock Bought Succesfully"<<endl;
        cout<<endl;
    }
    else {
        cout<<"Not enough balance"<<endl;
        cout<<endl;
    }
}

void DematAccount::display_stocks(){
    for(Stock i :StockVector){
        int count =0;
        cout<<"S.no"<<"\t"<<"NameOfStock"<<"\t"<<"SellingPriceOfStock"<<"\t"<<"NumberOfStocksAvailableToSell"<<endl;
        cout<<count+1<<":"<<"\t"<<i.name<<"\t\t\t"<<i.CurrentPrice<<"\t\t\t"<<i.NumberOfStocks;
        count++;
        cout<<endl;
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
    int NumberOfStocksToSell;
    cin>>NumberOfStocksToSell;
    //cout<<StockVector.at(sell_sno-1).name;
    vector<Stock>::iterator ptr; // pointer to a vector
    for(ptr = StockVector.begin();ptr<StockVector.end();ptr++){
        if(position==sell_sno-1){
           balance = balance+(StockVector.at(sell_sno-1).CurrentPrice*NumberOfStocksToSell);
           StockVector.at(sell_sno-1).NumberOfStocks=StockVector.at(sell_sno-1).NumberOfStocks-NumberOfStocksToSell;
           if(StockVector.at(sell_sno-1).NumberOfStocks==0){
            StockVector.erase(ptr);
           }
        }
        position++;
    }
    cout<<endl;
    display_stocks();
    cout<<"New Balance:"<<balance<<endl;
}

int main()
{
    DematAccount d1(1000,9103); // balance, pin
    d1.buy_stocks();
    d1.sell_stocks();

}