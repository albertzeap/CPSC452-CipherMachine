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
		// cout << "DEPTH VALUE: "<< railKey << endl;
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
	
	
	
	// cout << "Plaintext      : " << plaintext     << "\n";
	// cout << "Letters Per Row: " << lettersPerRow << "\n";

	for (int i = 0; i < lettersPerRow; ++i){

		//Inserts the plaintext by column
		for (int j = 0; j < railKey; ++j){
			railMatrix[j][i] = plaintext[pIndex]; 
			++pIndex;
			
		}
	}

	//Print and add value to ciphertext
	for (int i = 0; i < railKey; ++i){

		//Add space for diagonal view
		for(int space = 0; space < i; ++space){
			cout << " ";
		}

		//Append matrix elements to cipher text
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
	string plaintext;
	int lettersPerRow = cipherText.length() / railKey,
		cIndex = 0;
	char railMatrix[railKey][lettersPerRow];

	// cout << "Ciphertext     : " << cipherText     << "\n";
	// cout << "Letters Per Row: " << lettersPerRow << "\n";

	for (int i = 0; i < railKey; ++i){

		//Add space for diagonal view
		for(int space = 0; space < i; ++space){
			cout << " ";
		}

		//Inserts the ciphertext by row
		for (int j = 0; j < lettersPerRow; ++j){
			railMatrix[i][j] = cipherText[cIndex]; 
			++cIndex;
			cout << railMatrix[i][j] << " ";
		}
		cout << "\n";
	}


	for (int i = 0; i < lettersPerRow; ++i){

		//Inserts the plaintext by column
		for (int j = 0; j < railKey; ++j){
			plaintext += railMatrix[j][i];
		}
	}

	cout << "Plaintext: " << plaintext << "\n";
 
	return plaintext; 
	
}

