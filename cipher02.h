/********************************************************************
* Header:
* Checkerboard Cipher
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Eric Mott"; }
   virtual std::string getCipherName()  { return "Checkerboard"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "Bradley Dawson"; }

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
	   str = "checkerboardCipher()";
	   str = +"string vertKeyword";
	   str = +"string horizKeyword";
	   str = +"char rowKey[5]";
	   str = +"char columnKey[5]";
	   str = +"string message";
	   str = +"string cipherMessage";

	   str = +"char alphabetArray[5][5] = {";
	   str = +"{'w', 'c', 'e', 'o', 'v'},";
	   str = +"{'x', 'b', 'm', 's', 'f'},";
	   str = +"{'h', 'k', 'q', 'r', 'y'},";
	   str = +"{'i', 'p', 'z', 'n', 't'},";
	   str = +"{'u', 'a', 'd', 'g', 'l'}}";

	   str = +"display 'Enter first keyword (5 nonrepeating characters): '";
	   str = +"accept vertKeyword";
	   str = +"display 'Enter second keyword (5 nonrepeating characters): '";
	   str = +"accept horizKeyword";
	   str = +"display 'Enter message: '";

	   str = +"convert vertKeyword to vertKey";
	   str = +"convert horizKeyword to columnKey";

	   str = +"loop thru message";
	   str = +"loop thru alphabetArray";
	   str = +"match message character to alphabetArray character";
	   str = +"if message character is 'j' match to alphabetArray character 'i'";
	   str = +"if not alpha character then skip";
	   str = +"cipherMessage =+ rowKey[alphabetArray row value]";
	   str = +"cipherMessage =+ columnKey(alphabetArray column value]";

	   str = +"return codedCheckerboard";

	   // The decrypt pseudocode
	   str += "decodeCheckerboard(codedCheckerboard)";
	   str = +"string decodeMessage";
	   str = +"loop thru codedCheckerboard";
	   str = +"if codedCheckerboard index is even";
	   str = +"match codedCheckerboard character to rowKey character";
	   str = +"alphabetArrayRow = rowKey index";
	   str = +"if codedCheckerboard index is odd";
	   str = +"match codedCheckerboard character to columnKey character";
	   str = +"alphabetArrayColumn = columnKey index";
	   str = +"decodedMessage =+ alphabetArray[alphabetArrayRow][alphabetArrayColumn]";

	   str = +"return decodedMessage";

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

#endif // CIPHER02_H