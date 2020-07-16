/********************************************************************
* Header:
* Vigenère cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

#include <string>


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Jason Steffen"; }
   virtual std::string getCipherName()  { return "vigenere-cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher");
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

#endif // CIPHER05_H