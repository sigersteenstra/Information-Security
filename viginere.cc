#include <iostream>
#include <fstream>
#include <string.h>

/* The Viginere algorithm is implemented here:
 * It is a very simple encryption/decryption method
 * that surfaced ages ago. For a long time it seemed
 * unbreakable, but using character statistics the
 * password can be guessed.
 * The integer values of the characters of the password
 * determine the shift for a cipher.
 * This updated version can handle all ascii input
 * characters and is capable of writing an output file.
 * It requires a password, encryption/decryption flag,
 * input file and output file.
 */

using namespace std;

void encrypt(string password, char* buffer, int msglength, string output){
	char *pass = new char[password.length() + 1];
	strcpy(pass, password.c_str());
	int current;
	int passlength = password.length();
	cout << "\n\n-----------------\nORIGINAL MESSAGE:\n";
	for (int i=0;i<msglength;i++) cout << buffer[i];
	cout << "\n\n------------------\nENCRYPTED MESSAGE:\n";
	ofstream o;
	o.open(output);
	for(int i=0;i<msglength;i++){
		current=buffer[i];
		current+=pass[i%passlength];
		char cipher = current;
		cout << cipher;
		o << cipher;
	}
	o.close();
	cout << "\n\n";
}

void decrypt(string password, char* buffer, int msglength, string output){
	char *pass = new char[password.length() + 1];
	strcpy(pass, password.c_str());
	int current;
	int passlength = password.length();
	cout << "\n\n-----------------\nENCRYPTED MESSAGE:\n";
	for (int i=0;i<msglength;i++) cout << buffer[i];
	cout << "\n\n------------------\nDECRYPTED MESSAGE:\n";
	ofstream o;
	o.open(output);
	for(int i=0;i<msglength;i++){
		current=buffer[i];
		current-=pass[i%passlength];
		char cipher = current;
		cout << cipher;
		o << cipher;
	}
	o.close();
	cout << "\n\n";
}

int main(int argc, char *argv[])
{
	if (argc!=5){
		cout << "Incorrect number of arguments!\n";
		cout << "USAGE:\n";
		cout << "arg1: password\n";
		cout << "arg2: -e for encryption, -d for decryption\n";
		cout << "arg3: input file\n";
		cout << "arg4: output file\n";
		return -1;
	} else{
		string password = argv[1];
		string flag = argv[2];
		string output = argv[4];
		ifstream f;
		f.open(argv[3]);
		f.seekg(0, std::ios::end);
		int msglength = f.tellg();
		char* buffer;
		buffer = (char*) malloc(msglength*sizeof(char));	
		f.seekg(0, std::ios::beg);
		f.read(buffer, msglength);
		f.close();
		if (flag == "-d") decrypt(password,buffer,msglength,output);
		else if (flag == "-e") encrypt(password,buffer,msglength,output);
		else cout << "Error: bad flag\n";
		delete [] buffer;
	}
}
