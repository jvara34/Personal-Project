/*
 *Author: Julian Vara
 *Created: 4/16/2024
 *Purpose: CIS-17B Personal Project 
 */

#include <iostream> 
#include <string> 


using namespace std; 

//The user needs some kind of search bar for the website part 
struct Items
{
    string Backpacks; 
    string Jackets; 
    string Cars;
};

void greet();
int pickItem();
void itemChose(int, Items);

int main()
{
    Items items; 
    items.Backpacks = "Jansport";
    items.Jackets = "Patagonia"; 
    items.Cars = "Subaru";
    

    greet();
    int choice = pickItem();
    //Trying to return the value from the pickItem function to the itemChose function 
    //So I know what the user choose from the pickItem function :)
    itemChose(choice, items);
}

// This function introductions the user to the program and explains the 
// functionalilty of the program
void greet()
{
    cout << "Welcome to Julian's Store!" << endl; 
    cout << "This program is like Amazon but you cannot actually buy anything!" << endl; 
    
}

// Function purpose is to get the item choosen by the user 
int pickItem()
{
    int choice = 0;
    cout << "What would you like to shop for?" << endl;
    cout << "1) Backpacks" << endl; 
    cout << "2) Jackets" << endl; 
    cout << "3) Car" << endl; 
    cin >> choice; 

    return choice; 
}


void itemChose(int choice, Items items)
{
    /*This function will read from a file to get all of the data based on the 
     *Users choice 
     */
    if(choice == 1)
    {
        cout << items.Backpacks << endl;
    }
    if(choice == 2)
    {
        cout << items.Jackets << endl;
    }
    if(choice == 3)
    {
        cout << items.Cars << endl;
    }

}