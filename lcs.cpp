#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void LCS(string x, string y, int n, int m, ofstream& out){
     int** M=new int*[n+1];
     for(int i=0; i<n+1; i++){
        M[i]=new int[m+1];
     }
     
     for(int i=0; i<n+1; i++){
        M[i][0]=0;
     }
     
     for(int i=0; i<m+1; i++){
       M[0][i]=0;
     }
     
     for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
           if(x[i-1]==y[j-1]){
             M[i][j]=M[i-1][j-1]+1;
           }
           else{
             M[i][j]=max(M[i-1][j],M[i][j-1]);
           }
        } 
     }
     
     out<<M[n][m]<<endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int task=0; task<100; task++){
       int N; in>>N;
       int M; in>>M;
       string X; in>>X;
       string Y; in>>Y;
       LCS(X,Y,N,M,out);
    }
}
