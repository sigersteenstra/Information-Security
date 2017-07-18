#include <iostream>
#include <string.h>
#include <math.h>

/* This program finds all positive solutions for a
 * linear diophantine equation, like the beetle and spider problem.
 * "I have a jar in which only spiders and beetles occur.
 * Assume spiders have 8 legs, beetles have 6, and none of
 * the bugs are mutilated. If there are 56 legs in the jar, how many
 * spiders and how many beetles are there?"
 * To answer this question, we will have to solve
 * 8x+6y=56, which yields multiple solutions.
 * This program finds them all.
 */

using namespace std;

void diophantine(int x, int y, int u, int v){ 
	//Finds all (positive) solutions using linear diophantine equations,
	//and then prints them on the screen.
	while(y >= 0){
		cout << "x = " << x << " and y = " << y << "\n";
		x+=v;
		y-=u;
	}
}

void findSolution(int a, int b, int c, int* xy){
	//Finds only one solution,
	//the solution with the lowest x and highest y value.
	int x=0;	//x counter
	int y=0;	//y counter
	int found=0;
	while (found==0){
		if(c%b==0){
			found=1;
			y = c/b;
		} else {
			c-=a;
			x++;
		}
	}
	xy[0]=x;    //copy x value to array pointer
	xy[1]=y;	//copy y value to array pointer
}

int gcd(int a, int b){ 
	//function to compute the greatest common divisor
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char *argv[]){
	if (argc != 4){
		cout << "In the formula: ax+by=c, please enter a, b and c.\n";
		return -1;
	} else {
		int a = stoi (argv[1]);
		int b = stoi (argv[2]);
		int c = stoi (argv[3]);
		int div = gcd(a,b);
		int* xy = (int*) malloc(2*sizeof(int));
		if (c % div == 0 && c>=min(a,b)) {
			findSolution(a,b,c,xy);
			//cout << xy[0] << "  " << xy[1] << "\n";
			int u=a/div;	// parameters u and v for the linear diophantine equations are calc-
			int v=b/div;	// ulated here so a and b don't have to be passed to diophantine.
			cout << "Solutions for the system: " << a << "*x + " << b << "*y = " << c << ":\n";
			diophantine(xy[0],xy[1],u,v);
		}
		else cout << "No solutions\n";
		free(xy);
	}
}
