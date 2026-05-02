/***********************************************************
Program Name: Vehicle Searcher
Program Author: Kyle NoCompile
Date Completed: 3/17/19
Program Description:
This program allows the user to search for a vehicle
from the data supplied in a "VehiclesForSale.xml"
file and filter based on vehicle year and price.
Modified Date: 4/15/2026
Modified Description: I went through Kyle code and added comments to show him know what chagnges
i made and where he made the errors
***********************************************************/

//I changed #including to #include
// added a string
#include <iostream>
#include <vector>
#include <string>
// I changed <Pugixml.hpp> to "Pugixml.hpp"
#include "pugixml.hpp" // Using pugixml library to parse XML
// added a missing semicolon
using namespace std;

// Definition of Vehicle custom data type
class Vehicle
{
// changed ; to :
private:
// added a missing simicolon
string make_;
string model_;
int year_;
float price_;

//change the spelling to public from publicly
public:
// Constructor with initializer list
// changed the varibales for make and mode to string and added a comma
// added a simicolon
Vehicle(string make, string model, int year, float price)
    : make_(make), model_(model), year_(year), price_(price) {};

// Vehicle make getter
string getMake()
{
// added a simicolon and changed make to make_
return make_;
}

// Vehicle model getter
// changed () to {}
string getModel()
{
return model_;
}

// Vehicle year getter
int getYear()
{

return year_;
}
// Vehicle year getter
float getPrice()
{
return price_;
}
// added a simicolon to the end
};

// changed string to int
int main()
// changed () to {}
{
// Instantiate vector to hold all vehicle objects parsed from XML
//change <string> to <vehicle>
vector<Vehicle> vehicles;

// Instantiate xml document variable and load "VehiclesForSale.xml" file
pugi::xml_document doc;

//changed else if to if and {} to ()
if (!doc.load_file("VehiclesForSale.xml"))
{
cerr<<"Problem opening xml file \"VehiclesForSale.xml\"\n";
return 1;
}

// Get the root node in the XML file
// changed == to =
pugi::xml_node root = doc.first_child();
// Loop through all "vehicle" elements in the XML file
// changed while to for
for (pugi::xml_node xmlVehicle : root.children("vehicle"))
{
// Get make, model, year, and price from current vehicle element
// changed = to = and xmlVehicle->child_value to xmlVehicle.child_value
string make = xmlVehicle.child_value("make");
string model = xmlVehicle.child_value("model");
string year = xmlVehicle.child_value("year");
string price = xmlVehicle.child_value("price");

// Instantiate Vehicle object using values from XML
// Use stoi function to convert year from string to integer
// Use stof function to convert price from string to float

//added simicolons
Vehicle vehicle(make, model, stoi(year), stof(price));

// Push vehicle object to back of vector
// made it pushback
vehicles.push_back(vehicle);
}

// Variables to hold user input
// chande : to a ;
int minYear = 0;
float maxPrice= 0;

// Prompt and get user minimum vehicle year for filtering
//fixed the way the arrows were facing
cout<<"Enter the minimum vehicle year to show: ";
cin>>minYear;

// Prompt and get user minimum vehicle price for filtering
// changed cin to cout and cout to cin
cout<<"Enter the maximum price to show: ";
cin>>maxPrice;
//creates a newline to make a space beteewn enter and result

// changed fmt.print to cout
cout<<"\nResults:\n";

// Loop through vector of vehicle objects
// added () to the for loop

for (Vehicle &v : vehicles)
// changed [] to {}
{
// Only show vehicles that have a year greater than or equal to the minimum
// year and a price less than or equal to the maximum year specified by the user
// changed || to && and added ()
if (v.getYear() >= minYear && v.getPrice() <= maxPrice)
{

//changed < to << and added v.
cout<<endl;
cout<<v.getYear()<<" "<<v.getMake()<<" "<<v.getModel()<<endl;
cout<<"$"<<v.getPrice()<<endl;
}
}

// changed finished to return and changed the ) to }
return 0;
}