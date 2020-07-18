/********************************************************************
* Header: NUMBERED KEY CIPHER
*    To construct a numbered key cipher start with a key word, phrase, sentence, or
*    paragraph, extend it by appending any missing letters in alphabetical order, then
*    number the resulting extended key. Each plaintext letter is then encrypted by one of
*    the numbers in the key.
*    Key: "I like ciphers."
*    Extended key: i l i k e c i p h e r s a b d f g j m n o q t u v w x y z
*    Numbered key:
*    00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21
*     i  l  i  k  e  c  i  p  h  e  r  s  a  b  d  f  g  j  m  n  o  q
*    22 23 24 25 26 27 28
*     t  u  v  w  x  y  z 
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include <set>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

const std::string FULLALPHABET = "abcdefghijklmnopqrstuvwxyz";

/********************************************************************
 * STRUCT TO HOLD KEY TYPE
 *******************************************************************/
struct cipherKeyItem {
   vector <int> numberedKey;
   int currentKey;

   string getKey() {
      string key = to_string(numberedKey[currentKey]);

      currentKey = (currentKey + 1) % numberedKey.size();

      return key;
   }

   void addKey(int key) {
      numberedKey.push_back(key);
   }
};


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "James Clarke"; }
   virtual std::string getCipherName()  { return "Numbered Key Cipher"; }
   virtual std::string getEncryptAuth() { return "Cody Cornelison"; }
   virtual std::string getDecryptAuth() { return "Eric Mott"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.cryptogram.org/downloads/aca.info/ciphers/NumberedKey.pdf");
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

      str =  "START\n";
      str += "STRING key\n";
      str += "STRING message\n";
      str += "INT freqLetter\n";
      str += "CHAR numKey[key.length][freqLetter]\n";
      str += "INT num\n";
      str += "INT crpytText[message.length]\n";
      str += "DISPLAY Please enter key, letters only\n";
      str += "INPUT key\n";
      str += "DISPLAY Please enter message, letters only\n";
      str += "INPUT message\n";
      str += "FOR key.legnth\n";
      str += "READ key\n";
      str += "INSERT missing letters to end of STRING key in alphabetical order\n";
      str += "END FOR\n";
      str += "FOR key.length\n";
      str += "READ key FIND letters posistion in string\n";
      str += "INCREMENT freqLetter most used letter\n";
      str += "END FOR\n";
      str += "FOR key.length\n";
      str += "SET num = READ key to FIND letters posistion in string\n";
      str += "SET numKey[i][0] = key.pos[i]\n";
      str += "IF key.position == same letter\n";
      str += "SET  numKey[letter][++num] = position number\n";
      str += "ELSE n SET numKey[letter][num]\n";
      str += "END FOR \n";
      str += "FOR message.length\n";
      str += "READ message \n";
      str += "FIND numKey[letter][0]\n";
      str += "GET numKey[letter][num]\n";
      str += "SET cryptText[i]\n";
      str += "END FOR\n";
      str += "DISPLAY cryptText\n";
      str += "END\n";

      // The decrypt pseudocode
  

      str += "START Dycrpt\n";
      str += "STRING key\n";
      str += "STRING message\n";
      str += "INT freqLetter\n";
      str += "CHAR numKey[key.length][freqLetter]\n";
      str += "INT num\n INT crpytText[]\n";
      str += "DISPLAY Please enter key, letters only\n";
      str += "INPUT key\n FOR each number until user presses Q\n";
      str += "DISPLAY Please enter the Cryptext, numbers only\n";
      str += "INPUT cryptText[i]\n END FOR\n";
      str += "FOR key.legnth\n";
      str += "READ key\n";
      str += "INSERT missing letters to end of STRING key in alphabetical order\n";
      str += "END FOR\n";
      str += "FOR key.length\n";
      str += "READ key FIND letters posistion in string\n";
      str += "INCREMENT freqLetter most used letter\n";
      str += "END FOR\n";
      str += "FOR key.length\n";
      str += "SET num = READ key to FIND letters posistion in string\n";
      str += "SET numKey[i][0] = key.pos[i]\n";
      str += "IF key.position == same letter\n";
      str += "SET  numKey[letter][++num] = position number\n";
      str += "ELSE\n SET numKey[letter][num]\n";
      str += "END FOR\n";
      str += "FOR cryptText.length\n";
      str += "READ cryptText FIND numKey[i][number]\n";
      str += "SET message[i] = numKey[letter][number]\n";
      str += "END FOR\n";
      str += "DISPLAY message\n";
      str += "END\n";
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
      string key = createKey(password);
      map <char, cipherKeyItem> cipher;
      int numberCipherValue = 0;

      for (char a : FULLALPHABET) {
         cipher.insert({a, cipherKeyItem()});
      }

      for (char c : key) {
         cipher[c].addKey(numberCipherValue++);
      }

      for (char c : onlyLetters(plainText)) {
         if (cipherText.length() > 0 ) {
            cipherText += " ";
         }
         cipherText += cipher[c].getKey();
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
      string newCipherText = cipherText;
      newCipherText += " ";
      string key = createKey(password);
      vector <char> tempString;
      string number = "";
      vector <int> indexes;

      for (char c : newCipherText) {
         if (c != ' ') {
            tempString.push_back(c);
         }
         else {
            for (char d : tempString) {
               number += d;
            }
            indexes.push_back(stoi(number));
            tempString.clear();
            number = "";
         }
      }

      for (int i : indexes) {
         plainText += key[i];
      }

      return plainText;
   }

   /**********************************************************
    * CREATEKEY
    * TODO: Creates the cipher key by inserting the letters of
    *       the password into the key then adding all remaining
    *       letters to the key. Each letter is assigned a 
    *       numerical value for it's index. 
    **********************************************************/
   string createKey(string password) {
      std::string justLetters = onlyLetters(password);
      std::set <char> usedLetters;

      std::vector<char> keyVector;
      std::string key = "";

      for (char c : justLetters) {
         keyVector.push_back(c);
         usedLetters.insert(c);
      }

      for (char c : FULLALPHABET) {
         if(usedLetters.find(c) == usedLetters.end()) {
            keyVector.push_back(c);
         }
      }

      for (char c : keyVector) {
         key += c;
      }

      return key;
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

#endif // CIPHER01_H