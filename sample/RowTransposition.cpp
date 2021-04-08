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

	string ciphertext;
	vector<int>::iterator itr;
	int xCoor = rowTranKey.size(),
		yCoor = (plaintext.length() / xCoor) + (plaintext.length() % xCoor),
		index = 0, vecIndex = 0;
	
	for (int i = 0; i < rowTranKey.size(); ++i){
				
		index = rowTranKey[i] - 1;
		cout << "Index[" << index << "]["<< rowTranKey[i] << "] Find\n";
		cout << "Plaintext Length: [" << plaintext.length() << "] \n";
		//Travels down the column and appends it to the string
		while(index < plaintext.length()){
			ciphertext += plaintext[index];

			cout << "While - Index: " << index << "--> " << plaintext[index] <<  "\n";

			index += rowTranKey.size();
			
		}

		cout << endl;

		

		
	}

	cout << ciphertext << endl;

	return ciphertext; 
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

