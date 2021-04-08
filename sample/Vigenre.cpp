#include "Vigenre.h"

using namespace std;

/**
 * To encrypt the Vigenere Cipher:
 * The KEY's length must be repeat until it it matched the PLAINTEXT's length
 * PLAINTEXT is x while KEY is y
 * To decrypt the Vigenere Cipher:
 * /

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
//Checking whenever key are valid
//Invalid: numbers or special characters.
string keyV;
bool Vigenre::setKey(const string& key)
{ 

	keyV = key;
	int keyL = key.length();
	for(int i = 0; i < keyL; i++)
	{
		if(!isalpha(keyV[i]))
		{
			return false;
		}
	}
	return true;  
}


/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Vigenre::encrypt(const string& plaintext)
{ 
	//Encryption
	string cipherT = "";
	char cipherC;
	int sizeP = plaintext.size();
	
	int index = 0;
	while(cipherT.size() < plaintext.size())
	{
		for(int i = 0; i < keyV.size();i++)
		{
			cipherC = (char) (((((int)plaintext[index]-(int)'A') + (int)keyV[i]-(int)'A'))%26) + (int)'A';
			cipherT += cipherC;
			index++;
		
		}
	}

	return cipherT; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenre::decrypt(const string& cipherText) 
{ 
	//Decryption
	string plainT = "";
	char cipherC;
	
	int index = 0;
	while(plainT.size() < cipherText.size())
	{
		for(int i = 0; i < keyV.size();i++)
		{

			cipherC = (char) (((((int)cipherText[index]-(int)'A') - ((int)keyV[i]-(int)'A')) + 26)%26) + (int)'A';;
			plainT += cipherC;
			index++;
		}
	}
	
	return plainT; 
	
}