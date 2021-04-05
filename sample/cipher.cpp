#include <string>
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
	string cipherText = cipher->encrypt("hello world");
	
	/* Perform decryption */
	cipher->decrypt(cipherText);	
	
	return 0;
}
