//made by rafael pompa
//cretaed on 10/10/24
//this program shows the user inputs for what kind of drink they want and additional options for thir drink

#include <iostream>
#include <cmath>
using namespace std;
//setting up the code

void menu(){//function declaration with function name menu.
//this function demostrate the output of a menu and user inputs.
//function body
  cout<<"Drinks Menu"<<"\n";
  cout<<"1.  Espresso ..................$3.25"<<"\n";
  cout<<"2.  Cappuccino.................$5.25"<<"\n";
  cout<<"3.  Chai Latte.................$5.75"<<"\n";
  cout<<"4.  Chai Tea...................$3.75"<<"\n";
}
int main() {
int drink=0;
int sugar=0;
int milk=0;
int whipcream=0;
float total_price=0;
float tax=0.50;
float price=0;
//the results for the code
string result1 = "";
string result2 = "";
string result3 = "";
string result4 = "";
//user input for their drink
cout<< "please enter what you would like to drink"<<endl;
menu();//function call
cout<<"the options are 1 for Espresso, 2 for Cappuccino, 3 for Latte, and 4 for Tea."<<endl;
cin>>drink;
//if/else descions
if (drink==1){
result1 = "Espresso";
price = 3.25;
}
else if (drink==2){
result1="Cappuccino";
price = 5.25;
}
//if/else descions
else if (drink==3){
result1="Latte";
price = 3.75;
}
else if (drink==4){
result1="Tea"; 
price = 5.75;
}
//user input for the sugar option
cout<<"what kind of sugar would you like?"<< endl;
cout<<"the options are 1 for regular, 2 for no sugar, and 3 for extra sugar."<<endl;
cin>> sugar;
//if/else descions
if(sugar==1){
result2 = "regular";
}
else if (sugar==2){
result2 = "no";
}
//if/else descions
else if(sugar==3){
result2 = "extra";
} 
//user input for the milk option
cout<<"what kind of milk do you want?"<<endl;
cout<<"the options are 1 for almond milk, 2 for no milk, and 3 for whole milk."<<endl;
cin>>milk;
//if/else descions
if(milk==1){
result3 = "almond";
}
else if (milk==2){
result3 = "no";
}
//if/else descions
else if(milk==3){
result3 = "whole";
}
//user input for if they want whip cream or not
cout<<"Do you want any whip cream on your "<<result1<<"?"<<endl;
cout<<"the options are 1 for yes to whip cream and 2 for no whipcream."<<endl;
cin>>whipcream;
//if/else descions
if(whipcream==1){
result4 = "yes";
}else{
result4 = "no";
}
total_price= price + tax;
//finial output of the user drink order
cout<<"Alright, you order a "<<result1<< " with "<< result2 <<" sugar with "<<result3<< " milk and you said "<<result4<<" to whip cream on top."<<endl;
cout<<"the toal price is "<<total_price<<endl;
}
