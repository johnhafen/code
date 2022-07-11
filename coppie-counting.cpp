#include <iostream>
#include <fstream>

using namespace std;

template<class H>
class coppia{
	private:
		H x;
		H y;
	public:
		coppia(){
		}
		
		void set_x(H x){
			this->x=x;
		}
		void set_y(H y){
			this->y=y;
		}
		
		H get_x(){
			return x;
		}
		
		H get_y(){
			return y;
		}
};

int massimo(coppia<int>**a,int n){
	int x=1;
	for(int i=2; i<=n; i++){
		if(a[i]->get_x()>a[x]->get_x()){
			x=i;
		}
	}
	return a[x]->get_x();
}

int minimo(coppia<int>**a,int n){
	int x=a[1]->get_x();
	for(int i=2; i<=n; i++){
		if(a[i]->get_x()<x){
			x=a[i]->get_x();
		}
	}
	return x;
}

void counting_sort(coppia<double> **A, int n,ofstream& out){
	coppia <int> **vett=new coppia<int>*[n];
	for(int i=1; i<=n; i++){
		coppia<int> *n=new coppia<int>();
		n->set_x((int)(A[i]->get_x()*10));
		n->set_y((int)(A[i]->get_y()*10));
		vett[i]=n;
	}
	
	int max=massimo(vett,n);
	int min=minimo(vett,n);
	int k=max-min+1;
	
	int *C=new int[k+1];
	
	for(int i=0; i<=k; i++){
		C[i]=0;
	}
	
	for(int i=1; i<=n; i++){
		C[vett[i]->get_x()-min+1]++;
	}
	
	for(int i=2; i<=k; i++){
		C[i]=C[i]+C[i-1];
	}
	coppia <double> ** B=new coppia<double>*[n+1];
	for(int i=n; i>=1; i--){
		coppia <double> *n=new coppia<double>();
		n->set_x((double)(vett[i]->get_x()/10.0));
		n->set_y((double)(vett[i]->get_y()/10.0));
		B[C[vett[i]->get_x()-min+1]]=n;
		C[vett[i]->get_x()-min+1]--;
	}
	
	out<<C[0]<<" ";
	for(int i=1; i<=k; i++){
		if(C[i]!=0){
		out<<C[i]<<" ";	
		}
	}
	
	for(int i=1; i<=n; i++){
		out<<"("<<B[i]->get_x()<<" "<<B[i]->get_y()<<") ";
	}
	
	out<<endl;
	
	delete []B;
	delete []vett;
}


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task=0; task<100; task++){
		int N;
		in>>N;
		coppia <double>**A=new coppia<double>*[N];
		for(int i=1; i<=N; i++){
			coppia <double>*n=new coppia<double>();
			double x,y;
			char tmp;
			in>>tmp;
			in>>x;
			
			in>>y;
			in>>tmp;
			n->set_x(x);
			n->set_y(y);
			A[i]=n;
		}
		counting_sort(A,N,out);
	    delete []A;
	}
}





