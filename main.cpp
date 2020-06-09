#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void menu();
void noMitigation();
void weakMitigation();
void strongMitigation();
string getUsername();
string getPswd();
string sanitizeInputWeak(string input);
string generateQuery(string username, string pswd);
bool isUsernameWhitelisted(string username);
bool isPasswordWhiteListed(string password);


int main()
{
    menu();
    return 0;
}

//get the username from the user
string getUsername() 
{
    string username = "";
    cout << "Enter username: ";
    getline(cin, username);
    // cout << username << endl;
    return username;
}

//get the password from the user
string getPswd() 
{
    string pswd = "";
    cout << "Enter password: ";
    getline(cin, pswd);
    return pswd;
}

// use the username and password to generate a sql query to authenticate the user
string generateQuery(string username, string pswd) 
{
    string query = "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='" + pswd + "';";
    return query;   
}

/********************************************
* Things that need to be sanitized
* 1. UNION for union attack
* 2. OR for tautology attack
* 3. --, # for comment attack 
* 4. ; for additional statements
*********************************************/
string sanitizeInputWeak(string input) 
{
    //create a lowercase input to check because sql key statements are case insensitive
    string lowercaseInput = "";
    for (int i = 0; i < input.size(); i++) {
        lowercaseInput.push_back(tolower(input[i]));
    }

    //go backwards so that the string avoids buffer reallocation since we are deleting stuff
    //also makes sure a key word doesn't get created if we delete something in the middle
    for (int i = lowercaseInput.size() - 1; i >= 0; i--) 
    {
        //handle 1 character sanitation
        if (lowercaseInput[i] == '#' || lowercaseInput[i] == ';') 
        {
            //erase from regular input and lowercase input to keep track
            input.erase(input.begin() + i);
            lowercaseInput.erase(lowercaseInput.begin() + i);
            i++;
        }
        // 2 character sanitation
        //convert letters to lower because sql is case insensitive
        else if (lowercaseInput.substr(i, 3) == " or" || lowercaseInput.substr(i, 3) == " --") 
        {
            input.erase(i, 3);
            lowercaseInput.erase(i, 3);
            i++;
        }
        //handle union
        else if (lowercaseInput.substr(i, 6) == " union") {
            input.erase(i, 6);
            lowercaseInput.erase(i, 6);
            i++;
        }
    }
    cout << input << endl;
    return input;
}

bool isUsernameWhiteListed(string username)
{
    string namesInDataBase[12] = {"Jan", "Jay", "Jerry", "James", "Matthew", "Johnathan", "Jenni", "Dona", "Jeff", "Margret", "Bryce", "Alex"};
    
    bool found = false;
    
    for (int i = 0; i < 12; i++)
    {
        if (username == namesInDataBase[i])
        {
            found = true;
        }
    }
    
    return found;
} 

bool isPasswordWhiteListed(string password)
{
    string passwordInDataBase[12] = {"12345", "Password123", "password!", "hunter2", "grapesofwrath", "mysteriousStranger", "OpenSesame", "Pa$$word123", "admin", "correcthorsebatterystaple", "123", "dorwssap" };

    bool found = false;
    
    for (int i = 0; i < 12; i++)
    {
        if (password == passwordInDataBase[i])
        {
            found = true;
        }
    }
    
    return found;
}

void menu() {
    char choice;

    cout << "Enter n to test no mitigation" << endl;
    cout << "Enter w to test weak mitigation" << endl;
    cout << "Enter s to test strong mitigation" << endl;
    cout << "enter q to quit" << endl;

    cin  >> choice;
    cin.ignore();
    
    switch (tolower(choice))
    {
    case 'n':
        noMitigation();
        menu();
        break;
    case 'w':
        weakMitigation();
        menu();
        break;
    case 's':
        strongMitigation();
        menu();
        break;
    case 'q':
        break;
    default:
        cout << "Please enter a valid choice" << endl;
        menu();
        break;
    }

}

void noMitigation() {
    string username = getUsername();
    string password = getPswd();
    cout << generateQuery(username, password) << endl;
}

void weakMitigation() {
    string username = getUsername();
    string password = getPswd();
    cout << generateQuery(sanitizeInputWeak(username), sanitizeInputWeak(password)) << endl;
}

void strongMitigation() {
    string username = getUsername();
    string password = getPswd();

    if(isUsernameWhiteListed(username) && isPasswordWhiteListed(password)) {
        cout << generateQuery(username, password) << endl;
    }
    else {
        cout << "Unaccepted input" << endl;
    }
}