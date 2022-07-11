#include<iostream>
#include<list>
#include<fstream>
using namespace std;

template<class T>
class Hash{
	private:
		list<T> *H;
		int M;
		double c=0.61803;
	public:	
	    Hash(int dim){
	    	M=dim;
	    	H=new list<T>[M];
		}
		
		int insert(T x){
			double y=x*c;
			double a=y-(int)y;
			int pos=(int)(M*a);
			H[pos].push_back(x);
			return pos;
		}
		    
};

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	
	for(int task=0; task<100; task++){
		string type;
		in>>type;
		int M,N;
		in>>M;
		in>>N;
		
		if(type=="int"){
			Hash<int> *h=new Hash<int>(M);
			int tmp;
			int A[M];
			
			for(int i=0;i<M; i++){
				A[i]=0;
			}
			
			for(int i=0; i<N; i++){
				in>>tmp;
				int pos=h->insert(tmp);
				A[pos]++;
			}
			
			for(int i=0; i<M; i++){
				out<<A[i]<<" ";
			}
			out<<endl;
		}
		if(type=="double"){
			Hash<double> *h=new Hash<double>(M);
			double tmp;
			int A[M];
			
			for(int i=0;i<M; i++){
				A[i]=0;
			}
			
			for(int i=0; i<N; i++){
				in>>tmp;
				int pos=h->insert(tmp);
				A[pos]++;
			}
			
			for(int i=0; i<M; i++){
				out<<A[i]<<" ";
			}
			out<<endl;
		}
		if(type=="bool"){
			Hash<bool> *h=new Hash<bool>(M);
			bool tmp;
			int A[M];
			
			for(int i=0;i<M; i++){
				A[i]=0;
			}
			
			for(int i=0; i<N; i++){
				in>>tmp;
				int pos=h->insert(tmp);
				A[pos]++;
			}
			
			for(int i=0; i<M; i++){
				out<<A[i]<<" ";
			}
			out<<endl;
		}
		if(type=="char"){
			Hash<char> *h=new Hash<char>(M);
			char tmp;
			int A[M];
			
			for(int i=0;i<M; i++){
				A[i]=0;
			}
			
			for(int i=0; i<N; i++){
				in>>tmp;
				int pos=h->insert(tmp);
				A[pos]++;
			}
			
			for(int i=0; i<M; i++){
				out<<A[i]<<" ";
			}
			out<<endl;
		}
	}
}
