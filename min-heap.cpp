#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
using namespace std;

template<class H>
class Heap{
	private:
		H *vett;
		int heapsize;
		int call;
	    
	    int parent(int i){
	    	return i/2;
		}
		
		int left(int i){
			return i*2;
		}
		
		int right(int i){
			return i*2+1;
		}
	public:
		Heap(int dim){
			heapsize=0;
			call=0;
			vett=new H[dim];
		}
		
		~Heap(){delete [] vett;}
		
		void min_heapify(int i){
			if(heapsize>=1){
				call++;
			}
			int l=left(i);
			int r=right(i);
			int min=i;
			
			if(l<=heapsize && vett[l]<vett[min]){
				min=l;
			}
			
			if(r<=heapsize && vett[r]<vett[min]){
				min=r;
			}
			
			if(min!=i){
				swap(vett[min],vett[i]);
				min_heapify(min);
			}
		}
		
		void extract(){
			swap(vett[1],vett[heapsize]);
			heapsize--;
			min_heapify(1);
		}
		
		void decrease_key(H x){
		    int i=heapsize;
		    while(i>1 && vett[parent(i)]>vett[i]){
		    	swap(vett[parent(i)],vett[i]);
		    	i=parent(i);
			}
		}
		
		void enqueue(H x){
			heapsize++;
			vett[heapsize]=x;
			decrease_key(x);
		}
		
		int returncall(){
			return call;
		}
		
		void print(ofstream &out){
			for(int i=1; i<=heapsize; i++){
				out<<vett[i]<<" ";
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
			Heap<int> *t=new Heap<int>(N);
			
			for(int i=0; i<N; i++){
				string s;
				in>>s;
				if(s=="extract"){
					t->extract();
				}
				else{
					stringstream ss;
					string c=s.substr(2);
					int b;
					ss<<c;
					ss>>b;
					t->enqueue(b);
				}
			}
			int call=t->returncall();
				out<<call<<" ";
				t->print(out);
				delete t;
		}
		if(type=="double"){
			Heap<double> *t=new Heap<double>(N);
			
			for(int i=0; i<N; i++){
				string s;
				in>>s;
				if(s=="extract"){
					t->extract();
				}
				else{
					stringstream ss;
					string c=s.substr(2);
					double b;
					ss<<c;
					ss>>b;
					t->enqueue(b);
				}
			}
			int call=t->returncall();
				out<<call<<" ";
				t->print(out);
				delete t;
		}
		if(type=="bool"){
			Heap<bool> *t=new Heap<bool>(N);
			
			for(int i=0; i<N; i++){
				string s;
				in>>s;
				if(s=="extract"){
					t->extract();
				}
				else{
					stringstream ss;
					string c=s.substr(2);
					bool b;
					ss<<c;
					ss>>b;
					t->enqueue(b);
				}
			}
			int call=t->returncall();
				out<<call<<" ";
				t->print(out);
				delete t;
		}
		if(type=="char"){
			Heap<char> *t=new Heap<char>(N);
			
			for(int i=0; i<N; i++){
				string s;
				in>>s;
				if(s=="extract"){
					t->extract();
				}
				else{
					stringstream ss;
					string c=s.substr(2);
					char b;
					ss<<c;
					ss>>b;
					t->enqueue(b);
				}
			}
			int call=t->returncall();
				out<<call<<" ";
				t->print(out);
				delete t;
		}
	}
}
