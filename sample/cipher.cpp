#include <string>
#include <fstream>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"




using namespace std;

int main(int argc, char** argv)
{
	if(argc != 6){
		fprintf(stderr, "Usage: <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n");
		exit(-1);
	}
		
	fstream inputFile, outputFile;			//File objects
	inputFile.open (argv[4], ios::in );		
	outputFile.open(argv[5], ios::out);
	if (!inputFile){
		fprintf(stderr, "ERROR: Invalid file\n");
		exit(-1);
	}
	
	string fileContents;					//Store the contents of the file into a string
	while(!inputFile.eof()){
		inputFile >> fileContents;
	}

	/* Create an instance of the Playfair cipher */	
	CipherInterface* cipher = new Caesar();
	
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	cipher->setKey(argv[2]);
	
	/* Perform encryption */
	string cipherText = cipher->encrypt(fileContents);
	outputFile << "ENCRYPTED TEXT: \n" << cipherText << endl;
	
	/* Perform decryption */
	string plaintext = cipher->decrypt(cipherText);	
	outputFile << "DECRYPTED TEXT: \n" << plaintext << endl;
	
	return 0;
}
