#ifndef PLAYFAIR_H
#define PLAYFAIR_H

#include <vector>   /* For vectors */
#include <string>   /* For C++ strings */
#include <stdio.h>  /* For standard I/O */
#include <stdlib.h> /* For miscellenous C functions */
#include <iostream>
#include <utility>
#include "CipherInterface.h"

using namespace std;

/**
 * This class implements the playfair cipher.
 * The class extends the abstract class 
 * CipherInterface.
 */

class Playfair: public CipherInterface
{
	/** The public members **/
	public:

		/**
		 * Sets the key to use
		 * @param key - the key to use
		 * @return - True if the key is valid and False otherwise
		 */
		virtual bool setKey(const string& key);

		/**	
		 * Encrypts a plaintext string
		 * @param plaintext - the plaintext string
		 * @return - the encrypted ciphertext string
		 */
		virtual string encrypt(const string& plaintext);

		/**
		 * Decrypts a string of ciphertext
		 * @param ciphertext - the ciphertext
		 * @return - the plaintext
		 */
		virtual string decrypt(const string& ciphertext);


		/**
		 * Creates the Playfair matrix and updates playMatrix variable
		 */
		void createMatrix();

		/**
		 * Pairs the string and places x where consecutive duplicates occur
		 * @param  - plaintext 
		 * @return - the paired text
		 */
		string createPairedText(string plaintext);

		/**
		 * Finds the location of the current letter in the matrix
		 * @param  - a letter char
		 * @return - pair of int
		 */
		void findIndex(char letter, pair<int, int> &coordinates);
			
		/**
		 * Prints the Playfair matrix
		 * @param fp - the file pointer
		 */
		void printMatrix(FILE* fp);


		/**
		 *  Removes the duplicates from strings
		 *  @param  - string to be cleaned
		 * 	@return - string with duplicate letters removed
		 */
		string removeDuplicates(string filthyString);

		
		/* The protected members */
	protected:

		//The key for encrypting
		string playKey;

		//The 5x5 matrix that will be used
		char playMatrix[5][5];


};

#endif
