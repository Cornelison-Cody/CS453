/********************************************************************
* Header: RAGBABY CIPHER
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Cody Cornelison"; }
   virtual std::string getCipherName()  { return "Ragbaby Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://www.cryptogram.org/downloads/aca.info/ciphers/Ragbaby.pdf");
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
      str =  "    int wordCount = 1\n";
      str =  "    int charCount = 1\n";
      str += "    FOR c is all chars in plainText\n";
      str =  "        IF c is a space\n";
      str =  "            wordCount++\n";
      str =  "            charCount = wordCount % alphabet.length()\n";
      str =  "            encryptedText[c] = space\n";
      str =  "        ELSE \n";
      str =  "        offsetArray[c] = charCount++ % alphabet.length()\n";
      str += "        encryptedText[c] = alphabet[(alpabet.find(c) + offsetArray[c]) % alphabet.length()]\n";
      str += "    RETURN encryptedText\n";

      // The decrypt pseudocode
      str =  "decrypt(plainText, password)\n";
      str += "    string alphabet <- generateAlphabet(password)\n";
      str =  "    int wordCount = 1\n";
      str =  "    int charCount = 1\n";
      str += "    FOR c is all chars in plainText\n";
      str =  "        IF c is a space\n";
      str =  "            wordCount++\n";
      str =  "            charCount = wordCount % alphabet.length()\n";
      str =  "            decryptedText[c] = space\n";
      str =  "        ELSE \n";
      str =  "        offsetArray[c] = charCount++ % alphabet.length()\n";
      str += "        decryptedText[c] = alphabet[(alphabet.length() + alpabet.find(c) - offsetArray[c]) % alphabet.length()]\n";
      str += "    RETURN decryptedText\n";

      // Generate Alphabet function
      str =  "generateAlphabet(password)\n";
      str += "    FOR p is all values of password\n";
      str += "        store upper case p in a std::set alphabet to remove duplicates\n";
      str += "        if p is a - j then add corresponding number to alphabet\n";
      str += "    FOR c is A - Z and 0 - 9\n";
      str += "        add to alphabet as well\n";
      str += "    RETURN alphabet\n";
      

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

#endif // CIPHER06_H