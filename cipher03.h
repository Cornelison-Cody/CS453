/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <string>
#include <iostream>
#include <map>
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03: public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Bradley Dawson"; }
   virtual std::string getCipherName()  { return "Baconian Cipher"; }
   virtual std::string getEncryptAuth() { return "Jason Steffen"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Cryptogram.org, ";
      s += "\"BACONIAN 25 letter plaintext cipher\', \n   retrieved: ";
      s += "https://www.cryptogram.org/downloads/aca.info/ciphers/Baconian.pdf";
      return s;
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
      str =  "encrypt(plainText, password)\n";
      str += "   key <- generateKey(letter1, letter2)\n";
      str += "   FOR p in all values of plaintext\n";
      str += "      cipherText += key[p]\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str +=  "decrypt(cipherText, password)\n";
      str += "   key <- generateKey(letter1, letter2)\n";
      str += "   FOR p in all values of cipherText\n";
      str += "      FOR i in all elements of cipherText\n";
      str += "         IF key[i] EQUALS p\n";
      str += "            plainText += key[i]";
      str += "   RETURN plainText\n\n";

      // geterate key
      str += "generateKey(password)\n";
      str += "   a <- password[0]\n";
      str += "   b <- password[1]\n";
      str += "   key = {\n";
      str += "      A : aaaaa, b : aaaab,\n";
      str += "      C : aaaba, d : aaabb,\n";
      str += "      E : aabaa, F : aabab,\n";
      str += "      G : aabba, H : aabbb,\n";
      str += "      I : abaaa, J : abaaa,\n";
      str += "      K : abaab, L : ababa,\n";
      str += "      M : ababb, N : abbaa,\n";
      str += "      O : abbab, P : abbba,\n";
      str += "      Q : abbbb, R : baaaa,\n";
      str += "      S : baaab, T : baaba,\n";
      str += "      U : baabb, V : baabb,\n";
      str += "      W : babaa, X : babab,\n";
      str += "      Y : babba, Z : babbb,\n";
      str += "   }\n";
      str += "   RETURN key\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      
      //FC and SC stand for first character and second character.
      char FC = tolower(password[0]);
      char SC = tolower(password[1]);
      std::string codedMessage = "";

      for (int i = 0; cipherText[i]; i++)
      {
         if (isalpha(cipherText[i])) 
			  tolower(cipherText[i]);
		  

         switch (cipherText[i]) 
         {
		   case 'a':
			  codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += FC;
			  break;
         
         case 'b':
           codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += SC;
			  break;
         

         case 'c':
           codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'd':
			  codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += SC;
			  break;  

         case 'e':
			  codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += FC;
			  break;

         case 'f':
			  codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += SC;
			  break;

         case 'g':
			  codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'h':
			  codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += SC;
			  break;

         case 'i':
			  codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += FC;
			  break;

         case 'j':
			  codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += FC;
			  break;

         case 'k':
			  codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += SC;
			  break;

         case 'l':
			  codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'm':
			  codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += SC;
			  break;

         case 'n':
			  codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += FC; codedMessage += FC;
			  break;

         case 'o':
			  codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += FC; codedMessage += SC;
			  break;

         case 'p':
			  codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'q':
			  codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += SC; codedMessage += SC;
			  break;

         case 'r':
			  codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += FC;
			  break;

         case 's':
			  codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += FC; codedMessage += SC;
			  break;

         case 't':
			  codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'u':
			  codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += SC;
			  break;

         case 'v':
			  codedMessage += SC; codedMessage += FC; codedMessage += FC; codedMessage += SC; codedMessage += SC;
			  break;

         case 'w':
			  codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += FC;
			  break;

         case 'x':
			  codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += FC; codedMessage += SC;
			  break;

         case 'y':
			  codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += FC;
			  break;

         case 'z':
			  codedMessage += SC; codedMessage += FC; codedMessage += SC; codedMessage += SC; codedMessage += SC;
			  break;
         }

      }
      cipherText = codedMessage;
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
       std::string plainText = cipherText;
       // TODO - Add your code here

       plainText = "";
       std::map<std::string, char> key;
       char a = tolower(password[0]);
       char b = tolower(password[1]);

       std::string code = "";

       code = a;
       code += a;
       code += a;
       code += a;
       code += a;

       key[code] = 'A';

       code = a;
       code += a;
       code += a;
       code += a;
       code += b;

       key[code] = 'B';

       code = a;
       code += a;
       code += a;
       code += b;
       code += a;

       key[code] = 'C';

       code = a;
       code += a;
       code += a;
       code += b;
       code += b;

       key[code] = 'D';

       code = a;
       code += a;
       code += b;
       code += a;
       code += a;

       key[code] = 'E';

       code = a;
       code += a;
       code += b;
       code += a;
       code += b;

       key[code] = 'F';

       code = a;
       code += a;
       code += b;
       code += b;
       code += a;

       key[code] = 'G';

       code = a;
       code += a;
       code += b;
       code += b;
       code += b;

       key[code] = 'H';

       code = a;
       code += b;
       code += a;
       code += a;
       code += a;

       key[code] = 'I';

       code = a;
       code += b;
       code += a;
       code += a;
       code += b;

       key[code] = 'J';

       code = a;
       code += b;
       code += a;
       code += b;
       code += a;

       key[code] = 'K';

       code = a;
       code += b;
       code += a;
       code += b;
       code += b;

       key[code] = 'L';

       code = a;
       code += b;
       code += b;
       code += a;
       code += a;

       key[code] = 'M';

       code = a;
       code += b;
       code += b;
       code += a;
       code += b;

       key[code] = 'N';

       code = a;
       code += b;
       code += b;
       code += b;
       code += a;

       key[code] = 'O';

       code = a;
       code += b;
       code += b;
       code += b;
       code += b;

       key[code] = 'P';

       code = b;
       code += a;
       code += a;
       code += a;
       code += a;

       key[code] = 'Q';

       code = b;
       code += a;
       code += a;
       code += a;
       code += b;

       key[code] = 'R';

       code = b;
       code += a;
       code += a;
       code += b;
       code += a;

       key[code] = 'S';

       code = b;
       code += a;
       code += a;
       code += b;
       code += b;

       key[code] = 'T';

       code = b;
       code += a;
       code += b;
       code += a;
       code += a;

       key[code] = 'U';

       code = b;
       code += a;
       code += b;
       code += a;
       code += b;

       key[code] = 'V';

       code = b;
       code += a;
       code += b;
       code += b;
       code += a;

       key[code] = 'W';

       code = b;
       code += a;
       code += b;
       code += b;
       code += b;

       key[code] = 'X';

       code = b;
       code += b;
       code += a;
       code += a;
       code += a;

       key[code] = 'Y';

       code = b;
       code += b;
       code += a;
       code += a;
       code += b;

       key[code] = 'Z';

       int count = 1;
       code = "";

       for (int i = 0; i < cipherText.length(); i++)
       {
           code += cipherText[i];

           if (count == 5)
           {
               plainText += key.find(code)->second;
               code = "";
               count = 0;
           }
           count++;
       }

       return plainText;
   }
};

#endif // CIPHER03_H