#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void arrayVulnerability(int index);
void arrayWorking();
void arrayExploit();

void arcVulnerability(int index);
void arcWorking();
void arcExploit();

void vtableVulnerability();
void vtableWorking();
void vtableExploit();

void stackVulnerability();
void stackWorking();
void stackExploit();

void heapVulnerability(char, char);
void heapWorking();
void heapExploit();

bool intVulnerability(int);
void intWorking();
void intExploit();

void ansiVulnerability();
void ansiWorking();
void ansiExploit();

void pFunction();
void badFunction();

int main()
{
	cout << "Select a test:\n"
		<< "1: array working\n"
		<< "2: array Exploit\n"
		<< "3: arc working\n"
		<< "4: arc Exploit\n"
		<< "5: vtable working\n"
		<< "6: vtable Exploit\n"
		<< "7: stack working\n"
		<< "8: stack Exploit\n"
		<< "9: heap working\n"
		<< "10: heap Exploit\n"
		<< "11: int working\n"
		<< "12: int Exploit\n"
		<< "13: ansi working\n"
		<< "14: ansi Exploit\n"
		<< "Select: ";

	int test;
	cin >> test;

	switch (test)
	{
	case 1:
		arrayWorking();
		break;
	case 2:
		arrayExploit();
		break;
	case 3:
		arcWorking();
		break;
	case 4:
		arcExploit();
		break;
	case 5:
		vtableWorking();
		break;
	case 6:
		vtableExploit();
		break;
	case 7:
		stackWorking();
		break;
	case 8:
		stackExploit();
		break;
	case 9:
		heapWorking();
		break;
	case 10:
		heapExploit();
		break;
	case 11:
		intWorking();
		break;
	case 12:
		intExploit();
		break;
	case 13:
		ansiWorking();
		break;
	case 14:
		ansiExploit();
		break;
	}
	return 0;
}

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(int index)
{
	int array[5];
	bool safe = true;

	array[index] = 0;

	if (safe)
	{
		cout << "Safe! No exploit.\n";
	}
	else
	{
		cout << "Array has been exploited.\n";
	}
}

/**************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void arrayWorking()
{
	int index = 3;
	arrayVulnerability(index);
}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
	int index = 5;
	arrayVulnerability(index);
}

/**************************************
 * ARC VULNERABILITY
 * 1. There must be a function pointer used in the code
 * 2. Through some vulnerability, there must be a way for user input to
 *    overwrite the function pointer. This typically happens through a stack
 *    buffer vulnerability.
 * 3. After the memory is overwritten, the function pointer must be
 *    dereferenced.
 *************************************/
void arcVulnerability(int index)
{
	long buffer[1];
	void (*pointerFunction)() = pFunction;

	cout << "Input a number: ";
	cin >> buffer[index];
	pointerFunction();

}
void arcWorking()
{
	cout << "Safe\n";
	arcVulnerability(0);
}

/**************************************
 * ARC EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing unintended access to
 *    the function pointer
 * 2. The attacker must have the address to another function which is to be
 *    used to replace the existing function pointer.
 *************************************/
void arcExploit()
{
	cout << "Not Safe\n";
	cout << "Here have an address to another function: " << hex << showbase << badFunction << endl;
	arcVulnerability(1);
}
void pFunction()
{
	cout << "Pointer Function was called.\n";
}
void badFunction()
{
	cout << "Will now do bad things.\n";
}

/*************************************
 * V-Table VULNERABILTY
 * 1. The vulnerable class must be polymorphic.
 * 2. The class must have a buffer as a member variable.
 * 3. Through some vulnerability, there must be a way for user input to overwrite parts of the V-Table.
 * 4. After a virtual function pointer is overwritten, the virtual function must	be called.

 ****************************************/
class Vulnerable
{
public:
 virtual void safe() {}; 		// polymorphic functions
 virtual void dangerous() {};
private:
 long buffer[2]; 				// an array in the class that has
}; 								// a buffer overrun vulnerability

class MyVulnerability : public Vulnerable {
	public: 
		void safe() { cout << "Safe Function" << endl; }
		void dangerous() { cout << "Danger Danger" << endl; }
		void setBuffer(long value, int index) { buffer[index] = value; }
	private:
	 long buffer[2];
};

/**************************************
 * V-Table WORKING
 * Call virtual function () in a way that does
 * not yield unexpected behavior
 *************************************/
void vtableWorking() {
	
	MyVulnerability safeObject;
	int index = 0;
	long value = 0;

	cout << "Enter 0 or 1 for the index to modify: ";
	cin  >> index;

	cout << "Enter the value: ";
	cin  >> value;

	if (index >= 0 && index <= 1) {
		safeObject.setBuffer(value, index);
		cout 	<< "Output should be: Safe Function/n"
				<< "Function Output : "; safeObject.safe();
		return;
	}
	else {
		cout << "Buffer overrun, please enter 0 or 1 for the index" << endl;
		return;
	}
}

