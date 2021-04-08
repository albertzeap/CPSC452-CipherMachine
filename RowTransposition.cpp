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
	return true;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string RowTransposition::encrypt(const string& plaintext)
{ 

	string ciphertext, plaintextDup = plaintext; 
	int index = 0;

	//Adds filler characters to even out the string for decryption
	while ( (plaintextDup.length() % rowTranKey.size()) != 0){
		plaintextDup += 'x';
	}
	
	
	for (int i = 0; i < rowTranKey.size(); ++i){
				
		index = rowTranKey[i] - 1;

		//Travels down the column and appends it to the string
		while(index < plaintextDup.length()){
			ciphertext += plaintextDup[index];

			index += rowTranKey.size();
			
		}		
	}
	return ciphertext; 
}


/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const string& cipherText) 
{ 
	string plaintext;

	//Create a pair to record the column number of the character
	vector<pair <int,char>> rowLetters;
	int rows  = (cipherText.length() / rowTranKey.size()) ,
		 keyCounter, index = 0;


	for (int i = 0; i < rows; ++i){

		//Index keeps track of character in the row
		index = i;

		//Key counter maps the character values to the key value
		keyCounter = 0;

		//Creates a vector of pairs consisting of the column and corresponding character
		while(index < cipherText.length()){

			
			if (keyCounter < rowTranKey.size()){
				rowLetters.push_back(make_pair(rowTranKey[keyCounter],cipherText[index]));
				++keyCounter;
			}
			else {
				keyCounter = 0;
			}
				index += rows;
		}
		
		//Sorts the integer/key values and also sorts the letters by doing so
		sort(rowLetters.begin(),rowLetters.end());
		
		//Append the characters to the plaintext
		for (int i = 0 ; i < rowLetters.size(); ++i){
			plaintext += rowLetters[i].second;
		}

		//Vector only handles one row at a time
		rowLetters.clear();
		

	}
	return plaintext; 
	
}

