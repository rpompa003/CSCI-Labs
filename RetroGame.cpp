/***************************************
Memory Game
Author: Rafael Pompa
Date Completed: 2/25/2026
Description: This program simulates a game of Memory on a CLI.
***************************************/

#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include "RandomInt.hpp"
using namespace std;

// Setting up the struct variables
struct Card {
string Phrase;
bool Matched;
};

// non-member Function to checks if all cards in the array are matched
bool allCardsMatched(array<Card, 4> &cards) {
for (int i = 0; i < 4; i++) {
// Checking to see if their are any unmatched cards left
if (cards.at(i).Matched == false) {
return false;
}
}
// Loop finishes if all the cards are matched
return true;
}

// non-member Function to randomize the phrase for the cards
void buildRandomCardPointerArray(array<Card, 4> &cards, array<Card*, 8> &pointers) {
for (int i = 0; i < 4; i++) {
pointers.at(i) = &cards.at(i);
pointers.at(i + 4) = &cards.at(i);
}

// Creating a random number generator for shuffling 
Random::RandomInt randomIntGenerator(0, 7);
for (int i = 0; i < 8; i++) {
int randomPosition = randomIntGenerator.get();

Card* temp = pointers.at(i);
pointers.at(i) = pointers.at(randomPosition);
pointers.at(randomPosition) = temp;
}
}
// non member Function that displays the game board
void displayGameBoard(array<Card*, 8> &pointers) {
for (int i = 0; i < 8; i++) {
cout << "Card " << (i + 1) << ": ";
        
Card* currentCard = pointers.at(i);

// If the cards matched, show the phrase
if ((*currentCard).Matched == true) {
cout << (*currentCard).Phrase;
} else {
// If the cards don't matched, show ?
cout << "?";
}
cout << endl;
}
}

//Setting up the variables
int main() {
int totalGuesses = 0;
int card1 = 0;
int card2 = 0;

cout << "Welcome to Memory Game!" << endl << endl;

// Creating array of 4 Card objects with phrases
array<Card, 4> CardPhrase;
CardPhrase.at(0) = {"Flying Monkey", false};
CardPhrase.at(1) = {"Mad Cow", false};
CardPhrase.at(2) = {"Magic Genie", false};
CardPhrase.at(3) = {"Great Pumpkin", false};

// Creating pointer array that holds shuffled cards
array<Card*, 8> cardObjects;

buildRandomCardPointerArray(CardPhrase, cardObjects);

// Outing the total guesses so far
while (allCardsMatched(CardPhrase) == false) {
cout << "Total Guesses: " << totalGuesses << endl << endl;

// Outputing the current game board
displayGameBoard(cardObjects);

cout<< endl;

// Asking user to choose between 8 cards
cout << "Select two different cards between 1 and 8:" << endl;
cin >> card1 >> card2;

//Making sure the user picks two different cards
if (card1 == card2) {
cout << "You must select two different cards!" << endl;
continue;
}

// Minus 1 from the user input to match the array 0-7
int index1 = card1 - 1;
int index2 = card2 - 1;

Card* firstCard = cardObjects.at(index1);
Card* secondCard = cardObjects.at(index2);

// Checking to see of the cards match
if ((*firstCard).Phrase == (*secondCard).Phrase) {
cout << "You found a matching pair!" << endl;
cout << "Both cards say \"" << (*firstCard).Phrase << "\"" << endl;

// Changing matching cards as true in original CardPhrase array
for (int i = 0; i < 4; i++) {
if (CardPhrase.at(i).Phrase == (*firstCard).Phrase) {
CardPhrase.at(i).Matched = true;
}
}
} else {
// If cards don't match, reveal what phrase  they were
cout << "The cards don't match" << endl;
cout << "First card says \"" << (*firstCard).Phrase << "\"" << endl;
cout << "Second card says \"" << (*secondCard).Phrase << "\"" << endl;  // Add this line
}

// Increases the user total guesses
totalGuesses++;

// Allowing the user to confirm if they want to go onto their next turn
cout << "PRESS ENTER KEY TO CONTINUE..." << endl;
cin.ignore();
cin.get();
system("clear||cls");

}
cout << "Total Guesses: " << totalGuesses << endl << endl;

//displaying all the matched cards
displayGameBoard(cardObjects);
cout << endl;
cout << "You matched all of the cards! Game over." << endl;

return 0;
}