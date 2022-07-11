#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class terna{
      private:
      H x, y, z;

      public:
      terna(H x, H y, H z){
        this->x=x;
        this->y=y;
        this->z=z;
      } 

      H getx(){
          return x;
      }
      H gety(){
          return y;
      }
      H getz(){
          return z;
      }
};

template<class H>
H massimo(terna<H> **v,int n){
    int max=1;
    for(int i=2; i<=n; i++){
        if(v[i]->getx()>v[max]->getx()){
            max=i;
        }
    }
    return v[max]->getx();
}

template<class H>
H minimo(terna<H> **v, int n){
    int min=1;
    for(int i=2; i<=n; i++){
        if(v[i]->getx()<v[min]->getx()){
            min=i;
        }
    }
    return v[min]->getx();
}

void counting(terna<double> **v, int n, ofstream& out){
     terna<int> **p=new terna<int>*[n+1];
     for(int i=1; i<=n; i++){
         int x=((int) (v[i]->getx()*10));
         int y=((int) (v[i]->gety()*10));
         int z=((int) (v[i]->getz()*10));
         terna<int> *e=new terna<int>(x,y,z);
         p[i]=e;
     }
     int max=massimo(p,n);
     int min=minimo(p,n);
     int k=max-min+1;
     int C[k+1];
     for(int i=0; i<=k; i++){
         C[i]=0;
     }

     for(int i=1; i<=n; i++){
         C[p[i]->getx()-min+1]++;
     }

     for(int i=2; i<=k; i++){
         C[i]=C[i]+C[i-1];
     }

     terna<double> **B=new terna<double>*[n+1];
     for(int i=n; i>=1; i--){
         double x=((double) (p[i]->getx()/10.0));
         double y=((double) (p[i]->gety()/10.0));
         double z=((double) (p[i]->getz()/10.0));
         terna<double> *e=new terna<double>(x,y,z);
         B[C[p[i]->getx()-min+1]]=e;
         C[p[i]->getx()-min+1]--;
     }
     for(int i=1; i<=k; i++){
         out<<C[i]<<" ";
     }
     for(int i=1; i<=n; i++){
         out<<"("<<B[i]->getx()<<" "<<B[i]->gety()<<" "<<B[i]->getz()<<") ";
     }
     out<<endl;
     delete []p;
     delete []B;
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int task=0; task<100; task++){
        int N; in>>N;
        terna<double> **A=new terna<double>*[N+1];
        for(int i=1; i<=N; i++){
            char tmp; in>>tmp;
            double x,y,z;
            in>>x;
            in>>y;
            in>>z;
            in>>tmp;
            terna<double> *e=new terna<double>(x,y,z);
            A[i]=e;
        }
        counting(A,N,out);
    }
}