#include <iostream>
#include <fstream>
using namespace std;

template<class T>
class Heap{
	private:
		T *A;
		int heapsize;
		
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
			A=new T[dim];
		}
		void decrease_key(T x){
			int i=heapsize;
    	                if(x>A[i]){
    	    	            return;
			}
    	    
			while(i>1 && A[parent(i)]>A[i]){
				swap(A[parent(i)],A[i]);
				i=parent(i);
			}
	        }
		void Insert(T x){
			heapsize++;
			A[heapsize]=x;
			decrease_key(x);
		}
		
		void print(ofstream &out){
            for(int i = 1; i <= heapsize; i++){
               out << A[i] << " ";
            }
          out << endl;
        }

};

int main() {
	ifstream in("input.txt");
    ofstream out("output.txt");

	for(int task=0; task<100; task++){
		string type; in>>type;
		int N; in>>N;
		if(type=="int"){	
	        Heap<int> *t=new Heap<int>(N*2);
	        for(int i=1; i<=N; i++){
	   	        int tmp;
		        in>>tmp;
		        t->Insert(tmp);
	        }
	        t->print(out);
	        delete t;
	    }
	    
	    else if(type=="double"){	
	        Heap<double> *t=new Heap<double>(N*2);
	        for(int i=1; i<=N; i++){
	   	        double tmp;
		        in>>tmp;
		        t->Insert(tmp);
	        }
	        t->print(out);
	        delete t;
	    }
	    else if(type=="bool"){	
	        Heap<bool> *t=new Heap<bool>(N*2);
	        for(int i=1; i<=N; i++){
	   	        bool tmp;
		        in>>tmp;
		        t->Insert(tmp);
	        }
	        t->print(out);
	        delete t;
	    }
	    else if(type=="char"){	
	        Heap<char> *t=new Heap<char>(N*2);
	        for(int i=1; i<=N; i++){
	   	        char tmp;
		        in>>tmp;
		        t->Insert(tmp);
	        }
	        t->print(out);
	        delete t;
	    }
	   
    }
}
