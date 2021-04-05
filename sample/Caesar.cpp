#include "Caesar.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{ 
	string verifiedKey;								//Final key used for error checking
	int keyValue;									//Int value of key

	for (int i = 0; i < key.length(); ++i){			//Checks for any value that is not a digit
		char letter = key[i];
		if (isalpha(letter)){
			fprintf(stderr, "ERROR: Key is not a valid digit\n");
			exit(-1);
		}

		verifiedKey += letter;						//Append the digit values to the string
	}
		keyValue = stoi(verifiedKey) % 26;				//Convert the string value to an int
	
		if (isdigit(keyValue)){
			cout << "CURRENT KEY: "<<verifiedKey << "\n";
			caesarKey = keyValue;
			return true;
		}
	
	return false;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{ 
	string ciphertext;							//Create the ciphertext variable
	for (int i = 0; i < plaintext.length(); ++i){
		char letter = plaintext[i]; 			//Saves the current character to be shifted 
		letter += caesarKey % 26;					//Shifts the letter by the key value
		ciphertext += letter;					//Saves value
	}
	cout << "ENCRYPTION: " <<ciphertext << endl;

	return ciphertext; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText) 
{
	string plainText;
	for (int i = 0; i < cipherText.length(); ++i){
			char letter = cipherText[i]; 			//Saves the current character to be shifted 
			letter -= caesarKey % 26;				//Shifts the letter by the key value
			plainText += letter;					//Saves value
		}
		cout <<"DECRYPTION: " <<plainText << endl;



	return plainText; 
	
}

