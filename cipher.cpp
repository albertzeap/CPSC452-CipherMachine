#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "CipherInterface.h"
#include "Playfair.h"
#include "Vigenre.h"
#include "Caesar.h"
#include "RowTransposition.h"
#include "RailFence.h"


using namespace std;

int main(int argc, char** argv)
{


	if(argc != 6)
	{
		fprintf(stderr, "Usage: <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n");
		cout << "PLF --> PLAYFAIR            |	KEY: Word\n";
		cout << "RTS --> ROW TRANSPOSITION   |	KEY: Digit-Digit-Digit\n";
		cout << "RFC --> RAILFENCE           |	KEY: Digit\n";
		cout << "VIG --> VIGENERE            |	KEY: Word\n";
		cout << "CES --> CAESAR              |	KEY: Digit\n";
		exit(-1);
	}

	

	string cipherN = argv[1];
	string cipherK = argv[2];
	string cipherM = argv[3];
	string cipherIP = argv[4];
	string cipherOP = argv[5];
	
	transform(cipherN.begin(), cipherN.end(), cipherN.begin(), ::toupper);

	transform(cipherM.begin(), cipherM.end(), cipherM.begin(), ::toupper);
	
	
	//File objects
	fstream inputFile, outputFile;			
	inputFile.open (cipherIP, ios::in );		
	
	if (!inputFile)
	{
		fprintf(stderr, "ERROR: Invalid file\n");
		exit(-1);
	}
	
	//Store the contents of the file into a string
	string fileContents;					
	while(!inputFile.eof())
	{
		inputFile >> fileContents;
		
	}
	
	
	
	//Closing file afer open
	if (inputFile.is_open())
	{
		inputFile.close();
	}
	
	/* Create an instance of the Playfair cipher */	
	CipherInterface* cipher = NULL;
	//Cipher selection
	
	if( cipherN == "PLF")
	{
		cout << "CIPHER: Playfair \nKEY: " 			<< cipherK << endl;
		cipher = new Playfair();
	}
	else if( cipherN == "RTS")
	{
		cout << "CIPHER: Row Transposition \nKEY: " << cipherK << endl;
		cipher = new RowTransposition();
	}
	else if( cipherN == "RFC")
	{
		cout << "CIPHER: Rail Fence \nKEY: " 		<< cipherK << endl;
		cipher = new RailFence();
	}
	else if( cipherN == "VIG")
	{
		cout << "CIPHER: Vigenere \nKEY: " << cipherK << endl;
		transform(cipherK.begin(), cipherK.end(), cipherK.begin(), ::toupper);
		transform(fileContents.begin(), fileContents.end(), fileContents.begin(), ::toupper);
		cipher = new Vigenre();
		cipher->setKey(cipherK);
	}
	else if( cipherN == "CES")
	{
		cout << "CIPHER: Caesar \nKEY: " << cipherK << endl;
		cipher = new Caesar();
	}
	else //Error chekcing taking from the provided sample file
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
		__FILE__, __FUNCTION__, __LINE__);
		cout << "Please compare your Cipher name input to the ones available in the Read Me and try again.\n" << "Thank you and good bye." << endl; 
		exit(-1);
	}

	if(cipher->setKey(cipherK) == false)
	{
		cout << "Invalid Key" << endl;
		exit(-1);
	}
	
	/* Set the encryption key */
	//cipher->setKey(argv[2]);
	//Check the mode
	//Write finished encryption or decryption to output file
	outputFile.open(cipherOP, ios::out);
	if(cipherM == "ENC")
	{
		/* Perform encryption */
		cout << "PLAINTEXT : " << fileContents << endl;
		string cipherText = cipher->encrypt(fileContents);
		cout << "CIPHERTEXT: " << cipherText << endl;
		outputFile << cipherText;
	}
	else if(cipherM == "DEC")
	{
		/* Perform decryption */
		cout << "CIPHERTEXT: " << fileContents << endl;
		string plaintext = cipher->decrypt(fileContents);	
		outputFile << plaintext;
		cout << "PLAINTEXT : " << plaintext << endl;
	}
	else
	{
		cout << "Please enter ENC for Encryption or DEC for Decryption" << endl;
		exit(-1);
	}

	//Close file after writing
	if (outputFile.is_open())
	{
		outputFile.close();
	}
	
	
	return 0;
}