#include "Playfair.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Playfair::setKey(const string& key)
{ 
	string keyVal;
	for(int i = 0; i < key.length(); ++i){			//Iterate through the key to check for digits
		if(isalpha(key[i])){
			keyVal += key[i];

			if(keyVal.length() == key.length()){ 	//Only return true if the whole key had no digits
				playKey = key;
				return true;
			}
		}

	}

	return false;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{ 
	string cipherText;
	for(int i = 0; i < plaintext.length(); ++i){
		





	}
	
 	
	return ""; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText) 
{ 
	return ""; 
	
}



