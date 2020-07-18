/********************************************************************
* Header:
* Vigenère cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <string>
#include <map>


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jason Steffen"; }
   virtual std::string getCipherName()  { return "Vigenere-cipher"; }
   virtual std::string getEncryptAuth() { return "Eric Mott"; }
   virtual std::string getDecryptAuth() { return "Cody Cornelison"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.geeksforgeeks.org/vigenere-cipher/ - Written by Ayush Khanduri. - Retrieved on 07/15/2020");
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
      str =  "";
      str += "string plaintext;\n";
      str += "string password;\n";
      str += "string cipher;\n";
      
      str += "cin >> password;\n";
      str += "cin >> plaintext;\n";

      str += "char cipherColumn[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}\n";

      str += "char aArray[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}\n";
      str += "char bArray[] = {b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a}\n";
      str += "char cArray[] = {c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b}\n";
      str += "...\n";
      str += "//THE REST OF THE ARRAYS GO HERE\n";
      str += "...\n";
      str += "char zArray[] = {z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y}\n";

      str += "int passwordIterator = 0;\n";

      str += "//Iterate through the plaintext message\n";
      str += "for int i = 0; plaintext[i]; i++\n";
      str += "{\n";
      str += "   char plaintextLetter = plaintext[i]\n";
      str += "   int plaintextNumber = -1;\n";
      str += "   char passwordLetter = password[passwordIterator]\n";

      str += "   //Find the column number of the cipher\n";
      str += "   SWITCH statement\n";
      str += "   char plaintextLetter = a\n";
      str += "      plaintextNumber = 0;\n";
      str += "      break;\n";
      str += "   char plaintextLetter = b\n";
      str += "      plaintextNumber = 1;\n";
      str += "      break;\n";
      str += "   //...MORE SWITCH STATEMENTS\n";
      str += "   char plaintextLetter = z\n";
      str += "      plaintextNumber = 25\n";
      str += "      break;\n";

      str += "   //Any character that is not a-z will be the placeholder\n";
      str += "   if plaintextNumber = -1\n";
      str += "      cipher[i] = 0 or any other placeholder\n";

      str += "   //Find the row of the cipher and set the cipher's letter\n";
      str += "   SWITCH statement\n";
      str += "   char password[passwordIterator] = a\n";
      str += "      cipher[i] = aArray[plaintextNumber];\n";
      str += "      break;\n";
      str += "   char password[passwordIterator] = b\n";
      str += "      cipher[i] = bArray[plaintextNumber];\n";
      str += "      break;\n";
      str += "   //...MORE SWITCH STATEMENTS\n";
      str += "   char password[passwordIterator] = z\n";
      str += "      cipher[i] = zArray[plaintextNumber];\n";
      str += "      break;\n";

      str += "      //If we have gone through the password, start over.\n";
      str += "   if password[!passwordIterator++]\n";
      str += "     passwordIterator = 0;\n";
      str += "   else passwordIterator++;\n";
      str += "}\n";

      str += "   cout << cipher;\n";
      
      

      // The decrypt pseudocode
      str += "\n";
      str += "string plaintext;\n";
      str += "string password;\n";
      str += "string cipher;\n";
      
      str += "cin >> password;\n";
      str += "cin >> cipher;\n";

      str += "char plaintextColumn[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}\n";

      str += "char aArray[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}\n";
      str += "char bArray[] = {b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a}\n";
      str += "char cArray[] = {c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b}\n";
      str += "...\n";
      str += "//THE REST OF THE ARRAYS GO HERE\n";
      str += "...\n";
      str += "char zArray[] = {z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y}\n";

      str += "int passwordIterator = 0;\n";

      str += "//Iterate through the cipher message\n";
      str += "for int i = 0; cipher[i]; i++\n";
      str += "{\n";
      str += "   char cipherLetter = cipher[i]\n";
      str += "   int cipherNumber = -1;\n";
      str += "   char passwordLetter = password[passwordIterator]\n";

      str += "   //Find the column number of the cipher\n";
      str += "   SWITCH statement\n";
      str += "   char cipherLetter = a\n";
      str += "      cipherNumber = 0;\n";
      str += "      break;\n";
      str += "   char cipherLetter = b\n";
      str += "      cipherNumber = 1;\n";
      str += "      break;\n";
      str += "   //...MORE SWITCH STATEMENTS\n";
      str += "   char cipherLetter = z\n";
      str += "      cipherNumber = 25\n";
      str += "      break;\n";

      str += "   //Any character that is not a-z will be the placeholder\n";
      str += "   if cipherNumber = -1\n";
      str += "      plaintext[i] = 0 or any other placeholder\n";

      str += "   //Find the row of the plaintext and set the plaintext's letter\n";
      str += "   SWITCH statement\n";
      str += "   char password[passwordIterator] = a\n";
      str += "      plaintext[i] = aArray[cipherNumber];\n";
      str += "      break;\n";
      str += "   char password[passwordIterator] = b\n";
      str += "      plaintext[i] = bArray[cipherNumber];\n";
      str += "      break;\n";
      str += "   //...MORE SWITCH STATEMENTS\n";
      str += "   char password[passwordIterator] = z\n";
      str += "      plaintext[i] = zArray[cipherNumber];\n";
      str += "      break;\n";

      str += "   //If we have gone through the password, start over.\n";
      str += "   if password[!passwordIterator++]\n";
      str += "     passwordIterator = 0;\n";
      str += "   else passwordIterator++;\n";

      str += "}\n";

      str += "   cout << plaintext;\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = onlyLetters(plainText);
      // TODO - Add your code here
	  std::string cipherPassword = onlyLetters(password);
	  string cleanPassword = onlyLetters(password);


	  // build encoding array
	  char cipherColumn[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	  char aArray[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	  char bArray[] = { 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a' };
	  char cArray[] = { 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b' };
	  char dArray[] = { 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c' };
	  char eArray[] = { 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd' };
	  char fArray[] = { 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e' };
	  char gArray[] = { 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f' };
	  char hArray[] = { 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
	  char iArray[] = { 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	  char jArray[] = { 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
	  char kArray[] = { 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	  char lArray[] = { 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' };
	  char mArray[] = { 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' };
	  char nArray[] = { 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm' };
	  char oArray[] = { 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n' };
	  char pArray[] = { 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o' };
	  char qArray[] = { 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p' };
	  char rArray[] = { 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q' };
	  char sArray[] = { 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r' };
	  char tArray[] = { 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's' };
	  char uArray[] = { 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't' };
	  char vArray[] = { 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u' };
	  char wArray[] = { 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v' };
	  char xArray[] = { 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w' };
	  char yArray[] = { 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x' };
	  char zArray[] = { 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' };

	  int passwordIterator = 0;

	  // loop thru and convert the message
	  for (int i = 0; cipherText[i]; i++)
	  {
		  char cipherLetter = cipherText[i];
		  int cipherNumber = -1;
		  int cipherLetterNumber = -1;
		  int passwordLetterNumber = -1;
		  char passwordLetter = cleanPassword[passwordIterator];

		  if (isalpha(cipherText[i])) {
			  cipherLetter = tolower(cipherText[i]);
		  }

		  // find column number
		  switch (cipherLetter) {
		  case 97:
			  cipherNumber = 0;
			  break;
		  case 98:
			  cipherNumber = 1;
			  break;
		  case 99:
			  cipherNumber = 2;
			  break;
		  case 100:
			  cipherNumber = 3;
			  break;
		  case 101:
			  cipherNumber = 4;
			  break;
		  case 102:
			  cipherNumber = 5;
			  break;
		  case 103:
			  cipherNumber = 6;
			  break;
		  case 104:
			  cipherNumber = 7;
			  break;
		  case 105:
			  cipherNumber = 8;
			  break;
		  case 106:
			  cipherNumber = 9;
			  break;
		  case 107:
			  cipherNumber = 10;
			  break;
		  case 108:
			  cipherNumber = 11;
			  break;
		  case 109:
			  cipherNumber = 12;
			  break;
		  case 110:
			  cipherNumber = 13;
			  break;
		  case 111:
			  cipherNumber = 14;
			  break;
		  case 112:
			  cipherNumber = 15;
			  break;
		  case 113:
			  cipherNumber = 16;
			  break;
		  case 114:
			  cipherNumber = 17;
			  break;
		  case 115:
			  cipherNumber = 18;
			  break;
		  case 116:
			  cipherNumber = 19;
			  break;
		  case 117:
			  cipherNumber = 20;
			  break;
		  case 118:
			  cipherNumber = 21;
			  break;
		  case 119:
			  cipherNumber = 22;
			  break;
		  case 120:
			  cipherNumber = 23;
			  break;
		  case 121:
			  cipherNumber = 24;
			  break;
		  case 122:
			  cipherNumber = 25;
			  break;
		  }

		  if (cipherNumber == -1)
		  {
			  cipherText[i] = '0';
		  }

		  // find the row of the plaintext and set the ciphertext's letter
		  if (isalpha(cleanPassword[passwordIterator])) {
			  cipherPassword[passwordIterator] = tolower(cleanPassword[passwordIterator]);
		  }

		  if (cipherNumber != -1)
		  {
			  switch (cipherPassword[passwordIterator]) {
			  case 97:
				  cipherText[i] = aArray[cipherNumber];
				  break;
			  case 98:
				  cipherText[i] = bArray[cipherNumber];
				  break;
			  case 99:
				  cipherText[i] = cArray[cipherNumber];
				  break;
			  case 100:
				  cipherText[i] = dArray[cipherNumber];
				  break;
			  case 101:
				  cipherText[i] = eArray[cipherNumber];
				  break;
			  case 102:
				  cipherText[i] = fArray[cipherNumber];
				  break;
			  case 103:
				  cipherText[i] = gArray[cipherNumber];
				  break;
			  case 104:
				  cipherText[i] = hArray[cipherNumber];
				  break;
			  case 105:
				  cipherText[i] = iArray[cipherNumber];
				  break;
			  case 106:
				  cipherText[i] = jArray[cipherNumber];
				  break;
			  case 107:
				  cipherText[i] = kArray[cipherNumber];
				  break;
			  case 108:
				  cipherText[i] = lArray[cipherNumber];
				  break;
			  case 109:
				  cipherText[i] = mArray[cipherNumber];
				  break;
			  case 110:
				  cipherText[i] = nArray[cipherNumber];
				  break;
			  case 111:
				  cipherText[i] = oArray[cipherNumber];
				  break;
			  case 112:
				  cipherText[i] = pArray[cipherNumber];
				  break;
			  case 113:
				  cipherText[i] = qArray[cipherNumber];
				  break;
			  case 114:
				  cipherText[i] = rArray[cipherNumber];
				  break;
			  case 115:
				  cipherText[i] = sArray[cipherNumber];
				  break;
			  case 116:
				  cipherText[i] = tArray[cipherNumber];
				  break;
			  case 117:
				  cipherText[i] = uArray[cipherNumber];
				  break;
			  case 118:
				  cipherText[i] = vArray[cipherNumber];
				  break;
			  case 119:
				  cipherText[i] = wArray[cipherNumber];
				  break;
			  case 120:
				  cipherText[i] = xArray[cipherNumber];
				  break;
			  case 121:
				  cipherText[i] = yArray[cipherNumber];
				  break;
			  case 122:
				  cipherText[i] = zArray[cipherNumber];
				  break;
			  }
		  }
		  

		  // if thru password start password over
		  if (!cleanPassword[passwordIterator + 1])
		  {
			  passwordIterator = 0;
		  }
		  else
		  {
			  passwordIterator++;
		  }

	  }
	  return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
		int passwordIterator = 0;
		string cleanPassword = onlyLetters(password);

	  	// build encoding array
	  char fullAlphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	  // get location of ciphered letter
	  for (int i = 0; i < cipherText.length(); i++) {
		  	plainText += fullAlphabet[(26 + cipherText[i] - cleanPassword[passwordIterator++]) % 26]; 
			passwordIterator = passwordIterator % cleanPassword.length();
	  } 

      return plainText;
   }

	/**********************************************************
	 * ONLYLETTERS
	 * TODO: ADD description
	 *       This cipher only allows letters to be used. All
	 *       other text is dropped. 
	 **********************************************************/

	std::string onlyLetters(std::string str) {
		std::string cleanString = "";

		for (char& c : str) {
			if (isalpha(c)) {
				cleanString += tolower(c);
			}
		}

		return cleanString;
	}
};

#endif // CIPHER05_H