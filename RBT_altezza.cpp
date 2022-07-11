#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Nodo{
    private:
    H element;
    Nodo<H> *p;
    Nodo<H> *dx;
    Nodo<H> *sx;
    char color;

    public:
    Nodo(H x){
        element=x;
        p=NULL;
        dx=NULL;
        sx=NULL;
        color='R';
    }

    void setp(Nodo<H> *x){
        p=x;
    }
    void setdx(Nodo<H> *x){
        dx=x;
    }
    void setsx(Nodo<H> *x){
        sx=x;
    }
    void setcolor(char x){
        color=x;
    }

    Nodo<H> *getp(){return p;}
    Nodo<H> *getdx(){return dx;}
    Nodo<H> *getsx(){return sx;}
    char getcolor(){return color;}
    H gete(){return element;}
};

template<class H>
class RBT{
    private:
    Nodo<H> *root;

    void trapianta(Nodo<H> *,Nodo<H> *);
    void rleft(Nodo<H> *);
    void rright(Nodo<H> *);

    public:
    RBT(){
        root=NULL;
    }
    
    void insert(H);
    void insert_fixup(Nodo<H> *);
    int get_altezza();
    int altezza(Nodo<H> *);
};

template<class H> void RBT<H>::trapianta(Nodo<H> *u, Nodo<H> *v){
    if(u->getp()==NULL){
        root=v;
    }
    else if(u==u->getp()->getdx()){
        u->getp()->setdx(v);
    }
    else{
        u->getp()->setsx(v);
    }

    if(v!=NULL){
        v->setp(u->getp());
    }
}

template<class H> void RBT<H>::rleft(Nodo<H> *x){
    if(x!=NULL){
        Nodo<H> *y=x->getdx();

        if(y!=NULL){
            x->setdx(y->getsx());
            if(x->getdx()!=NULL){
                x->getdx()->setp(x);
            }
            trapianta(x,y);

            x->setp(y);
            y->setsx(x);
        }   
    }
}

template<class H> void RBT<H>::rright(Nodo<H> *x){
    if(x!=NULL){
        Nodo<H> *y=x->getsx();

        if(y!=NULL){
            x->setsx(y->getdx());
            if(x->getsx()!=NULL){
                x->getsx()->setp(x);
            }
            trapianta(x,y);
            x->setp(y);
            y->setdx(x);
        }
    }
}

template<class H> void RBT<H>::insert(H x){
    Nodo<H> *nuovo=new Nodo<H>(x);

    if(root==NULL){
        root=nuovo;
    }
    else{
        Nodo<H> *ptr=root;
        Nodo<H> *tmp=NULL;

        while(ptr!=NULL){
            tmp=ptr;
            if(x>ptr->gete()){
                ptr=ptr->getdx();
            }
            else{
                ptr=ptr->getsx();
            }
        }
        nuovo->setp(tmp);

        if(x>tmp->gete()){
            tmp->setdx(nuovo);
        }
        else{
            tmp->setsx(nuovo);
        }
    }
    insert_fixup(nuovo);
}

template<class H> void RBT<H>::insert_fixup(Nodo<H> *z){
    if(z->getp()!=NULL && z->getp()->getcolor()=='B'){
        return;
    }

    if(z==root){
        z->setcolor('B');
        return;
    }

    Nodo<H> *padre=z->getp();
    Nodo<H> *nonno=padre->getp();
    Nodo<H> *zio=nonno->getdx();
    if(nonno->getdx()==padre){
        zio=nonno->getsx();
    }

    if(zio!=NULL && zio->getcolor()=='R'){
        padre->setcolor('B');
        zio->setcolor('B');
        nonno->setcolor('R');
        insert_fixup(nonno);
        return;
    }

    if( padre==nonno->getsx()){
        if(z==padre->getdx()){
            rleft(padre);
            padre=z;
            z=padre->getsx();
        }

        rright(nonno);
        padre->setcolor('B');
        nonno->setcolor('R');
        return;
    }
    else{
        if(z==padre->getsx()){
            rright(padre);
            padre=z;
            z=padre->getdx();
        }

        rleft(nonno);
        nonno->setcolor('R');
        padre->setcolor('B');
        return;
    }
}

template<class H> int RBT<H>::get_altezza(){return altezza(root);}
template<class H> int RBT<H>::altezza(Nodo<H> *ptr){
    if(ptr==NULL){return 0;}
    int s=altezza(ptr->getsx());
    int d=altezza(ptr->getdx());
    return 1+max(s,d);
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int task=0; task<100; task++){
        string type; in>>type;
        int N; in>>N;

        if(type=="int"){
            RBT<int> *t=new RBT<int>();
            for(int i=0; i<N; i++){
                int x; in>>x;
                t->insert(x);
            }
            out<<t->get_altezza()<<endl;
            delete t;
        }
        else{
            RBT<double> *t=new RBT<double>();
            for(int i=0; i<N; i++){
                double x; in>>x;
                t->insert(x);
            }
            out<<t->get_altezza()<<endl;
            delete t;
        }

    }
}