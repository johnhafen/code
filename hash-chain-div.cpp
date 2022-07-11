#include <iostream>
#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

template <class H>
void Hash(int m, int n, H* A){
	int k[m];

	for(int i=0; i<m; i++)
		k[i]=0;

	for(int i=0; i<n; i++){
		int j=((int)A[i])%m;
		k[j]++;
	}

	for(int i=0; i<m; i++)
		out<<k[i]<<" ";
	out<<endl;
}

int main(){
for(int i=0; i<100; i++){
	string type;
	int m, n;

	in>>type>>m>>n;

	if(type=="int" || type=="bool"){
		int* A=new int[n];
		for(int j=0; j<n; j++){
			int val; 
			in>>val;
			A[j]=val;
		}
		Hash(m, n, A);
	}
	else if(type=="double"){
		double* A=new double[n];
		for(int j=0; j<n; j++){
			double val;
			in>>val;
			A[j]=val;
		}
		Hash(m, n, A);
	}
	else if(type=="char"){
		char* A=new char[n];
		for(int j=0; j<n; j++){
			char val;
			in>>val;
			A[j]=val;
		}
		Hash(m, n, A);
	}
}
}