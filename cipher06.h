/********************************************************************
* Header: RAGBABY CIPHER
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher 
{
public:
   virtual std::string getPseudoAuth()  { return "Cody Cornelison"; }
   virtual std::string getCipherName()  { return "Ragbaby Cipher"; }
   virtual std::string getEncryptAuth() { return "James Clarke"; }
   virtual std::string getDecryptAuth() { return "Jason Steffen"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.cryptogram.org/downloads/aca.info/ciphers/Ragbaby.pdf and http://www.dickason.com/caching/OHMIKYragbaby.html");
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
      str += "    string alphabet <- generateAlphabet(password)\n";
      str += "    int wordCount = 1\n";
      str += "    int charCount = 1\n";
      str += "    FOR c is all chars in plainText\n";
      str += "        IF c is a space\n";
      str += "            wordCount++\n";
      str += "            charCount = wordCount % alphabet.length()\n";
      str += "            encryptedText[c] = space\n";
      str += "        ELSE \n";
      str += "        offsetArray[c] = charCount++ % alphabet.length()\n";
      str += "        encryptedText[c] = alphabet[(alpabet.find(c) + offsetArray[c]) % alphabet.length()]\n";
      str += "    RETURN encryptedText\n\n";

      // The decrypt pseudocode
      str += "decrypt(plainText, password)\n";
      str += "    string alphabet <- generateAlphabet(password)\n";
      str += "    int wordCount = 1\n";
      str += "    int charCount = 1\n";
      str += "    FOR c is all chars in plainText\n";
      str += "        IF c is a space\n";
      str += "            wordCount++\n";
      str += "            charCount = wordCount % alphabet.length()\n";
      str += "            decryptedText[c] = space\n";
      str += "        ELSE \n";
      str += "        offsetArray[c] = charCount++ % alphabet.length()\n";
      str += "        decryptedText[c] = alphabet[(alphabet.length() + alpabet.find(c) - offsetArray[c]) % alphabet.length()]\n";
      str += "    RETURN decryptedText\n\n";

      // Generate Alphabet function
      str +=  "generateAlphabet(password)\n";
      str += "    FOR p is all values of password\n";
      str += "        store upper case p in a std::set alphabet to remove duplicates\n";
      str += "        if p is a - j then add corresponding number to alphabet\n";
      str += "    FOR c is A - Z and 0 - 9\n";
      str += "        add to alphabet as well\n";
      str += "    RETURN alphabet\n\n";
      

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      
      string alphabet = generateAlphabet(password);
      int wordCount = 1;
      int charCount = 1;
      int offsetArray[36];
      int letterLocation = 0;

      for ( int i = 0; i < plainText.length(); i++) {
          if (plainText[i] == ' ') {
              wordCount++;
              charCount = wordCount % alphabet.length();
              cipherText += ' ';
          }
          else {
              letterLocation = alphabet.find(toupper(plainText[i]));
              offsetArray[i] = charCount++ % alphabet.length();
              cipherText += alphabet[(letterLocation + offsetArray[i]) % alphabet.length()];
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
      
      string alphabet = generateAlphabet(password);
      int wordCount = 1;
      int charCount = 1;
      int offsetArray[36];
      int letterLocation = 0;

      for ( int i = 0; i < cipherText.length(); i++) {
          if (cipherText[i] == ' ') {
              wordCount++;
              charCount = wordCount % alphabet.length();
              plainText += ' ';
          }
          else {
              letterLocation = alphabet.find(toupper(cipherText[i]));
              offsetArray[i] = charCount++ % alphabet.length();
              plainText += alphabet[(letterLocation - offsetArray[i]) % alphabet.length()];
          }
      }
      
      return plainText;
   }

   /**********************************************************
 * Generate Alphabet
 * TODO: ADD description
 **********************************************************/
   string generateAlphabet(string password)
   {
      string fullalphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      string key = password + fullalphabet;
      string alphabet = "";
      set <char> usedLetters;

      vector <char> p;

       for (string::size_type i = 0; i < key.length(); ++i)
             alphabet +=  toupper(key[i]);
           
       for (string::size_type j = 0; j < alphabet.length(); ++j) {

           switch (alphabet[j])
           {
               case 'A':
                  if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                     p.push_back(alphabet[j]);
                     p.push_back('1');
                     usedLetters.insert(alphabet[j]);
                  }
                  break;
               case 'B':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('2');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'C':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('3');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'D':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('4');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'E':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('5');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'F':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('6');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'G':
				   if (usedLetters.find(alphabet[j]) == usedLetters.end())
				   {
					   p.push_back(alphabet[j]);
					   p.push_back('7');
					   usedLetters.insert(alphabet[j]);
				   }
				   break;

               case 'H':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('8');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'I':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('9');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;

               case 'J':
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   p.push_back('0');
                   usedLetters.insert(alphabet[j]);
                  }
                   break;
               case ' ':
                  break;
               default:
                   if(usedLetters.find(alphabet[j]) == usedLetters.end()) {
                   p.push_back(alphabet[j]);
                   usedLetters.insert(alphabet[j]);
                  }
            }
           
       }

       alphabet = "";

       for (char k : p) {
           alphabet += k;
     }

       return alphabet;
   }      
   
};

#endif // CIPHER06_H