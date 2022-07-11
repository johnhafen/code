#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

template<class H>
class edge{
    protected:
    H s, f, peso;
    public:
    edge(H x, H y, int p){
        s=x;
        f=y;
        peso=p;
    }

    H gets(){return s;}
    H getf(){return f;}
    int getpeso(){return peso;}
};


template<class H>
class grafo{
    protected:
    int len, n ,m,dim;
    H *K;
    edge<H> **M;

    int findindex(H x){
        for(int i=0; i<len; i++){
            if(K[i]==x){
                return i;
            }
        }
        return -1;
    }
    H getmin(int i){
        dim--;
        return K[i];
    }

    public:
    grafo(){
        len=1000;
        dim=n=m=0;
        M=new edge<H>*[len];
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
        dim++;
    }

    void addedge(H x, H y, int p){
        M[m]=new edge<H>(x,y,p);
        m++;
    }

    void Dijkstra(H s, H f, ofstream& out){
        int dist[n];
        int sorgente=findindex(s);
        int dest=findindex(f);

        for(int i=0; i<n; i++){
            dist[i]=INT_MAX;
        }

        dist[sorgente]=0;
        int t=0;
        while(dim>0){
            for(int i=t; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(dist[i]>dist[j]){
                        swap(dist[i],dist[j]);
                        swap(K[i],K[j]);
                    }
                }
            }
            H sorg=getmin(t);
            t++;
            for(int j=0; j<m; j++){
                if(M[j]!=NULL && M[j]->gets()==sorg){
                    H u=M[j]->gets();
                    H v=M[j]->getf();
                    H w=M[j]->getpeso();
                    int index=findindex(u);
                    int indey=findindex(v);
                    if(dist[index]!=INT_MAX && dist[index]+w<dist[indey]){
                        dist[indey]=dist[index]+w;
                    }
                }
            }
        }
         dest=findindex(f);
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
            g->Dijkstra(s,f,out);
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
            g->Dijkstra(s,f,out);
            delete g;
        }
    }
}


