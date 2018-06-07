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

int m, n, iteration, kk;
//m is number of As
//n is number of Bs
char cc[1000];

//arrays of A and B
//A.front() is first person going east, B.front is first person going west
vector<int> A, B;

map<pi,int> ma;
map<pi,int> lanema;

//returns the lane number randomly in the range [0, kkk)
int randnum(int kkk){
    //srand((unsigned)time( NULL ));
	long long t = rand();
	//cout << t << endl;
	long long rr = RAND_MAX;
	for (int i = 0; i < kkk; i++){
		if (t*kkk <= (i+1)*rr){
			//cout << i << endl;
			return i;
		}
	}
}

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
	printf("Enter the number of lanes: ");
	scanf("%d", &kk);
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
			A.push_back(randnum(kk));
		}
		for (int i = 0; i < n; i++){
			B.push_back(randnum(kk));
		}
		//simulation
		for (int j = 0; j < A.size(); j++){
			//A goes through B
			for (int k = 0; k < B.size(); k++){
				if (A[j] != B[k]){
					//no collision
					continue;
				} else { //collision
					int aa = randnum(4);
					incre(j, k);
					if (A[j] == 0 && B[k] == 0){
						aa = randnum(2);
						if (aa == 0){
							A[j] = 1;
						} else {
							B[k] = 1;
						}
					} else if (A[j] == kk - 1 && B[k] == kk - 1){
						aa = randnum(2);
						if (aa == 0){
							A[j] = kk - 2;
						} else {
							B[k] = kk - 2;
						}
					} else {
						aa = randnum(4);
						if (aa == 0){
							A[j] = B[k] - 1;
						} else if (aa == 1){
							A[j] = B[k] + 1;
						} else if (aa == 2){
							B[k] = A[j] - 1;
						} else {
							B[k] = A[j] + 1;
						}
					}
				}
			}
		}
		for (int j = 0; j < A.size(); j++){
			if (lanema.find(make_pair(A[j], 0)) == lanema.end()){
				lanema[make_pair(A[j], 0)] = 1;
			} else {
				lanema[make_pair(A[j], 0)] = lanema[make_pair(A[j], 0)] + 1;;
			}
		}
		for (int j = 0; j < B.size(); j++){
			if (lanema.find(make_pair(B[j], 1)) == lanema.end()){
				lanema[make_pair(B[j], 1)] = 1;
			} else {
				lanema[make_pair(B[j], 1)] = lanema[make_pair(B[j], 1)] + 1;;
			}
		}
	}
	
	//print out stats
	/*
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			fprintf(pFile, "%d %d %lf\n", i + 1, j + 1, (double)ma[make_pair(i, j)]/(double)iteration);
		}
	}
	*/
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < kk; j++){
			if (i == 0) fprintf(pFile, "A %d %lf\n", j + 1, (double)lanema[make_pair(j, 0)]/((double)m*(double)iteration));
			else fprintf(pFile, "B %d %lf\n", j + 1, (double)lanema[make_pair(j, 1)]/((double)n*(double)iteration));
		}
	}
	fclose(pFile);
	
	
}
