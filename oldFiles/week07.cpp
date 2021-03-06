#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void initialOutput();
void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char* passMessage = ":)";
const char* failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
    char text[8] = "*MAIN**";
    long number = 123456;
    void (*pointerFunction)() = fail;
    const char* message = failMessage;

    initialOutput();

    // display the initial values of the local variables
    cout << "main() : " << (void*)main << endl;
    cout << "\ttext:             " << text << endl;
    cout << "\tnumber:           " << number << endl;
    cout << "\tmessage:          " << message << endl;
    cout << "\tfunction pointer: ";
    pointerFunction();

    // call the other functions
    one(number + 111111);     // 234567

    // display the new values of the local variables
    cout << "main() - after\n";
    cout << "\ttext:             " << text << endl;
    cout << "\tnumber:           " << number << endl;
    cout << "\tmessage:          " << message << endl;
    cout << "\tfunction pointer: ";
    pointerFunction();

    return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char* p)
{
    string output;
    for (int i = 0; i < 8; i++)
        output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
    return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
    char text[8] = "**ONE**";

    cout << "one() : " << (void*)one << endl;
    cout << "\tmessage: " << (void*)failMessage << endl;
    cout << "\tfail():  " << (void*)fail << endl;
    cout << endl;

    two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
    // start your display of the stack from this point
    long bow = number + 111111;     // 456789
    char text[8] = "**TWO**";
    long* pLong = NULL;
    char* pChar = NULL;

    int mainPtr = 0;
    int numberPtr = 0;
    int messagePtr = 0;
    int functionPtr = 0;

    // header for our table. Use these setw() offsets in your table
    cout << '[' << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
    cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";
    for (long i = 24; i >= -8; i--)   // You may need to change 24 to another number +17?
    {
        ////////////////////////////////////////////////
        // Insert code here to display the callstack
        pLong = &bow + i;
        pChar = (char*)pLong;

        if (displayCharArray(pChar) == " * M A I N * * .") {
            mainPtr = i;
        }

        if (*pLong == 123456) {
            numberPtr = i;
        }
        
        if(*pLong == (long)(void*)failMessage) {
            messagePtr = i;
        }      

        if(*pLong == (long)(void*)fail) {
            functionPtr = i;
        }
        
        cout << '[' << setw(3) << i << ']'
            << setw(15) << hex << showbase << pLong
            << setw(20) << *pLong
            << setw(20) << dec << *pLong
            << setw(18) << displayCharArray(pChar)
            << endl;
        //
        ////////////////////////////////////////////////
    }

    ////////////////////////////////////////////////
    // Insert code here to change the variables in main()
    // change text in main() to "*main**"    

    pLong = &bow + mainPtr;
    pChar = (char*)pLong;

    pChar[1] = 'm';
    pChar[2] = 'a'; 
    pChar[3] = 'i'; 
    pChar[4] = 'n';

    // change number in main() to 654321
    pLong = &bow + numberPtr;
    *pLong = 654321;

    // change pointerFunction in main() to point to pass    
    pLong = &bow + functionPtr;
    *pLong = (long)(void*)pass;
    
    // change message in main() to point to passMessage
    pLong = &bow + messagePtr;
    *pLong = (long)(void*)passMessage;
      
    ////////////////////////////////////////////////
}

void initialOutput() {
    int * pointsToHeap = NULL;
    pointsToHeap = new int [1];

    cout << endl;
    cout << "Code:  " << &passMessage << endl;
    cout << "Stack: " << &pointsToHeap << endl;
    cout << "Heap:  " << pointsToHeap << endl;
    cout << endl;
}