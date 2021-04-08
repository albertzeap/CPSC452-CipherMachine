#include "RowTransposition.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool RowTransposition::setKey(const string& key)
{ 

	//Checks for any alphabet
	int keyValue;
	if (!(keyValue = stoi(key))){					
		return false;
	}

	//Adds the values into a vector
	for (int i = 0; i < key.length(); ++i){

		//Parses out the '-'
		if (key[i] != '-'){
			
			//Push integer value back into the vector
			rowTranKey.push_back((int)key[i] - 48);
			
		}

	}

	//Prints Key
	cout << "KEY: ";  
	for (int i = 0 ; i < rowTranKey.size(); ++i){
		cout << rowTranKey[i] << " ";
	}
	cout << "\n";

	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RowTransposition::encrypt(const string& plaintext)
{ 
	
	
	return ""; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const string& cipherText) 
{ 
	return ""; 
	
}

