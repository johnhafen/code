#include <iostream>
#include <fstream>

using namespace std;

class attivit{
    private:
    int s;
    int f;
    public:
    attivit(int x, int y ){
        s=x;
        f=y;
    }
    int gets(){return s;}
    int getf(){return f;}
    int getprofit(){return f-s;}
};
 
    void bubblesort(attivit **vett, int N){
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(vett[i]->getf()>vett[j]->getf()){
                    swap(vett[i],vett[j]);
                }
                else if(vett[i]->getf() == vett[j]->getf() && vett[i]->gets() < vett[j]->gets()){
                    swap(vett[i], vett[j]);
                }
            }
        }
    }
    int latestNonConflict(attivit ** vett, int i){
    for(int j = i-1; j >= 0; j--)
        if(vett[j]->getf() <= vett[i]->gets())
            return j;
    return -1;
   }

    void activity(attivit **vett,ofstream &out,int N){
        int table[N];
        table[0] = vett[0]->getprofit();
        for(int i=1; i<N; i++){
            int tmprofit = vett[i]->getprofit();
            int l = latestNonConflict(vett, i);

            if(l != -1)
            tmprofit += table[l];
            if(tmprofit > table[i-1])
                table[i] = tmprofit;
            else
                table[i] = table[i-1];
        }
        out << table[N-1] << endl;
    }



int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	for(int task=0; task<100; task++){
        int N; in>>N;
        attivit **A=new attivit*[N];
        for(int i=0; i<N; i++){
            char tmp;
            int x,y;
            in>>tmp;
            in>>x;
            in>>y;
            in>>tmp;
            A[i]=new attivit(x,y);
        }
        bubblesort(A,N);
        activity(A,out,N);
       delete [] A;
    }
}