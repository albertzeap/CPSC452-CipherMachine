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
		caesarKey = (keyValue % 26);
		cout << "Shift Value: " << caesarKey << endl;
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
	string ciphertext;										//Create the ciphertext variable

	for (int i = 0; i < plaintext.length(); ++i){
		int charVal = ((int)plaintext[i]) + caesarKey;		//Shift the plaintext over by the key

		if(charVal <= 'z'){									//Checks if shifted value is out of bounds
			ciphertext += (char)charVal;
		}
		else{
			charVal = (charVal - 'z') + 'a';				//Loop back to the beginning of the alphabet
			ciphertext +=(char)charVal;
		}
		
				
	}
	cout << "ENCRYPTION - CIPHERTEXT: " <<ciphertext << endl;

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
			int charVal = (int)cipherText[i] - caesarKey;

		if(charVal >= 'a'){
			plainText += (char)charVal;
		}
		else{
			charVal = (charVal - 'a') + 'z';
			plainText +=(char)charVal;
		}

		}
		cout <<"DECRYPTION - PLAINTEXT : " <<plainText << endl;



	return plainText; 
	
}

