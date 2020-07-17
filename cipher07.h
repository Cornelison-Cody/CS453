/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

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
      // TODO - Add your code here
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
      return plainText;
   }
};

#endif // CIPHER07_H