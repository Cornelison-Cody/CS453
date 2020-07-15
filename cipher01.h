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

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "James Clarke"; }
   virtual std::string getCipherName()  { return "Numbered Key Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

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
      /*
      START 
      STRING key
      STRING message
      INT freqLetter
      CHAR numKey[key.length][freqLetter]
      INT num

      DISPLAY "Please enter key, letters only"
      INPUT key 

      DISPLAY "Please enter message, letters only"
      INPUT message

      CALCULATE key.length

      
      CALCULATE key missing letters a to z

      FOR key.legnth
            READ key
            INSERT missing letters to end of STRING key in alphabetical order
      END FOR
      FOR key.length
            READ key FIND letters posistion in string
            INCREMENT freqLetter most used letter
      END FOR
      FOR key.length
      
        SET num = READ key to FIND letters posistion in string
        SET numKey[i][0] = key
       

      */

      str =  "insert the encryption pseudocode\n";

      // The decrypt pseudocode
      /*
      PseudcCode goes Here
      */

      str += "insert the decryption pseudocode\n";

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

#endif // CIPHER01_H