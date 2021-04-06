#include "Caesar.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{ 
	int keyValue;									//Int value of key
	
	if (!(keyValue = stoi(key))){					//stoi() throws error if value is alphabet
		return false;
	}
	else {
		cout << "CURRENT KEY: "<<keyValue << "\n";
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
		char letter = plaintext[i];				//Saves the current character to be shifted 
		if(letter <= 'a' || letter <= 'z'){
			
		}
		letter += caesarKey % 26;				//Shifts the letter by the key value
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

