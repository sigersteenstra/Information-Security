#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

// this code can be used in Cyclic Redundancy Checks
// which were of great importance in Information Security

vector<int> computeCRC(vector<int> bitstream, vector<int> divisor){
	for(int i=0; i<divisor.size()-1; i++) bitstream.push_back(0);
	for(int i=0; i<bitstream.size()-divisor.size();i++){
		if (bitstream[i]==1){
			for(int j=0; j<divisor.size(); j++){
				bitstream[i+j]=bitstream[i+j]^divisor[j];
			}
		}
	}
	vector<int> crc;
	for(int i=bitstream.size()-(divisor.size()-1);i<bitstream.size();i++){
		crc.push_back(bitstream[i]);
	}
	return crc;
}

vector<int> twoPowers(int s){
	vector<int> powers;
	int largest=0;
	while(pow(2,largest+1)<s) largest++;
	for (;largest>=0;largest--){
		if(s-(int) pow(2,largest)>=0){
			s-=(int) pow(2,largest);
			powers.push_back(largest);
		}
	}
	int i;
	return powers;
}

vector<int> binaryString (int p){
	vector<int> powers = twoPowers(p+1);
	vector<int> bs;
	for(int i=powers[0];i>=0;i--){
		if (find (powers.begin(), powers.end(), i) != powers.end()){
			bs.push_back(1);
		} else bs.push_back(0);
	}
	return bs;
}

int main(int argc, char *argv[]){
	
	string bitstring = argv[1];
	string divisor_string = argv[2];
	int lower_bound = 224;
	int upper_bound = 255;
	vector<int> bitstream;
	for(int i=0;i<bitstring.size();i++){
		bitstream.push_back(bitstring[i]-48);
	}
	vector<int> divisor;
	for(int i=0;i<divisor_string.size();i++){
		divisor.push_back(divisor_string[i]-48);
	}
	vector<int> crc = computeCRC(bitstream, divisor);
	cout << "CRC for your entered bitstream and divisor is: ";
	for(int i=0;i<crc.size();i++) cout << crc[i] << ",";
	cout << "\n";
	vector<int> bitstream2;
	for(int i=lower_bound;i<=upper_bound;i++){
		bitstream2 = binaryString(i);
		vector<int> crc2 = computeCRC(bitstream2,divisor);
		if (crc == crc2 && bitstream != bitstream2){
			cout << "Collision: ";
			for(int j=0;j<bitstream2.size();j++){
				cout << bitstream2[j] << ",";
			}
			cout << "\n CRC check: ";
			for(int j=0;j<crc2.size();j++){
				cout << crc2[j] << ",";
			}
			cout << "\n";
		}
	}
}
