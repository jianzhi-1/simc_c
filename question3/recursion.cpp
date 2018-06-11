#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
using namespace std;
long double p[100000];
char cc[1000];
long double cone = ((long double)1.0/(long double)6.0);
long double ctwo = ((long double)1.0/(long double)12.0);
long double cthree = ((long double)1.0/(long double)4.0);
long double cfour = ((long double)1.0/(long double)3.0);
long double cfive = (long double)1.0;
long double expo(long double a, int b){
	if (b == 0) return (long double)(1.0);
	if (b == 1) return a;
	long double half = expo(a, b/2);
	if (b % 2 == 0) return half*half;
	else return half*half*a;
}
int main(){
	printf("Enter file name to store results: ");
	scanf("%s", &cc);
	FILE * pFile;
	pFile = fopen(cc, "w");
	p[0] = 1;
	for (int i = 1; i < 1000; i++){
		p[i] = (cone + ctwo*expo(cthree, i)) + cfour*(cfive-cthree*expo(cthree, i))*p[i - 1];
		fprintf(pFile, "%d %Lf\n", i, p[i]);
	}
	fclose(pFile);
	
}
