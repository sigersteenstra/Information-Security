#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

void printIntVec(vector<int> v){
	//prints an integer vector
	if (v.size()>0){
		int i;
		cout << "[";
		for(i=0;i<v.size()-1;i++){
			cout << v[i] << ",";
		}
		cout << v[i] << "]\n";
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
	//makes use of the above smart helper-function
	if (p==1) return 0;
	else return isPrime2(p,2);
}

vector<int> primeFactors (int p){
	// returns a vector with the prime factors of p
	vector<int> qs;
	int i,x;
	x=p-1;
	for(i=2;i<p/2;i+=2){
		if (x%i==0 && isPrime(i)) qs.push_back(i);
		if(i==2) i--;
	}
	return qs;
}

int gcd(int p, int q){ 
	//function to compute the greatest common divisor
	//returns the integer value of the gcd.
	return q == 0 ? p : gcd(q, p % q);
}

int relativePrime(int p, int q){
	// function to compute whether p and q are relative prime
	// This means that they have no common denominators.
	// returns 1 if true, 0 if false.
	return gcd(p,q) == 1 ? 1 : 0;
}

int totient(int p){
	int counter=0;
	for(int i=p-1;i>0;i--) if (relativePrime(p,i)==1) counter++;
	return counter;
}

int modularInverse2(int x, int m, int n){
	if (x>n) return 0;
	else return (x*m)%n == 1 ? x : modularInverse2(x+1,m,n);
}

int modularInverse(int m, int n){
	// Computes the modular inverse of m,
	// e.g. the number of times (x) we need to
	// multiply m to obtain (x*m) mod n == 1 mod n.
	if (m==0 || m==2) return 0; //non-existent
	else return m%n == 1 ? 1 : modularInverse2(2,m,n);
}

int myXor(int p, int q){
	// simple xor that returns 0 if p and q are equal, 
	// and 1 if they are not.
	return p==q ? 0 : 1;
}

int fibonacci(int p){
	// this returns the p'th fibonacci number.
	// it's not a very efficient way, because
	// there are a lot of double calculations.
	// However, it is probably the shortest
	// implementation.
	if (p==1) return 0;
	else if (p==2) return 1;
	else return fibonacci(p-2)+fibonacci(p-1);
}

int fibonacci2(int p){
	// a less computationally exhaustive way
	// of computing the p'th fibonacci number.
	// Values are stored in a vector, and this
	// requires less computation than the
	// recursive version above.
	vector<int> fibs;
	fibs.push_back(0);
	fibs.push_back(1);
	for(int i=2;i<p;i++){
		fibs.push_back(fibs[i-2]+fibs[i-1]);
	}
	return fibs[p-1];
}

int fermat(int p, int a){
	// fermat's little theorem says that if
	// p is prime, for any number a, a^p-a
	// is an integer multiple of p.
	// This function computes that multiple.
	return (int)(pow(a,p)-a)/p;
}

int main(int argc, char *argv[]){
	//cout << fibonacci(42) << "\n";
	//cout << fibonacci2(42) << "\n";
	cout << fermat(7,2) << "\n";
}
