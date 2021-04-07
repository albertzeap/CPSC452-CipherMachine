#include "RailFence.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool RailFence::setKey(const string& key)
{ 
	//Int value of key
	int keyValue;	
	
	//stoi() throws error if value is alphabet
	if (!(keyValue = stoi(key))){					
		return false;
	}
	else {
		cout << "CURRENT KEY: "<< keyValue << "\n";
		railKey = keyValue ;
		cout << "DEPTH VALUE: "<< railKey << endl;
		return true;
	}					
	
	return false;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RailFence::encrypt(const string& plaintext)
{ 
	
	
	return ""; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RailFence::decrypt(const string& cipherText) 
{ 
	return ""; 
	
}

