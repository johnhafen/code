#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class terna{
	private:
		T uno, due, tre;
	public:
		terna(){
			uno=NULL;
			due=NULL;
			tre=NULL;
		}
		
		void set_uno(T x){
			uno=x;
		}
		void set_due(T y){
			due=y;
		}
		void set_tre(T z){
			tre=z;
		}
		
		T get_uno(){
			return uno;
		}
		
		T get_due(){
			return due;
		}
		
		T get_tre(){
			return tre;
		}
};

template<class H>
class Heap:public terna<H>{
	private:
		terna<H> **vett;
		int heapsize,call,k;
		
		int p(int i){
			return i/2;
		}
		int L(int i){
			return i*2;
		}
		int R(int i){
			return i*2+1;
		}
	public:
		Heap(int n){
			heapsize=n;
			k=heapsize;
			call=0;
			vett=new terna<H>*[heapsize];
		}
		
		void buildmax(terna<H> **e){
			vett=e;
			for(int i=heapsize/2; i>0; i--){
				max_heapify(i);
			}
		}
		
		void max_heapify(int i){
			if(heapsize>=1){
				call++;
			}
			int l=L(i);
			int r=R(i);
			int max=i;
			if(l<=heapsize){
			    H x1L=vett[l]->get_uno();
			    H y1L=vett[l]->get_due();
			    H z1L=vett[l]->get_tre();
			    if(l<=heapsize && ((x1L>vett[max]->get_uno()) || (x1L==vett[max]->get_uno() && y1L>vett[max]->get_due()) || (x1L==vett[max]->get_uno() && y1L==vett[max]->get_due() && z1L>vett[max]->get_tre()))){
				    max=l;
			    }
	    	}
			if(r<=heapsize){
			    H x2R=vett[r]->get_uno();
			    H y2R=vett[r]->get_due();
			    H z2R=vett[r]->get_tre();
			    if(r<=heapsize && ((x2R>vett[max]->get_uno()) || (x2R==vett[max]->get_uno() && y2R>vett[max]->get_due()) || (x2R==vett[max]->get_uno() && y2R==vett[max]->get_due() && z2R>vett[max]->get_tre()))){
				    max=r;
			    }
		    }
		
			if(max!=i){
				swap(vett[i],vett[max]);
				max_heapify(max);
			}
		}
		
		void heapsort(){
			for(int i=heapsize; i>=2; i--){
				swap(vett[1],vett[i]);
				heapsize--;
				max_heapify(1);
			}
		}
		
		void print(ofstream& out){
			out<<call<<" ";
			for(int i=1; i<=k; i++){
				out<<"("<<vett[i]->get_uno()<<" "<<vett[i]->get_due()<<" "<<vett[i]->get_tre()<<") ";
			}
			out<<endl;
		}
};

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	for(int task=0; task<100; task++){
		string type;
		in>>type;
		int N;
		in>>N;
		
		if(type=="int"){
			Heap<int> *h=new Heap<int>(N);
			terna<int> **t=new terna<int>*[N];
			for(int i=1; i<=N; i++){
				char tmp;
				in>>tmp;
				int x,y,z;
				in>>x;
				in>>y;
				in>>z;
				in>>tmp;
				terna<int> *e=new terna<int>();
				e->set_uno(x);
				e->set_due(y);
				e->set_tre(z);
				t[i]=e;
			}
			h->buildmax(t);
			h->heapsort();
			h->print(out);
		}
		if(type=="bool"){
			Heap<bool> *h=new Heap<bool>(N);
			terna<bool> **t=new terna<bool>*[N];
			for(int i=1; i<=N; i++){
				char tmp;
				in>>tmp;
				bool x,y,z;
				in>>x;
				in>>y;
				in>>z;
				in>>tmp;
				terna<bool> *e=new terna<bool>();
				e->set_uno(x);
				e->set_due(y);
				e->set_tre(z);
				t[i]=e;
			}
			h->buildmax(t);
			h->heapsort();
			h->print(out);
		}
	
		if(type=="double"){
			Heap<double> *h=new Heap<double>(N);
			terna<double> **t=new terna<double>*[N];
			for(int i=1; i<=N; i++){
				char tmp;
				in>>tmp;
				double x,y,z;
				in>>x;
				in>>y;
				in>>z;
				in>>tmp;
				terna<double> *e=new terna<double>();
				e->set_uno(x);
				e->set_due(y);
				e->set_tre(z);
				t[i]=e;
			}
			h->buildmax(t);
			h->heapsort();
			h->print(out);
		}
		
		if(type=="char"){
			Heap<char> *h=new Heap<char>(N);
			terna<char> **t=new terna<char>*[N];
			for(int i=1; i<=N; i++){
				char tmp;
				in>>tmp;
				char x,y,z;
				in>>x;
				in>>y;
				in>>z;
				in>>tmp;
				terna<char> *e=new terna<char>();
				e->set_uno(x);
				e->set_due(y);
				e->set_tre(z);
				t[i]=e;
			}
			h->buildmax(t);
			h->heapsort();
			h->print(out);
		}
	}
}
