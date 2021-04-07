#include "Caesar.h"


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key) { 	\

	//Int value of key
	int keyValue;	
	
	//stoi() throws error if value is alphabet
	if (!(keyValue = stoi(key))){					
		return false;
	}
	else {
		cout << "CURRENT KEY: "<<keyValue << "\n";
		caesarKey = (keyValue % 26);
		cout << "Shift Value: " << caesarKey << endl;
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
	string ciphertext;									

	for (int i = 0; i < plaintext.length(); ++i){

		//Shift the plaintext over by the key
		int charVal = ((int)plaintext[i]) + caesarKey;		

		//Checks if shifted value is out of bounds
		if(charVal <= 'z'){									
		}
		else{
			//Loop back to the beginning of the alphabet
			charVal = (charVal - 'z') + 'a';				
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

