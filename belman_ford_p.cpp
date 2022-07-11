#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

class edge{
    protected:
    int s,f,peso;
    public:
    edge(int x, int y, int p){
        s=x;
        f=y;
        peso=p;
    }

    int gets(){return s;}
    int getf(){return f;}
    int getpeso(){return peso;}
};

class grafo{
    protected:
    int len, n, m;
    edge **M;

    public:
    grafo(int N){
        n=N;
        len=1000;
        m=0;
        M=new edge*[len];
        for(int i=0; i<len; i++){
            M[i]=NULL;
        }
    }

    ~grafo(){
        for(int i=0; i<m; i++){
            delete M[i];
        }
        delete [] M;
    }

    void addedge(int x, int y, int p){
        M[m]=new edge(x,y,p);
        m++;
    }

    void belman_ford(int s, int f, int k, ofstream& out){
        int dist[n];
        for(int i=0; i<n; i++){
            dist[i]=INT_MAX;
        }
        dist[s]=0;

        for(int i=1; i<k+1; i++){
            for(int j=0; j<m; j++){
                if(M[j]!=NULL){
                    int u=M[j]->gets();
                    int v=M[j]->getf();
                    int w=M[j]->getpeso();
                    if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                        dist[v]=dist[u]+w;
                    }
                }
            }
        }

        if(dist[f]==INT_MAX){
            out<<"inf."<<endl;
        }
        else{
            out<<dist[f]<<endl;
        }
    }
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int task=0; task<100; task++){
        int N, M, K;
        in>>N;
        in>>M;
        in>>K;
        grafo *g=new grafo(N);
        for(int i=0; i<M; i++){
            char tmp; in>>tmp;
            int x,y,p;
            in>>x;
            in>>y;
            in>>p;
            in>>tmp;
            g->addedge(x,y,p);
        }
        int s,f;
        in>>s;
        in>>f;
        g->belman_ford(s,f,K,out);
        delete g;
    }
}