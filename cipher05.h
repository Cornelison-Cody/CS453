/********************************************************************
* Header:
* Vigenère cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

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
      str =  "
      string plaintext;
      string password;
      string cipher;
      
      cin >> password;
      cin >> plaintext;

      char cipherColumn[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}

      char aArray[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}
      char bArray[] = {b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a}
      char cArray[] = {c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b}
      ...
      //THE REST OF THE ARRAYS GO HERE
      ...
      char zArray[] = {z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y}

      int passwordIterator = 0;

      //Iterate through the plaintext message
      for int i = 0; plaintext[i]; i++
      {
         char plaintextLetter = plaintext[i]
         int plaintextNumber = -1;
         char passwordLetter = password[passwordIterator]

         //Find the column number of the cipher
         SWITCH statement
         char plaintextLetter = a
            plaintextNumber = 0;
            break;
         char plaintextLetter = b
            plaintextNumber = 1;
            break;
         //...MORE SWITCH STATEMENTS
         char plaintextLetter = z
            plaintextNumber = 25
            break;

         //Any character that is not a-z will be the placeholder
         if plaintextNumber = -1
            cipher[i] = 0 or any other placeholder

         //Find the row of the cipher and set the cipher's letter
         SWITCH statement
         char password[passwordIterator] = a
            cipher[i] = aArray[plaintextNumber];
            break;
         char password[passwordIterator] = b
            cipher[i] = bArray[plaintextNumber];
            break;
         //...MORE SWITCH STATEMENTS
         char password[passwordIterator] = z
            cipher[i] = zArray[plaintextNumber];
            break;

            //If we have gone through the password, start over.
         if password[!passwordIterator++]
           passwordIterator = 0;
         else passwordIterator++;
      }

         cout << cipher;
      ";

      // The decrypt pseudocode
      str += "
      string plaintext;
      string password;
      string cipher;
      
      cin >> password;
      cin >> cipher;

      char plaintextColumn[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}

      char aArray[] = {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}
      char bArray[] = {b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a}
      char cArray[] = {c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,a,b}
      ...
      //THE REST OF THE ARRAYS GO HERE
      ...
      char zArray[] = {z,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y}

      int passwordIterator = 0;

      //Iterate through the cipher message
      for int i = 0; cipher[i]; i++
      {
         char cipherLetter = cipher[i]
         int cipherNumber = -1;
         char passwordLetter = password[passwordIterator]

         //Find the column number of the cipher
         SWITCH statement
         char cipherLetter = a
            cipherNumber = 0;
            break;
         char cipherLetter = b
            cipherNumber = 1;
            break;
         //...MORE SWITCH STATEMENTS
         char cipherLetter = z
            cipherNumber = 25
            break;

         //Any character that is not a-z will be the placeholder
         if cipherNumber = -1
            plaintext[i] = 0 or any other placeholder

         //Find the row of the plaintext and set the plaintext's letter
         SWITCH statement
         char password[passwordIterator] = a
            plaintext[i] = aArray[cipherNumber];
            break;
         char password[passwordIterator] = b
            plaintext[i] = bArray[cipherNumber];
            break;
         //...MORE SWITCH STATEMENTS
         char password[passwordIterator] = z
            plaintext[i] = zArray[cipherNumber];
            break;

         //If we have gone through the password, start over.
         if password[!passwordIterator++]
           passwordIterator = 0;
         else passwordIterator++;

      }

         cout << plaintext;

      ";

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