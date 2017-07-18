#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

/* This program requires as input an integer.
 * The program then determines its faculty.
 * It runs in to problems quite fast
 * because of integer bounds, but it is
 * meant to show simple recursion.
 */

using namespace std;

int fac(int f){
	if (f==0 || f==1) return 1;
	else return f*fac(f-1);
}

int main(int argc, char *argv[]){
	if (argc!=2) cout << "provide a number\n";
	else{
		int f = stoi(argv[1]);
		int result = fac(f);
		cout << result << "\n";
	}
}
