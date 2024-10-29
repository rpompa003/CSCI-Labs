//Made by Rafael Pompa
//Created on 10/28
//This program is to show Debugging (with loops)

#include<iostream>
#include <cmath>
using namespace std;

//Setting up the coding Process
int main() {
  float a = 0.0;
  float m = 0.0;
  float r = 0.0;
  float y = 0.0;  

// user input for amount borrowed
  cout<<"Enter the amount borrowed: ";
  cin>>a;
// user input for monthly payment
  cout<<"Enter the monthly payment you'll make: ";
  cin>>m;
// user input for intrest rate
  cout<<"Enter the annual interest rate: ";
  cin>>r;
// user input for years simulated
  cout<<"Enter the number of years you want to simulate: ";
  cin>>y;

// convert interest rate from percent to fraction
  r = r/100;

//iterate through each monthly
  for (int i = 0; i < 12 * y; i++){

//calculate additional interest
    float I = a*(r/12);

//add interest and subtract payment from balance
    a = a + I - m;
  }

cout<<"At the end of "<<y<<" years you owe "<<a<<" dollars";
}