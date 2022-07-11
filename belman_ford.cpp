#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

class edge{
    protected:
    int s, f, peso;

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

template<class H>
class grafo{
    protected:
    int len, n ,m;
    H *K;
    edge **M;

    int findindex(H x){
        for(int i=0; i<len; i++){
            if(K[i]==x){
                return i;
            }
        }
        return -1;
    }

    public:
    grafo(){
        len=1000;
        n=m=0;
        M=new edge*[len];
        for(int i=0; i<len; i++){
            M[i]=NULL;
        }
        
        K=new H[len];
        for(int i=0; i<len; i++){
            K[i]=-1;
        }
    }

    ~grafo(){
        for(int i=0; i<m; i++){
            delete M[i];
        }
        delete [] M;
        delete [] K;
    }

    void addnodo(H x){
        K[n]=x;
        n++;
    }

    void addedge(H x, H y, int p){
        int i=findindex(x);
        int j=findindex(y);

        M[m]=new edge(i,j,p);
        m++;
    }

    void Belmanford(H s, H f, ofstream& out){
        int dist[n];
        int sorgente=findindex(s);
        int dest=findindex(f);

        for(int i=0; i<n; i++){
            dist[i]=INT_MAX;
        }

        dist[sorgente]=0;

        for(int i=1; i<n; i++){
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

        for(int i=0; i<m; i++){
            if(M[i]!=NULL){
                int u=M[i]->gets();
                int v=M[i]->getf();
                int w=M[i]->getpeso();

                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    out<<"undef."<<endl;
                    return;
                }
            }
        }

        if(dist[dest]==INT_MAX){
            out<<"inf."<<endl;
        }
        else{
            out<<dist[dest]<<endl;
        }
    }


};

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task=0; task<100; task++){
        int N, M;
        in>>N; in>>M;
        string type; in>>type;

        if(type=="int"){
            grafo<int> *g=new grafo<int>();

            for(int i=0; i<N; i++){
                int x;
                in>>x;
                g->addnodo(x);
            }

            for(int i=0; i<M; i++){
                char tmp; in>>tmp;
                int x; in>>x;
                int y; in>>y;
                int p; in>>p;
                in>>tmp;
                g->addedge(x,y,p);
            }
            int s,f;
            in>>s;
            in>>f;
            g->Belmanford(s,f,out);
            delete g;
        }
        else{
            grafo<double> *g=new grafo<double>();

            for(int i=0; i<N; i++){
                double x;
                in>>x;
                g->addnodo(x);
            }

            for(int i=0; i<M; i++){
                char tmp; in>>tmp;
                double x; in>>x;
                double y; in>>y;
                int p; in>>p;
                in>>tmp;
                g->addedge(x,y,p);
            }
            double s,f;
            in>>s;
            in>>f;
            g->Belmanford(s,f,out);
            delete g;
        }
    }
}