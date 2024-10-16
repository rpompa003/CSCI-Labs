//Made by Rafael Pompa
//Created on 10/12
//This program 
#include <iostream>
#include <cmath>
using namespace std;

void Store_coworker_sales(){
cout<<"Hey, how many $600 Tvs have you sold so far?";
}

//function declaration with function name multiplication
int multiplication(int Amount_sold, int Tv_Price){
  //times amount sold by the tv price to get total price
  int total_price;
  total_price = Amount_sold * Tv_Price;
  //returing the total price of the tvs
return total_price;
  }

//function declaration with function name calculate
int calculate(int total_price){
int result1;
int percent;
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
}
int main(){
  //SEtting up the coding Process
  int Amount_sold=0;
  float total_price=1;
  float result1 =0;
  float percent =0;
  float Tv_Price=600;
  //userinput for how ,amy tvs were sold
Store_coworker_sales();
cin>>Amount_sold;
cout<<" "<<endl;

//multiplying amount of tvs sold by the tv price
total_price = multiplication (Amount_sold, Tv_Price);//function call
cout<<"you made $"<<total_price<<" in tv sales so far" <<endl;

//calculating commission price
result1 = calculate( total_price);

if (total_price>=250000){
percent=6.75;
}
//if the price is under 50,000
else if (total_price<50000){
percent=4;
}
//if the price is between 50,000 and 250,000
else if (50000>=total_price <=250000){
percent=6;
}


//final outputs for total price, commission made, and percent commission is at.
cout<<"total price: $"<<total_price<<endl;
cout<<"comminssions made: $"<<result1<<endl;
cout<<"percent that the commission is at "<<percent <<"%"<<endl;
cout<<" "<<endl;

//final sentence showing all outputs
cout<<"You know that scene you sold "<<Amount_sold<<" tvs, you would have made $"<<total_price<<" dollars selling tvs," <<endl;
cout<<" you would get $"<< result1 <<" in comminssions at a "<<percent<<"%."<<endl;
}
