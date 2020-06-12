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

void heapVulnerability();
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

void vtableVulnerability() {}
void vtableWorking() {}
void vtableExploit() {}

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

void heapVulnerability() {}
void heapWorking() {}
void heapExploit() {}

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

void ansiVulnerability() {}
void ansiWorking() {}
void ansiExploit() {}