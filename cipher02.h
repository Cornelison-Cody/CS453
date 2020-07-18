/********************************************************************
* Header:
* Checkerboard Cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
	virtual std::string getPseudoAuth() { return "Eric Mott"; }
	virtual std::string getCipherName() { return "Checkerboard"; }
	virtual std::string getEncryptAuth() { return "Benjamin Thaut"; }
	virtual std::string getDecryptAuth() { return "Bradley Dawson"; }

	/***********************************************************
	 * GET CIPHER CITATION
	 * Returns the citation from which we learned about the cipher
	 ***********************************************************/
	virtual std::string getCipherCitation()
	{
		return std::string("citation");
	}

	/**********************************************************
	 * GET PSEUDOCODE
	 * Returns the pseudocode as a string to be used by the caller.
	 **********************************************************/
	virtual std::string getPseudocode()
	{
		std::string str;

		// TODO: please format your pseudocode
		// The encrypt pseudocode
		str = "checkerboardCipher()";
		str = +"string vertKeyword";
		str = +"string horizKeyword";
		str = +"char rowKey[5]";
		str = +"char columnKey[5]";
		str = +"string message";
		str = +"string cipherMessage";

		str = +"char alphabetArray[5][5] = {";
		str = +"{'w', 'c', 'e', 'o', 'v'},";
		str = +"{'x', 'b', 'm', 's', 'f'},";
		str = +"{'h', 'k', 'q', 'r', 'y'},";
		str = +"{'i', 'p', 'z', 'n', 't'},";
		str = +"{'u', 'a', 'd', 'g', 'l'}}";

		str = +"display 'Enter first keyword (5 nonrepeating characters): '";
		str = +"accept vertKeyword";
		str = +"display 'Enter second keyword (5 nonrepeating characters): '";
		str = +"accept horizKeyword";
		str = +"display 'Enter message: '";

		str = +"convert vertKeyword to vertKey";
		str = +"convert horizKeyword to columnKey";

		str = +"loop thru message";
		str = +"loop thru alphabetArray";
		str = +"match message character to alphabetArray character";
		str = +"if message character is 'j' match to alphabetArray character 'i'";
		str = +"if not alpha character then skip";
		str = +"cipherMessage =+ rowKey[alphabetArray row value]";
		str = +"cipherMessage =+ columnKey(alphabetArray column value]";

		str = +"return codedCheckerboard";

		// The decrypt pseudocode
		str += "decodeCheckerboard(codedCheckerboard)";
		str = +"string decodeMessage";
		str = +"loop thru codedCheckerboard";
		str = +"if codedCheckerboard index is even";
		str = +"match codedCheckerboard character to rowKey character";
		str = +"alphabetArrayRow = rowKey index";
		str = +"if codedCheckerboard index is odd";
		str = +"match codedCheckerboard character to columnKey character";
		str = +"alphabetArrayColumn = columnKey index";
		str = +"decodedMessage =+ alphabetArray[alphabetArrayRow][alphabetArrayColumn]";

		str = +"return decodedMessage";

		return str;
	}

	/**********************************************************
	 * ENCRYPT
	 * TODO: ADD description
	 **********************************************************/
	virtual std::string encrypt(const std::string& plainText,
		const std::string& password)
	{
		std::string cipherText = plainText;
		// TODO - Add your code here

		std::string vertKeyword;
		std::string horizKeyword;
		char rowKey[5];
		char colKey[5];
		std::string message;
		std::string cipherMessage = "";

		//CheckerBoard or look up array for encryption
		char alphabetArray[5][5] = {
		 {'w', 'c', 'e', 'o', 'v'},
		 {'x', 'b', 'm', 's', 'f'},
		 {'h', 'k', 'q', 'r', 'y'},
		 {'i', 'p', 'z', 'n', 't'},
		 {'u', 'a', 'd', 'g', 'l'} };

		//This key is used for encrypting each row with the letters input
		std::cout << "Enter first keyword (5 nonrepeating characters): ";
		std::cin >> vertKeyword;

		//This key is used for encrypting each column with the letters input
		std::cout << "Enter second keyword (5 nonrepeating characters): ";
		std::cin >> horizKeyword;

		//plainText was already grabbed from the user
		message = plainText;

		//all input must be lowercase
		for (int i = 0; i < vertKeyword.length(); i++)
		{
			vertKeyword[i] = tolower(vertKeyword[i]);
		}

		//all input must be lowercase
		for (int i = 0; i < horizKeyword.length(); i++)
		{
			horizKeyword[i] = tolower(horizKeyword[i]);
		}

		//all input must be lowercase
		for (int i = 0; i < message.length(); i++)
		{
			message[i] = tolower(message[i]);
		}

		//set the row and column keys input by the user
		for (int i = 0; i < 5; i++)
		{
			rowKey[i] = vertKeyword[i];
			colKey[i] = horizKeyword[i];
		}

		//This encrypts the message so we must loop through that message
		for (int i = 0; i < message.length(); i++)
		{
			//To encrypt each letter we must loop through the 2 dimensinal alphabetArray 'x' represents each row
			for (int x = 0; x < 5; x++)
			{
				//To encrypt each letter we must loop through the 2 dimensional alphabetArray, 'j' represents each column
				for (int j = 0; j < 5; j++)
				{
					//When a letter in message is found in alphabetArray encypt that letter by adding the letter that represents
					//that row and the letter that represents that column to cipherMessage
					if (message[i] == alphabetArray[x][j])
					{
						cipherMessage += rowKey[x];
						cipherMessage += colKey[j];
					}
					//There is no 'j' in alphabetArray so we must look for 'i' instead, this must be taken into account for decryption
					//as well
					if (message[i] == 'j' && alphabetArray[x][j] == 'i')
					{
						cipherMessage += rowKey[x];
						cipherMessage += colKey[j];
					}
				}
			}
			//To not confuse letters add a space between every two added to cipherMessage unless its the end of the message
			if (i < (message.length() - 1))
			{
				cipherMessage += ' ';
			}
		}

		cipherText = cipherMessage;

		return cipherText;
	}

	/**********************************************************
	 * DECRYPT
	 * TODO: ADD description
	 **********************************************************/
	virtual std::string decrypt(const std::string& cipherText,
		const std::string& password)
	{
		std::string vertKeyword;
		std::string horizKeyword;
		std::string plainText = "";

		//CheckerBoard or look up array for encryption
		char alphabetArray[5][5] = {
		 {'w', 'c', 'e', 'o', 'v'},
		 {'x', 'b', 'm', 's', 'f'},
		 {'h', 'k', 'q', 'r', 'y'},
		 {'i', 'p', 'z', 'n', 't'},
		 {'u', 'a', 'd', 'g', 'l'} };

		//This key is used for encrypting each row with the letters input
		std::cout << "Enter first keyword (5 nonrepeating characters): ";
		std::cin >> vertKeyword;

		//This key is used for encrypting each column with the letters input
		std::cout << "Enter second keyword (5 nonrepeating characters): ";
		std::cin >> horizKeyword;

		for (int i = 0; i < cipherText.length() - 1; i++)
		{
			// get the rowKeys from the ciphertext
			char columnChar = cipherText[i++];
			char rowChar = cipherText[i++];

			int columnIndex = 0;
			int rowIndex = 0;
			// match the keys with the index of the keywords
			for (int j = 0; j < vertKeyword.length(); j++)
			{
				if (columnChar == vertKeyword[j])
				{
					columnIndex = j;
					break;
				}
			}
			for (int j = 0; j < horizKeyword.length(); j++)
			{
				if (rowChar == horizKeyword[j])
				{
					rowIndex = j;
					break;
				}
			}

			plainText += alphabetArray[columnIndex][rowIndex];
		}

		// TODO - Add your code here
		return plainText;
	}
};

#endif // CIPHER02_H