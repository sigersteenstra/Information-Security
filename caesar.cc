#include <iostream>
#include <fstream>
#include <string.h>

/* This simple C program uses a Caesar cipher to encrypt a text.
 * it requires an integer shift and an input file.
 * You can decrypt by using the integer counterpart
 * (count back from 26).
 */

using namespace std;

int main(int argc, char *argv[])
{
	int shift = stoi(argv[1])%26;
	ifstream f;
	f.open(argv[2]);
	f.seekg(0, std::ios::end);
	int length = f.tellg();
	char* buffer;
	buffer = (char*) malloc(length*sizeof(char));	
	f.seekg(0, std::ios::beg);
	f.read(buffer, length);
	f.close();
	int current;
	for(int i=0; i<length-1; i++){
		current=buffer[i];
		if(buffer[i]!=' '){
			current+=shift;
			if (current>122) current-=26;
		}
		char cipher = current;
		cout << cipher;
	}
	cout << '\n';
	delete [] buffer;
}
