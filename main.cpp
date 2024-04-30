/*
 *Author: Julian Vara
 *Created: 4/16/2024
 *Purpose: CIS-17B Personal Project 
 */

#include <iostream> 
#include <string> 
#include <fstream> //This header allows us to read and write to bin files 
#include <cstring>

using namespace std; 

//The user needs some kind of search bar for the website part 
class Items
{   
    public:
    string Backpacks; 
    string Jackets; 
    string Cars;
};

class Users
{
    public:
    string userName; 
    string userPassword; 
    char n[12]; //This is for User NAME
    char p[12]; //This is for PASSWORD
};

void userMenu(Users);
int pickItem();
void itemChose(int, Items);
//void login(); 
void signUp(Users);


int main()
{
    Items items; 
    items.Backpacks = "Jansport";
    items.Jackets = "Patagonia"; 
    items.Cars = "Subaru";

    Users tempUser;
    

    userMenu(tempUser);
    int choice = pickItem();
    //Trying to return the value from the pickItem function to the itemChose function 
    //So I know what the user choose from the pickItem function :)
    itemChose(choice, items);
}

// This function introductions the user to the program and explains the 
// functionalilty of the program
void userMenu(Users tempUsers)
{
    int input = 0; 
    cout << "Hello User, " << endl;
    cout << "Thank you for joining me today! " << endl; 
    cout << "1) login: " << endl; 
    cout << "2) Sign up: " << endl;
    cin >> input; 
    
    switch(input)
    {
        case 1: 
            //login();
            break;
        case 2:
            signUp(tempUsers);
            break;
        default:
            cout << "Wrong value";
    }
}

/*void login()
{
    char userName;
    char userPassword;
    cout << "User Name: " << endl;
    cin >> userName; 
    cout << "Password: " << endl;
    cin >> userPassword;
    fstream f("userinfo.bin", ios::out | ios::binary);

    if(f)
    {
        f.read(userName, userPassword);

        f.close();
    }
    //Gets User Input and compares it to the data stored in the binary file 
    //If the data is not found in binary file then the User does not exist
    /*
     *Need to get this function to read from a binary file 
     *I don't understand the read function and how it works Need to look further 
     *into the function
     */ 
//}
//*/

void signUp(Users tempUser)
{
    //the userName and password should be taken from the class  
    string userName;
    string userPassword;  
    cout << "Hello New User" << endl;
    cout << "We will need a user name and password" << endl; 
    cout << "User Name: " << endl;
    cin >> userName; 
    cout << "Password: " << endl; 
    cin >> userPassword; 

    ofstream f; 
    f.open("userinfo.dat", ios::binary | ios::out);

    //Convert the tempUser.userName from a string to a char* 
    strcpy(tempUser.n, userName);
    strcpy(tempUser.p, userPassword);
    


    if(f)
    {
        f.write(reinterpret_cast<char*>(&n), sizeof(tempUser)); //I do not understand how this works?
        f.write(reinterpret_cast<char*>(&p), sizeof(tempUser));

        f.close();
    }
    else
    {
        cout << "Error\n";
    }
    
    //Gets User Input and adds it to the binary file 
    //Checks to see if user is already added to bin file 
    //If not then add the new User info  
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