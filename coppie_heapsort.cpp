#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

template<class H>
class Element{
      private:
        H x;
        H y;
      public:
      Element(){
      }
      
      H get_x(){
        return x;
      }
      
      H get_y(){
        return y;
      }
      
      void set_x(H xx){
         x=xx;
      }
      void set_y(H yy){
         y=yy;
      }
};

template<class H>
class Heap:public Element<H>{
      private:
          Element<H> **A;
          int heapsize;
          int N, call;
      public:
          Heap(int n){
             N=n;
             A=new Element<H>*[N];
             heapsize=n;
             call=0;
          }
          
          int getL(int i){
              return i*2;
          }
          
          int getR(int i){
              return i*2+1;
          }
          
          int getP(int i){
              return i/2;
          }
          
          void maxheapify(int i){
             if(N>=1){
                call++;
             }
             int l=getL(i);
             int r=getR(i);
             int max=i;
             H x1,x2, y1, y2;
             if(l>=1 && l<=N){
               x1=A[l]->get_x();
               y1=A[l]->get_y();
             }
             if(r>=1 && r<=N){
                x2=A[r]->get_x();
                y2=A[r]->get_y();
             }
             if(l<=N && ((x1>A[max]->get_x()) || (x1==A[max]->get_x() && y1>A[max]->get_y()))){
                max=l;
             }
             
             if(r<=N && ((x2>A[max]->get_x()) || (x2==A[max]->get_x() && y2>A[max]->get_y()))){
                max=r;
             }
             
             if(max!=i){
               swap(A[i],A[max]);
               maxheapify(max);
             }
             
          }
          
          void build_maxheap(Element<H> **v){
               A=v;
               for(int i=N/2; i>=1; i--){
                  maxheapify(i);
               }
          }
          
          void heapsort(){
               for(int i=N; i>=2; i--){
                  swap(A[1],A[i]);
                  N--;
                  maxheapify(1);
               }
          }
          
          void print(ofstream& out){
               out<<call<<" ";
               for(int i=1; i<=heapsize; i++){
                  out<<"("<<A[i]->get_x()<<" "<<A[i]->get_y()<<") ";
               }
               out<<endl;
          }
          
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int task=0; task<100; task++){
       string type; in>>type;
       int N; in>>N;
    
       if(type=="int" || type=="bool"){
          Heap<int> *H=new Heap<int>(N);
          Element<int> **v=new Element<int>*[N];
          for(int i=1; i<=N; i++){
             char tmp; in>>tmp;
             int x,y;
             in>>x;
             in>>y;
             in>>tmp;
             Element<int> *E=new Element<int>();
             E->set_x(x);
             E->set_y(y);
             v[i]=E;
          }
          H->build_maxheap(v);
          H->heapsort();
          H->print(out);
          delete []v;
          delete H;
       }
       
       if(type=="double"){
          Heap<double> *H=new Heap<double>(N);
          Element<double> **v=new Element<double>*[N+1];
          for(int i=1; i<=N; i++){
             char tmp; in>>tmp;
             double x,y;
             in>>x;
             in>>y;
             in>>tmp;
             Element<double> *E=new Element<double>();
             E->set_x(x);
             E->set_y(y);
             v[i]=E;
          }
          H->build_maxheap(v);
          H->heapsort();
          H->print(out);
          delete []v;
          delete H;
       }
       
       if(type=="char"){
          Heap<char> *H=new Heap<char>(N);
          Element<char> **v=new Element<char>*[N];
          for(int i=1; i<=N; i++){
             char tmp; in>>tmp;
             char x,y;
             in>>x;
             in>>y;
             in>>tmp;
             Element<char> *E=new Element<char>();
             E->set_x(x);
             E->set_y(y);
             v[i]=E;
          }
          H->build_maxheap(v);
          H->heapsort();
          H->print(out);
          delete []v;
          delete H;
       }
    }
}
