//Made by Rafael Pompa
//Created on 10/12
//This program is to show a paramter and return in a fuction
#include <iostream>
#include <cmath>
using namespace std;

void Store_coworker_sales(){
cout<<"Hey Bob, how many $600 Tvs have you sold so far? ";
}

float calcuting_for_commission(float total_price){//function declaration with function name calcuting_for_commission
  float commission;
//if price is over 250,000
  if (total_price>=250000){
  commission=total_price*0.0675;
}
//if the price is under 50,000
  else if (total_price<50000){
  commission= total_price*0.04;
}
//if the price is between 50,000 and 250,000
  else if (total_price >= 50000 && total_price <= 250000){
  commission=total_price*0.06;
}
//returing commission price amount
return commission;
}

float calcuting_for_commission_percent(float total_price){//function declaration with function name calcuting_for_commission_percent
float percent;
//calculating commission percent
//if price is over 250,000
if (total_price>=250000){
percent=6.75;
}
//if the price is under 50,000
else if (total_price<50000){
percent=4;
}
//if the price is between 50,000 and 250,000
else if (total_price >= 50000 && total_price <= 250000){
percent=6;
}
//returing commission percentage
return percent;
}

int main(){
  //SEtting up the coding Process
  int Amount_sold=0;
  float total_price=1;
  float commission =0;
  float percent =0;
  float Tv_Price=600;

//starting sentence
Store_coworker_sales();
//userinput for how ,amy tvs were sold
cin>>Amount_sold;
cout<<" "<<endl;
//finding total price of the tvs
total_price= Amount_sold * Tv_Price;

commission = calcuting_for_commission( total_price );//function call

percent = calcuting_for_commission_percent( total_price);//function call

//final outputs for tvs sold, total price, commission made, and percent commission is at.
cout<<"tvs sold: "<<Amount_sold<<endl;
cout<<"total price: $"<<total_price<<endl;
cout<<"comminssions made: $"<<commission<<endl;
cout<<"percent that the commission is at "<<percent <<"%"<<endl;
cout<<" "<<endl;

//final sentence showing all outputs
cout<<"You know that scene you sold "<<Amount_sold<<" tvs, you would have made $"<<total_price<<" dollars selling tvs." <<endl;
cout<<"That means you would get $"<< commission <<" in comminssions at a "<<percent<<"%."<<endl;
}