/**************************************
 * V-Table EXPLOIT
 * 1. Through some vulnerability, the V-Table pointer or a function pointer within the V-Table must be overwritten.
 * 2. The attacker must have the address to another V-Table pointer or a function pointer.
 *************************************/
void vtableExploit() {
	MyVulnerability safeObject;
	int index = 0;
	long value = 0;

	cout << "Enter 0 or 1 for the index to modify: ";
	cin  >> index;

	cout << "Enter the value: ";
	cin  >> value;

	safeObject.setBuffer(value, index);
	cout 	<< "Output should be: Safe Function/n"
			<< "Function Output : "; safeObject.safe();
}

void stackVulnerability(char input[]) {
	istringstream iss(input);
	cin.rdbuf(iss.rdbuf());	
	
	char username[4];
	char pin[] = "1234";

	cin >> username;
	cout << pin;
}
void stackWorking() {
	char input[] = "user";
	stackVulnerability(input);
}
void stackExploit() {
	char input[] = "user5678";
	stackVulnerability(input);
}

/**************************************
 * Heap Spraying
 * For a heap smashing vulnerability to exist in the code, the following must be present:
 * 1. There must be two adjacent heap buffers.
 * 2. The first buffer must be reachable through external input.
 * 3. The mechanism to fill the buffer from the external input must not correctly check for the buffer size.
 * 4. The second buffer must be released before the first.
 * 5. The first buffer must be overrun (extend beyond the intended limits of the array).
 *************************************/
void heapVulnerability(char* buffer1, char* buffer2) {

	delete[] buffer2; // need to delete second buffer first 
	delete[] buffer1;
}
void heapWorking() {

	int numElements = 3;

	char* buffer1 = new char[4]; // requires two buffers on the heap 
	char* buffer2 = new char[4];
	string input;

	cout << "Enter 3 characters: " << endl;
	cout << "buffer Size: " << sizeof(buffer1) << endl;

	cin >> input;

	cout << "sizeof Input: " << input.length() << endl;

	if (input.length() >= 4)
	{
		cout << "Please Enter fewer characters: " << endl;
		return;
	}

	for (int j = 0; j < numElements; j++)
	{
		buffer1[j] = input[j];
	}
	cout << "Buffer 1 input: " << buffer1 << endl;

	heapVulnerability(buffer1, buffer2);
}
void heapExploit() {
	char* buffer1 = new char[4]; // requires two buffers on the heap 
	char* buffer2 = new char[4];

	cout << "Enter 4 or more characters: " << endl;
	cin >> buffer1;

	heapVulnerability(buffer1, buffer2);
}

/**************************************
 * Integer Overflow
 * 1. There must be a security check by an expression
 * 2. The expression must have potential for an overflow
 * 3. One of the numbers used to compute the setinel must be reachable from
 *    external input. This sentinel is a variable used to make the security decision
 *    from the first requirement.
 *************************************/
bool intVulnerability(int offset) {

	int buffer[256];
	int* check = buffer + 256;
	bool safe = true;

	if (offset + buffer < check)
	{
		cin >> buffer[offset];
		safe = false;
	}
	return safe;
}

void intWorking() {

	int offset;
	bool safe;

	offset = 9999999999999999999;

	cout << "Offset max value is 9999999999999999999" << endl;

	safe = intVulnerability(offset);

	if (safe)
	{
		cout << "Safe! No exploit.\n";
	}
	else
	{
		cout << "Integer Overflow!\n";
	}
}

void intExploit() {
	int offset;
	bool safe;

	cout << "Enter Offset: " << endl;

	cin >> offset;

	safe = intVulnerability(offset);

	if (safe)
	{
		cout << "Safe! No exploit.\n";
	}
	else
	{
		cout << "Integer Overflow!\n";
	}
}

void ansiVulnerability(short* unicodeText1, int numElements)
{
	for (int i = 0; i < numElements; i++)
	{
		unicodeText1[i] = 1;
	}

	cout << unicodeText1[numElements - 1] << endl;
	cout << "Number of elements: " << numElements << ". Should be 256." << endl;
	cout << "Element in array index " << (numElements - 1) << " is: " << unicodeText1[numElements - 1] << endl;
}
void ansiVulnerability(char* unicodeText1, int numElements)
{
	for (int i = 0; i < numElements; i++)
	{
		unicodeText1[i] = 'a';
	}

	cout << unicodeText1[numElements - 1] << endl;
	cout << "Number of elements: " << numElements << ". Should be 256." << endl;
	cout << "Element in array index " << (numElements - 1) << " is: " << unicodeText1[numElements - 1] << endl;
}
void ansiWorking()
{
	cout << "Safe\n";
	char unicodeText1[256];

	ansiVulnerability(unicodeText1, sizeof(unicodeText1));
}
void ansiExploit()
{
	cout << "Unsafe\n";
	short unicodeText1[256];

	ansiVulnerability(unicodeText1, sizeof(unicodeText1));
}
