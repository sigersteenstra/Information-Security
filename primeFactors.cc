#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

void printVec(vector<int> vector, int p){
	if (vector.size()==0){
		cout << "no prime factors for " << p << "!\n";
	} else{
		cout << "Prime factors of " << p << ":\n";
		int i;
		for(i=0;i<vector.size()-1;i++){
			cout << vector[i] << ", ";
		}
		cout << vector[i] << ".\n";
	}
}
		

int isPrime2(int p, int n){
	if (p<n*n) return 1;
	if (n==2 && p%n==0) return 0;
	if (n==2 && p%n==1) return isPrime2(p,3);
	if (p%n==0) return 0;
	if (p%n>0) return isPrime2(p,n+2);
}

int isPrime(int p){
	//returns 1 if p is a prime, otherwise 0.
	//makes use of the above helper-function
	if (p==1) return 0;
	else return isPrime2(p,2);
}

vector<int> primeFactors (int p){
	// returns a vector with the prime factors of p
	vector<int> qs;
	int i;
	for(i=2;i<=p/2;i+=2){
		if (p%i==0 && isPrime(i)) qs.push_back(i);
		if(i==2) i--;
	}
	printVec(qs,p);
	return qs;
}

int main(int argc, char *argv[]){
	if (argc!=2) cout << "provide a number\n";
	else{
		int p = stoi(argv[1]);
		vector<int> qs = primeFactors(p);
		// vector qs is returned so it can be used
		// for further coding.
	}
}
