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
	string cipherText;
	int lettersPerRow = plaintext.length() / railKey,
		pIndex = 0;
	char railMatrix[railKey][lettersPerRow];
	// char railMatrix[lettersPerRow][railKey];
	
	
	
	cout << "Plaintext      : " << plaintext     << "\n";
	cout << "Letters Per Row: " << lettersPerRow << "\n";

	for (int i = 0; i < lettersPerRow; ++i){

		//Inserts the plaintext by column
		for (int j = 0; j < railKey; ++j){
			railMatrix[j][i] = plaintext[pIndex]; 
			++pIndex;
			
		}
	}

	for (int i = 0; i < railKey; ++i){

		for(int space = 0; space < i; ++space){
			cout << " ";
		}


		for (int j = 0; j < lettersPerRow; ++j){
			cout << railMatrix[i][j] << " ";
			cipherText += railMatrix[i][j];
		}

		cout << "\n";
	}
	
	cout << "CipherText: " << cipherText << "\n";

	return cipherText; 
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

