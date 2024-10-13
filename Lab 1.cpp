//Made by Rafael Pompa
//Created on 10/12
//This program 
#include <iostream>
#include <cmath>
using namespace std;


int main(){
  //SEtting up the coding Process
  int Amount_sold=0;
  int Tv_Price=600;
  float total_price=1;
  float result1 =0;
  float percent =0;
  //userinput for how ,amy tvs were sold
cout<<"Hey, how many $600 Tvs have you sold so far?"<<endl;
cin>>Amount_sold;
//multiplying amount of tvs sold by the tv price
total_price=Tv_Price;
total_price=(Amount_sold*Tv_Price);
cout<<Amount_sold<<"*"<<Tv_Price<<"="<<total_price<<endl;
//if the price is over 250,000
if (total_price>=250000){
result1=total_price*0.0675;
percent=6.75;
}
//if the price is under 50,000
else if (total_price<50000){
result1= total_price*0.04;
percent=4;
}
//if the price is between 50,000 and 250,000
else if (50000>=total_price <=250000){
result1=total_price*0.06;
percent=6;
}
//final sentence showing all outputs
cout<<"If we made $"<<total_price<<" dollars selling tvs, than we would get $"<< result1 <<" in comminssions at a "<<percent<<"%."<<endl;
}