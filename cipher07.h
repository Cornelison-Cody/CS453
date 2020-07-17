/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H
#include <vector>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Benjamin Thaut"; }
   virtual std::string getCipherName()  { return "One-Time Pad"; }
   virtual std::string getEncryptAuth() { return "Bradley Dawson"; }
   virtual std::string getDecryptAuth() { return "James Clarke"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
       std::string s;
       s += "The laws of Cryptography: Perfect Cryptograph: The One-Time Pad\n";
       s += "by Neal R. Wagner (2002)\n";
       s += "http://www.cs.utsa.edu/~wagner/laws/pad.html";
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
      str =  "insert the encryption pseudocode\n";
      str += "Get the plaintext\n";
      str += "Plaintext must have no spaces, only letters, and shifted to all caps\n";
      str += "Generate a random number for each character of the plain text from 0 - 25\n";
      str += "Save these numbers in a vector\n";
      str += "This vector of random numbers is the password\n";
      str += "Output this number to the screen so the user will have it for the decryption\n";
      str += "First number in the vector shifts the first letter in the plaintext forward (or loops if the letter would exceed Z)\n";
      str += "Do this one at a time for each letter with each number in the vector\n";
      str += "When this is finished you have the ciphertext\n";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";
      str += "Pass the ciphertext to this function\n";
      str += "Ask the user for each individual number key for each letter\n";
      str += "This represents the password and should be a new vector containing the same numbers in the password vector\n";
      str += "Loop through the new number key vector and the ciphertext and shift the characters of the ciphertext back by the numbers in the vector one by one\n";
      str += "Decryption is finished, display the plaintext\n";


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
      std::string pswd = password;
      //convert to uppercase
      for (int i = 0; i < cipherText.length(); i++)
      {
         cipherText[i] = toupper(cipherText[i]);
      }
      //convert password to uppercase
      for (int i = 0; i < pswd.length(); i++)
      {
         pswd[i] = toupper(pswd[i]);
      }
      
      //add the password to the plaintext
      for (int i = 0; i < cipherText.length() && i < pswd.length(); i++)
      {
         // add the original plaintext to the password key
         // mod 26 will give us the correct letter from 0 - 26
         // and handle looping past Z
         // so add 65 to get back to the correct ascii range
         cipherText[i] = (((cipherText[i]) + (pswd[i])) % 26) + 65;
      }

      // TODO - Add your code here
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
       const std::string& password)
   {
       // insert the decryption pseudocode
       // Pass the ciphertext to this function
       std::string plainText = "";
       std::string pswd = password;
       vector <int> numKey;
       int input;

       // Ask the user for each individual number key for each letter  
       // This represents the password and should be a new vector containing the same numbers in the password vector  

       for (int i = 0; i < pswd.length(); i++){
           pswd[i] = toupper(pswd[i]);
       }

       for (int i = 0; i < pswd.length(); i++){
            cout << "Enter Number " << i+1 << " key: "  << endl;
            numKey.push_back(input);
            cin >> input;
       }

      // Loop through the new number key vector and the ciphertext and shift the characters of the ciphertext back by the numbers in the vector one by one
      // Decryption is finished, display the plaintext
       for (char k : numKey) {

           //plainText[k] = cipherText[k] + pswd[k] - numKey[k];
           plainText += cipherText[k] + pswd[k] - numKey[k];
       }
      return plainText;

   }

};

#endif // CIPHER07_H 