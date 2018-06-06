#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
using namespace std;

//pi.first is row, pi.second is type
//0 is top row, 1 is bottom row
//0 is polite, 1 is stubborn
typedef pair<int,int> pi;

int m, n, iteration;
//m is number of As
//n is number of Bs
char cc[1000];

//arrays of A and B
//A.front() is first person going east, B.front is first person going west
vector<int> A, B;

map<pi,int> ma;

//returns either 0 or 1 randomly
int randbool(){
    //srand((unsigned)time( NULL ));
	long long t = rand();
	//cout << t << endl;
	long long rr = RAND_MAX;
	if (2*t < rr) return 0;
	else return 1;
}

//increase the counter of aindex meeting bindex
void incre(int aindex, int bindex){
	if (ma.find(make_pair(aindex, bindex)) == ma.end()){
		ma[make_pair(aindex, bindex)] = 1;
	} else {
		ma[make_pair(aindex, bindex)] = ma[make_pair(aindex, bindex)] + 1;
	}
}

int main(){

	/*
	for (int i = 0; i < 5; i++){
		cout << (double)rand()/RAND_MAX << endl;
	}
	*/
	printf("Enter m and n, the number of As and Bs respectively: ");
	scanf("%d%d", &m, &n);
	printf("Enter the number of iterations: ");
	scanf("%d", &iteration);
	printf("Enter file name to store results: ");
	scanf("%s", &cc);
	FILE * pFile;
	pFile = fopen(cc, "w");
	
	
	for (int ct = 0; ct < iteration; ct++){
		A.clear();
		B.clear();
		for (int i = 0; i < m; i++){
			A.push_back(randbool());
		}
		for (int i = 0; i < n; i++){
			B.push_back(randbool());
		}
		//simulation
		for (int j = 0; j < A.size(); j++){
			//A goes through B
			for (int k = 0; k < B.size(); k++){
				if (A[j] != B[k]){
					//no collision
					continue;
				} else { //collision
					int aa = randbool();
					incre(j, k);
					if (aa){
						A[j] = 1 - B[k];
					} else {
						B[k] = 1 - A[j];
					}
				}
			}
		}
	}
	
	//print out stats
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			fprintf(pFile, "%d %d %lf\n", i + 1, j + 1, (double)ma[make_pair(i, j)]/(double)iteration);
		}
	}
	fclose(pFile);
	
	
}
