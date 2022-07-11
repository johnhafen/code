#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class heap{
	
	private:
		
		T *A;
		int heapsize;
		
		int getparent(int i)
		{
			return i/2;
		}
		
		int getleft(int i)
		{
			return i*2;
		}
		
		int getright(int i)
		{
			return i*2+1;
		}
	public:
		
		heap(){
			heapsize=0;
		}
		
		void MIN_HEAPIFY(int i)
		{
			
			int l=getleft(i);
			int r=getright(i);
			int min;
			if(l<=heapsize && A[l]<A[i]){
				min=l;
			}
			else min=i;
			
			if(r<=heapsize && A[r]<A[min]){
				min=r;
			}
			
			if(min!=i){
				T v=A[i];
				A[i]=A[min];
				A[min]=v;
				MIN_HEAPIFY(min);
			}
		}
		
		void BUILD_MINHEAP(T *a,int dim){
			A=a;
			heapsize=dim;
			for(int i=heapsize/2; i>=1; i--){
				MIN_HEAPIFY(i);
			}
		}
		
		void print(ofstream &out){
			for(int i=1; i<=heapsize; i++){
				out<<A[i]<<" ";
			}
			out<<endl;
		}
	
};

int main() {
	ifstream in("input.txt");
    ofstream out("output.txt");
	
	for(int j=0; j<100; j++){
		string type;
		in>>type;
		int N;
		in>>N;
		
		if(type=="int"){
			int *A=new int[N*2];
			heap <int> *t=new heap<int>();
			
			for(int i=1; i<=N; i++){
				int tmp;
				in>>tmp;
				A[i]=tmp;
			}
			t->BUILD_MINHEAP(A,N);
			t->print(out);
			delete t;
			delete []A;
		}
		
	    else if(type=="double"){
			double *A=new double[N*2];
			heap <double> *t=new heap<double>();
			
			for(int i=1; i<=N; i++){
				double tmp;
				in>>tmp;
				A[i]=tmp;
			}
			t->BUILD_MINHEAP(A,N);
			t->print(out);
			delete []A;
			delete t;
		}
		
		else if(type=="bool"){
			bool *A=new bool[N*2];
			heap <bool> *t=new heap<bool>();
			
			for(int i=1; i<=N; i++){
				bool tmp;
				in>>tmp;
				A[i]=tmp;
			}
			t->BUILD_MINHEAP(A,N);
			t->print(out);
			delete []A;
			delete t;
		}
		
		else if(type=="char"){
			char *A=new char[N*2];
			heap <char> *t=new heap<char>();
			
			for(int i=1; i<=N; i++){
				char tmp;
				in>>tmp;
				A[i]=tmp;
			}
			t->BUILD_MINHEAP(A,N);
			t->print(out);
			delete []A;
			delete t;
		}
	}
}


