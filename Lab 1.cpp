//made by rafael pompa
//date 12/3
//this program will allow the player to choose between paths, upgrade their gear, fight monsters, and answer questions to see who will attack

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to display story
void story(){
// Describe the setting and the player's purpose
cout << "Hello adventurer that has traveled from far away, you arrived in the small border town of Red Haven. As the sun dipped" << endl;
cout << "below the horizon, the Monsters had been attacking the villages each night, and the townsfolk were desperate for help." << endl;
cout << "The mayor tells you, who looks like an older man with tired eyes, they say you have come to get rid of the monsters." << endl;
cout << " " << endl;
}

//generating a question base on the path difficulty chosen by the player
// Function to generate math questions
int generateQuestion(string difficulty) {
    int num1, num2, answer;
    char operation;

    // Adjust question parameters based on difficulty level
    if (difficulty == "easy") {
    num1 = rand() % 15 + 1; // Random number between 1 and 15
    num2 = rand() % 15 + 1;
    operation = '+'; // Only addition for easy difficulty
    answer = num1 + num2;
    } else {
    num1 = rand() % 50 + 1; // Random number between 1 and 50
    num2 = rand() % 50 + 1;
    operation = '-'; // Only subtraction for hard difficulty
    answer = num1 - num2;
    }

    // Display the question to the player
    cout << "Solve: " << num1 << " " << operation << " " << num2 << endl;
    return answer;
}

//setting up the code
int main() {
srand(time(0)); // Seed for random number generation
string paths;
int level = 1;
int total_gold = 0;
int reward = 0;
//players health and damage
int player_hp = 100;
int player_attack_damage = 12;
string name;
string Kindom_name;
//monster health and damage
int monster_attack_damage = 10;
int monster_hp = 12;


cout << "Enter your name, adventurer: ";
cin >> name;
cout << "Enter the name of your kingdom: ";
cin >> Kindom_name;
story();//game story lime

// Main game loop for levels
while (level <= 4) {
cout<< "enter the word easy or hard with an under case  to choose a path"<<endl;
cout << "Level " << level << ": Choose your path (easy/hard): ";
cin >> paths;

// Validate input
if (paths != "easy" && paths != "hard") {
cout << "Invalid path! Please choose 'easy' or 'hard'." << endl;
cout << " "<<endl;
continue;
}

int Total_monsters = 3; // Number of monsters per level
 // Level storyline
if (paths == "easy") {
cout << "You take the easier route, a winding path through a quiet forest. The air is calm, but danger still lurks"<< endl;
} else {
cout << "You choose the harder route, a treacherous climb through rocky terrain. The sounds of monsters echo around you"<< endl;
}
// Loop through each monster in the level
while (Total_monsters > 0) {
if (paths == "easy") {
monster_attack_damage = 10;
monster_hp = 12;
} else {
monster_attack_damage = 15;
monster_hp = 24;
}

cout << "Answer this question correctly to attack!" << endl;

// Combat loop
while (monster_hp > 0 && player_hp > 0) {
int correct_answer = generateQuestion(paths); // Generate math question based on player choice path

int guess;
cin >> guess; // Player's answer

 // Check if the answer is correct
if (guess != correct_answer) {
cout << "The monster attacks!" << endl;
player_hp -= monster_attack_damage;  // Player loses health
cout << "Player HP: " << player_hp << endl;

} else {
cout << "You attack the monster!" << endl;
monster_hp -= player_attack_damage; // Monster loses health
cout << "Monster HP: " << monster_hp << endl;
}
}
// Monster defeated
if (monster_hp <= 0) {
cout << "The monster is defeated!" << endl;

Total_monsters--;
cout << "There are " << Total_monsters << " monsters left to fight." << endl;
cout << " "<<endl;
}

// Check if the Player is defeated
if (player_hp <= 0) {
cout << "Game over! You ran out of health." << endl;
return 0;
}

// Reward player with gold
if (paths == "easy") {
reward = 50;
} else {
reward = 100;
}

//increase amount of gold they have
total_gold += reward;
cout << "You cleared the level and received " << reward << " gold! Total gold: " << total_gold << endl;
cout << " "<<endl;

// If your moving to the next level or the boss fight
if (level < 4) {
cout << "The journey continues. The challenges ahead will only continue"<<endl;
} else {
cout << "You approach the leader of the monsters. The final battle awaits"<<endl;;
}

//increasing the level by 1
level++;
}
}

if (player_hp <= 0) {
cout << "Game over! You ran out of health and the adventures ends." << endl;
}else{
// Final Boss Fight
cout << "You have made it to the final boss!" << endl;
cout<< "The ground shakes as the leader emerges from the shadows. Its piercing eyes fixate on you"<<endl;

int boss_hp = 150;
int boss_attack_damage = 25;

// Combat loop for the boss
while (boss_hp > 0 && player_hp > 0) {
int correct_answer = generateQuestion("hard"); // Boss uses hard questions
int guess;

cin >> guess;// Player's answer

// Check if the answer is correct
if (guess != correct_answer) {//if the answer is wrong
cout << "The boss attacks!" << endl;
player_hp -= boss_attack_damage;
cout << "Player HP: " << player_hp << endl;

} else { //if the answer is right
cout << "You attack the boss!" << endl;
boss_hp -= player_attack_damage;
cout << "Boss HP: " << boss_hp << endl;
}

// Check if the Player is defeated
if (player_hp <= 0) {
cout << "Game over! You ran out of health." << endl;
return 0;
}

// Player defeats the boss
cout << "With a final strike, the boss collapses. The land is saved!"<<endl;
cout << "The townsfolk celebrate your bravery. You end your journey with " << total_gold << " gold pieces." << endl;
}
}
}