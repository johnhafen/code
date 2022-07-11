#include <iostream>
#include <fstream>


using namespace std;

template<class H>
class Heap{
	private:
		H *vett;
		int heapsize, call, numex, sum;
		
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
			call=0;
		}
		
		void max_heapify(int i){
			if(heapsize>=1){
				call++;
			}
			int l=left(i);
			int r=right(i);
			int max=i;
			
			if(l<=heapsize && vett[l]>vett[max]){
				max=l;
			}
			
			if(r<=heapsize && vett[r]>vett[max]){
				max=r;
			}
			
			if(max!=i){
				swap(vett[max],vett[i]);
				max_heapify(max);
			}
		}
		void build_maxheap(H *A, int dim){
			vett=A;
			heapsize=dim;
			for(int i=dim/2; i>0; i--){
				max_heapify(i);
			}
		
		}
		
		void extract(){
			
			swap(vett[1],vett[heapsize]);
			heapsize--;
			max_heapify(1);
		}
		
		
		void empty(){
            while(heapsize != 0){
                this->extract();
            }
        }  
		int returnsum(){
			
			return call;
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
			Heap<int> *t=new Heap<int>();
			int A[N];
			for(int i=1; i<=N; i++){
				in>>A[i];
			}
			t->build_maxheap(A,N);
			t->empty();
			out<<t->returnsum()<<endl;
		}
		
		if(type=="double"){
			Heap<double> *t=new Heap<double>();
			double A[N];
			for(int i=1; i<=N; i++){
				in>>A[i];
			}
			t->build_maxheap(A,N);
			t->empty();
			out<<t->returnsum()<<endl;
		}
		if(type=="bool"){
			Heap<bool> *t=new Heap<bool>();
			bool A[N];
			for(int i=1; i<=N; i++){
				in>>A[i];
			}
			t->build_maxheap(A,N);
			t->empty();
			out<<t->returnsum()<<endl;
		}
		if(type=="char"){
			Heap<char> *t=new Heap<char>();
			char A[N];
			for(int i=1; i<=N; i++){
				in>>A[i];
			}
			t->build_maxheap(A,N);
			t->empty();
			out<<t->returnsum()<<endl;
		}
	}
} 
