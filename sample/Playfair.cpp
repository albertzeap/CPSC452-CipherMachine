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
 * Pairs the string and places x where consecutive duplicates occur
 */

string Playfair::createPairedText(string plaintext){

	string pairedText;

	//Insert the x throughout the string
	for (int i=0; i < plaintext.length(); i++) {

	 //Peeking variable
     int j = i + 1;  

	 //Changes j to i in plaintext
	 if (plaintext[i] == 'j'){
		 plaintext[i] = 'i';
	 }

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

   //Add an x to even out the string 
   if ((pairedText.length() % 2) != 0){
	   pairedText += 'x';
   }

   return pairedText;
}


/**
 * Finds the location of the current letter in the matrix
 * @param  - a letter char
 * @return - pair of int
 */
void Playfair::findIndex(char letter, pair<int, int> &coordinates){
	for (int i = 0; i < 5; ++i){

			for (int j = 0; j < 5; ++j){
				
				if( letter == playMatrix[i][j] ){
					coordinates.first = i;
					coordinates.second = j;

					// cout << "Letter: " << letter << " is at [" << coordinates.first << "][" << coordinates.second << "]\n";
				}

			}
		}
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
	pair <int, int> firstCoordinates;
	pair <int, int> secondCoordinates;
	int peek;

	cout << "Plaintext: " << plaintext << endl;  

	createMatrix();
	pairedText = createPairedText(plaintext);


	for(int i = 0; i < pairedText.length(); i){
		peek = i + 1;

		// cout << "i   : " << i << "\n";
		// cout << "Peek: " << peek << endl;

		findIndex(pairedText[i], firstCoordinates);

		if (peek < pairedText.length()){
			findIndex(pairedText[peek], secondCoordinates);
		}

		// cout << "First Coordinates : " << firstCoordinates.first << " " << firstCoordinates.second << endl;
		// cout << "Second Coordinates: " << secondCoordinates.first << " " << secondCoordinates.second << endl;

		//If both letter fall in the same column, shift letters down
		if (firstCoordinates.first == secondCoordinates.first){

			firstCoordinates.second  = (firstCoordinates.second + 1) % 5;
			secondCoordinates.second = (secondCoordinates.second + 1) % 5;


			// cout << "Shifted First Coordinates : " << firstCoordinates.first << " " << firstCoordinates.second << endl;
			// cout << "Shifted Second Coordinates: " << secondCoordinates.first << " " << secondCoordinates.second << endl;

			cipherText += playMatrix[firstCoordinates.first ][firstCoordinates.second ];
			cipherText += playMatrix[secondCoordinates.first][secondCoordinates.second];

			// cout << cipherText << "\n\n";
		}

		//If both letters fall in the same row, shift letters right
		else if (firstCoordinates.second == secondCoordinates.second){

			firstCoordinates.first  = (firstCoordinates.first + 1) % 5;
			secondCoordinates.first = (secondCoordinates.first + 1) % 5;

			cipherText += playMatrix[firstCoordinates.first ][firstCoordinates.second ];
			cipherText += playMatrix[secondCoordinates.first][secondCoordinates.second];

			// cout << cipherText << "\n\n";
		}

		//If else, letter is replaced by the letter in the same row and in the column of the other letter of the pair 
		else { 
			int firstdifference = secondCoordinates.first - firstCoordinates.first;
			cipherText += playMatrix[firstCoordinates.first + firstdifference][firstCoordinates.second];

			int sdifference = secondCoordinates.second - firstCoordinates.second;
			cipherText += playMatrix[firstCoordinates.first][firstCoordinates.second + sdifference];

			// cout << cipherText << "\n\n";
		}

		i += 2;
	}
	
	
	cout << "Ciphertext: " << cipherText << endl;
	
	


	

	
 	
	return ""; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText) 
{ 
	pair <int, int> firstCoordinates;
	pair <int, int> secondCoordinates;
	string plaintext,pairedText;
	int peek;

	createMatrix();
	pairedText = createPairedText(cipherText);

	for(int i = 0; i < pairedText.length(); i){
		peek = i + 1;

		findIndex(pairedText[i], firstCoordinates);

		//Looks ahead and obtains coordinates of following letter
		if (peek < pairedText.length()){
			findIndex(pairedText[peek], secondCoordinates);
		}

		// cout << "First Coordinates : " << firstCoordinates.first << " " << firstCoordinates.second << endl;
		// cout << "Second Coordinates: " << secondCoordinates.first << " " << secondCoordinates.second << endl;

		//If both letter fall in the same column, shift letters up
		if (firstCoordinates.first == secondCoordinates.first){

			int firstCoorShifted, secondCoorShifted;
			firstCoorShifted  = firstCoordinates.second - 1; 
			secondCoorShifted = secondCoordinates.second - 1;

			//Wrap the index back into range
			if (firstCoorShifted == -1){
				firstCoorShifted = 4;
			}

			if (secondCoorShifted == -1){
				secondCoorShifted = 4;
			}

			firstCoordinates.second  = firstCoorShifted;
			secondCoordinates.second = secondCoorShifted;

			//Add to plaintext
			plaintext += playMatrix[firstCoordinates.first ][firstCoordinates.second ];
			plaintext += playMatrix[secondCoordinates.first][secondCoordinates.second];

			// cout << "Shifted First Coordinates : " << firstCoordinates.first << " " << firstCoordinates.second << endl;
			// cout << "Shifted Second Coordinates: " << secondCoordinates.first << " " << secondCoordinates.second << endl;
			// cout << plaintext << "\n\n";
		}

		//If both letters fall in the same row, shift letters left
		else if (firstCoordinates.second == secondCoordinates.second){

			//Shifts the letter index to the left;
			int firstCoorShifted, secondCoorShifted;
			firstCoorShifted  = firstCoordinates.first - 1; 
			secondCoorShifted = secondCoordinates.first - 1;

			//Wrap the index back into range
			if (firstCoorShifted == -1){
				firstCoorShifted = 4;
			}

			if (secondCoorShifted == -1){
				secondCoorShifted = 4;
			}

			firstCoordinates.first  = firstCoorShifted;
			secondCoordinates.first = secondCoorShifted;

			//Add to plaintext
			plaintext += playMatrix[firstCoordinates.first ][firstCoordinates.second ];
			plaintext += playMatrix[secondCoordinates.first][secondCoordinates.second];

			// cout << "Shifted First Coordinates : " << firstCoordinates.first << " " << firstCoordinates.second << endl;
			// cout << "Shifted Second Coordinates: " << secondCoordinates.first << " " << secondCoordinates.second << endl;
			// cout << plaintext << "\n\n";
		}

		//If else, letter is replaced by the letter in the same row and in the column of the other letter of the pair 
		else { 
			
			//First decrypted letter
			int fdifference = secondCoordinates.first - firstCoordinates.first;
			plaintext += playMatrix[firstCoordinates.first + fdifference][firstCoordinates.second];

			//Second decrypted letter
			int sdifference = secondCoordinates.second - firstCoordinates.second;
			plaintext += playMatrix[firstCoordinates.first][firstCoordinates.second + sdifference];


			// cout << plaintext << "\n\n";
		}

		i += 2;
	}
	cout << "Plaintext: " << plaintext << "\n";

	return plaintext; 
	
}



