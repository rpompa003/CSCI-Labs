/***************************************
Rigged
Author: [Rafael popma]
Date Completed: [2/25/2026]
Description: [This program will genrate random numbers for a simple number matching game but will never let the user win]
***************************************/

#include <iostream>
#include <string>
#include "RandomInt.hpp"
using namespace std ;

int main(){
// Declarng the variable for user input
int NumberSize = 0;

// Creating dialouge
cout << "Welcome to the totally fair game!" << endl << endl;
cout << "If you get all matching numbers, you win. Otherwise, you lose." << endl;
cout << "Enter the size of the set of numbers to produce (min = 2)" << endl;
// inputing the amount of time the random numbers are generated
cin >> NumberSize ;

// making sure the user input is atleast 2
if(NumberSize < 2) {
NumberSize = 2;
}

// Create random generator with max repeats = one less than user input
Random::RandomInt randomIntGenerator(1, 7, NumberSize - 1); // Will generate integers between 1 and 7 (inclusively)

// Generate and display numbers
// Total++ countinues the loop until it reaches the user input
for(int total = 0 ; total < NumberSize ; total++){
int randomInt = randomIntGenerator.get() ;
cout << randomInt ;

// Printing a space only if this is not the last number
if(total < NumberSize - 1){
cout << " " ;
}
}
cout << endl ;

// Displaying that the User always loses
cout << "Not all numbers match. I can't believe you lost!" << endl ;

return 0;
}