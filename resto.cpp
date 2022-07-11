#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

void resto(int *vett,int r, int n, ofstream&out){
     int table[r+1];
     
     table[0]=0;
     
     for(int i=1; i<r+1; i++){
        table[i]=INT_MAX;
     }
     
     for(int i=1; i<r+1; i++){
        for(int j=0; j<n; j++){
           if(vett[j]<=i){
              int sub_res=table[i-vett[j]];
              if(sub_res!=INT_MAX && sub_res+1<table[i]){
                table[i]=sub_res+1;
              }
           }
        }
     }
     
     out<<table[r]<<endl;
}



int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int task=0; task<100; task++){
       int R; in>>R;
       int N; in>>N;
       
       int *vett=new int[N];
       for(int i=0; i<N; i++){
          int x; in>>x;
          vett[i]=x;
       }
       
       resto(vett,R,N,out);
    }
}
