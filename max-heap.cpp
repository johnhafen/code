#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
using namespace std;

template<class T>
class Heap{
	private:
		T *H;
		int heapsize;
		int num;
		
		int getparent(int i){
			return i/2;
		}
		
		int getleft(int i){
			return i*2;
		}
		
		int getright(int i){
			return i*2+1;
		}
		
	public:
		Heap(int dim){
			heapsize=0;
			num=0;
			H=new T[dim];
		}
		
		~Heap(){delete [] H;}
		void increasekey(T x){
			int i=heapsize;
			while(i>1 && H[getparent(i)]<H[i]){
				swap(H[i],H[(getparent(i))]);
				i=getparent(i);
			}
		}
		
		void insert(T x){
			heapsize++;
			H[heapsize]=x;
			increasekey(x);
		}
		
		void extract_key(){
			/*int max=H[1];
			H[1]=H[heapsize];*/
			swap(H[1],H[heapsize]);
			heapsize--;
			max_heapify(1);
		}
		
		void max_heapify(int i){
			if(heapsize>=1){
				num++;
			}
			int l=getleft(i);
			int r=getright(i);
			int max;
			if(l<=heapsize && H[l]>H[i]){
				max=l;
			}
			else max=i;
			
			if(r<=heapsize && H[r]>H[max]){
				max=r;
			}
			
			if(max!=i){
				swap(H[i],H[max]);
				max_heapify(max);
			}
		}
	/*	void buildmaxheap(){
			int dim=heapsize/2;
			for(int i=dim; i>0; i--){
				max_heapify(i);
			}
		}*/
		
		void print(ofstream &out){
			for(int i=1; i<=heapsize; i++){
				out<<H[i]<<" ";
			}
			out<<endl;
		}
		
		int numHeapify(){
			return num;
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
		    for(int i=0; i<N; i++){
		        string s;
			    in>>s;
			    if(s=="extract"){
				    h->extract_key();
			    }
			    else{
			        stringstream ss;
				    string c=s.substr(2);
				    ss<<c;
				    int b;
				    ss>>b;
				    h->insert(b);
			    }
		    }
		    int n=h->numHeapify();
		    out<<n<<" ";
		    h->print(out);
		    delete h;
		}
		if(type=="double"){
			Heap<double> *h=new Heap<double>(N);
		    for(int i=0; i<N; i++){
		        string s;
			    in>>s;
			    if(s=="extract"){
				    h->extract_key();
			    }
			    else{
			        stringstream ss;
				    string c=s.substr(2);
				    ss<<c;
				    double b;
				    ss>>b;
				    h->insert(b);
			    }
		    }
		    int n=h->numHeapify();
		    out<<n<<" ";
		    h->print(out);
		    delete h;
		}
		if(type=="bool"){
			Heap<bool> *h=new Heap<bool>(N);
		    for(int i=0; i<N; i++){
		        string s;
			    in>>s;
			    if(s=="extract"){
				    h->extract_key();
			    }
			    else{
			        stringstream ss;
				    string c=s.substr(2);
				    ss<<c;
				    bool b;
				    ss>>b;
				    h->insert(b);
			    }
		    }
		    int n=h->numHeapify();
		    out<<n<<" ";
		    h->print(out);
		    delete h;
		}
		if(type=="char"){
			Heap<char> *h=new Heap<char>(N);
		    for(int i=0; i<N; i++){
		        string s;
			    in>>s;
			    if(s=="extract"){
				    h->extract_key();
			    }
			    else{
			        stringstream ss;
				    string c=s.substr(2);
				    ss<<c;
				    char b;
				    ss>>b;
				    h->insert(b);
			    }
		    }
		    int n=h->numHeapify();
		    out<<n<<" ";
		    h->print(out);
		    delete h;
		}
	}
	
}
