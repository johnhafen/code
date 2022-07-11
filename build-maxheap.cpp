#include <stdio.h>
#include <fstream>

using namespace std;

template <class T>
class Heap{
	private:
		int heapsize;
		T* A;
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
    	Heap(){
    		heapsize=0;
		}
    	
        void max_heapfy(T *a, int i){
        	A=a;
        	
    		int l=left(i);
    		int r=right(i);
    		int max;
    	
    		if(l<=heapsize && A[l]>A[i]){
    			max=l;
			}
			else max=i;
			
			if(r<=heapsize && A[r]>A[max]){
				max=r;
			}
			
			if(max!=i){
				T v=A[i];
				A[i]=A[max];
				A[max]=v;
				max_heapfy(A,max);
			}
			
		}
		
		void Build_maxheap(T *a, int dim){
			heapsize=dim;
			for(int i=dim/2; i>0; i--){
				max_heapfy(a,i);
			}
		}
		
		void print(ofstream &out){
			
			for(int i=1; i<=heapsize; i++){
				out << A[i] << "\t";
			}
			out << "\n";
		}
};

int main(){
	ifstream in("input.txt");
    ofstream out("output.txt");
	
	for(int task=0; task<100; task++){
		string type;
		int n;
		in>>type;
		in>>n;
		
		if(type=="int"){
			int *A=new int[n*2];
			Heap<int>* t = new Heap<int>();
	        int tmp;
            for(int i=1; i<=n; i++){
    	       in>>tmp;
    	       A[i]=tmp;
	        }
	        t->Build_maxheap(A,n);
	        t->print(out);
	        delete t;
            delete []A;
		}
		else if(type=="bool"){
			bool *A=new bool[n*2];
			Heap<bool>* t = new Heap<bool>();
	        bool tmp;
            for(int i=1; i<=n; i++){
    	       in>>tmp;
    	       A[i]=tmp;
	        }
	        t->Build_maxheap(A,n);
	        t->print(out);
	        delete t;
            delete []A;
		}
		else if(type=="double"){
			double *A=new double[n*2];
			Heap<double>* t = new Heap<double>();
	        double tmp;
            for(int i=1; i<=n; i++){
    	       in>>tmp;
    	       A[i]=tmp;
	        }
	        t->Build_maxheap(A,n);
	        t->print(out);
	        delete t;
            delete []A;
		}
		else if(type=="char"){
			char *A=new char[n*2];
			Heap<char>* t = new Heap<char>();
	        char tmp;
            for(int i=1; i<=n; i++){
    	       in>>tmp;
    	       A[i]=tmp;
	        }
	        t->Build_maxheap(A,n);
	        t->print(out);
	        delete t;
            delete []A;
		}
	}
	
	//fine
}





