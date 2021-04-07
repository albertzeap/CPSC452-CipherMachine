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
				cout << "Key: " << playKey << "\n";
				return true;
			}
		}

	}

	return false;  
}

/**
 * Creates the Playfair matrix and updates playMatrix variable
 * @param - the cleanKey without duplicates
 */
void Playfair::createMatrix(){

	//Values that will be stored in matrix
	string matrixContents;

	//Alphabet + key										
	string alphaKey = playKey;	

	//Replaces j with i
	for (int i = 0; i < alphaKey.length(); ++i){				
		if (alphaKey[i] == 'j'){
			alphaKey[i] = 'i';
		}
	}

	//Add the alphabet to the clean key and skip j
	char letter = 'a';  										
	for (int i = 0; i < 26; ++i){
			if (letter == 'j'){							
				letter++;
			}
			else{
				alphaKey += letter;
				letter++;
			}
			
	}

	//Remove any duplicate letters															
	matrixContents = removeDuplicates(alphaKey);				
	
	

	//Loads up matrix
	int k = 0;
	//Column
	for(int j = 0; j < 5; ++j){ 	
		//Row						
		for (int i = 0; i < 5; ++i){						
			//Checks if k is out of range of matrixContents string
			if (k < matrixContents.length()) {					
				playMatrix[i][j] = matrixContents[k];
			}
			++k;
		}
	}


	//Prints Matrix
	for(int j = 0; j < 5; ++j){ 								
		for (int i = 0; i < 5; ++i) {							
			cout << playMatrix[i][j] << "   ";
		}
		cout << "\n";
	}

}

/**
 *  Removes the duplicates from strings
 *  @param  - string to be cleaned
 * 	@return - string with duplicate letters removed
 */
string Playfair::removeDuplicates(string filthyString){
	string cleanString;
	int index = 0;   
     
   for (int i=0; i < filthyString.length(); i++) {
     int j;  

	//Move on to the next if duplicates are found
     for (j = 0; j<i; j++) {
        if (filthyString[i] == filthyString[j]){
           break;
		}
	 }
       
	//Add it to the string if it has no duplicate  
     if (j == i){
		cleanString += filthyString[i]; 
	 }
   }
	return cleanString;
}


/**
 * Prints the Playfair matrix
 * @param fp - the file pointer
 */
void Playfair::printMatrix(FILE* fp){

}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plaintext)
{ 
	
	string cipherText, pairedText;
	int counter = 0;
	createMatrix();

	for (int i=0; i < plaintext.length(); i++) {
	 //Peeking variable
     int j = i + 1;  

	 //Append first characters to pairedText
	 pairedText += plaintext[i]; 

	 //If there are two consecutive duplicates, insert an x
	 if (j < plaintext.length()){
		 if (plaintext[i] == plaintext[j]){
			pairedText += 'x';
		 }
		++j;
	 }


	

     
	
		
   }

	

	cout << "PairedText: " << pairedText << endl;
	
	


	

	
 	
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



