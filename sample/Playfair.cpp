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

string Playfair::removeDuplicates(string filthyString){
	string cleanString;
	int index = 0;   
     

   for (int i=0; i < filthyString.length(); i++) {
     int j;  

	//Move on to the next if duplicates are found
     for (j = 0; j<i; j++) {
        if (filthyString[i] == filthyString[j])
           break;
	 }
       
	//Add it to the string if it has no duplicate  
     if (j == i)
        cleanString += filthyString[i];
   }
     
		

		
	
	cout << "Matrix Key: " << cleanString << endl;



	return cleanString;
}


/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{ 
	string cipherText;

	//Key that is used in the matrix with duplicates removed
	string matrixKey = removeDuplicates(playKey);



	int k = 0;
	char letter = 'a';
	for(int j = 0; j < 5; ++j){ 								//Column
		for (int i = 0; i < 5; ++i){							//Row
			if (k < matrixKey.length() ){	
				playMatrix[i][j] = matrixKey[k];
			}
			else {
				playMatrix[i][j] = letter;
				++letter;
			}
			++k;
		}

	}

	for(int j = 0; j < 5; ++j){ 								//Column
		for (int i = 0; i < 5; ++i){							//Row
			cout << playMatrix[i][j] << " ";
		}
		cout << "\n";
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



