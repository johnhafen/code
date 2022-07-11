#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void matrix_chain(int *p, int N, ofstream& out){
    int M[N][N];

    for(int i=1; i<N; i++){
        M[i][i]=0;
    }

    for(int l=2; l<N; l++){
        for(int i=1; i<N-l+1; i++){
            int j=i+l-1;
            M[i][j]=INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q=M[i][k]+M[k+1][j]+p[i-1]*p[k]*p[j];

                if(q<M[i][j]){
                    M[i][j]=q;
                }
            }
        }
    }
    out<<M[1][N-1]<<endl;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task=0; task<100; task++){
        int N; in>>N;
        int *p=new int[N+1];
        int x, y;
        for(int i=0; i<N; i++){
            char tmp; in>>tmp;
            in>>x;
            p[i]=x;
            in>>tmp;
            in>>y;
            in>>tmp;
        }
        p[N]=y;
        matrix_chain(p,N+1,out);
        delete [] p;
    }
}