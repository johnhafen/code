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

    Nodo<H> *getp(){return p;}
    Nodo<H> *getdx(){return dx;}
    Nodo<H> *getsx(){return sx;}
    H gete(){return element;}
    char get_color(){return color;}

    void setp(Nodo<H> *x){p=x;}
    void setdx(Nodo<H> *x){dx=x;}
    void setsx(Nodo<H> *x){sx=x;}
    void set_color(char x){color=x;}
};

template<class H>
class RBT{
    private:
    Nodo<H> *root;

    void trapianta(Nodo<H> *,Nodo<H> *);
    void preorder(Nodo<H> *,ofstream&);
    void postorder(Nodo<H> *,ofstream&);
    void inorder(Nodo<H> *,ofstream&);

    void rleft(Nodo<H> *);
    void rright(Nodo<H> *);
    public:
    RBT(){
        root=NULL;
    }

    void insert(H);
    void insert_fixup(Nodo<H> *);
    void print(ofstream&, string);
};

template<class H> void RBT<H>::insert(H x){
    Nodo<H> *nuovo=new Nodo<H>(x);
    if(root==NULL){
        root=nuovo;
    }
    else{
        Nodo<H> *ptr=root;
        Nodo<H> *iter=NULL;

        while(ptr!=NULL){
            iter=ptr;
            if(x>ptr->gete()){
                ptr=ptr->getdx();
            }
            else{
                ptr=ptr->getsx();
            }
        }
        nuovo->setp(iter);
        if(x>iter->gete()){
            iter->setdx(nuovo);
        }
        else{
            iter->setsx(nuovo);
        }
    }
    
    insert_fixup(nuovo);
}


template <class H> void RBT<H>::insert_fixup(Nodo<H>* z){
    if(z->getp() != NULL && z->getp()->get_color() == 'B')
        return;
    if(z == root){
        z->set_color('B');
        return;
    }
    Nodo<H>* padre = z->getp();
    Nodo<H>* nonno = padre->getp();
    Nodo<H>* zio = nonno->getdx();
    if(nonno->getdx() == padre)
        zio = nonno->getsx();
    
    if(zio != NULL && zio->get_color() == 'R'){
        zio->set_color('B');
        padre->set_color('B');
        nonno->set_color('R');
        insert_fixup(nonno);
        return;
    }

    if(padre == nonno->getsx()){
        if(z == padre->getdx()){
            rleft(padre);
            padre = z;
            z = padre->getsx();
        }

        rright(nonno);
        padre->set_color('B');
        nonno->set_color('R');
        return;
    }
    else{
        if(z == padre->getsx()){
            rright(padre);
            padre = z;
            z = padre->getdx();
        }

        padre->set_color('B');
        nonno->set_color('R');
        rleft(nonno);
        return;
    }
}

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

template<class H> void RBT<H>::rleft(Nodo<H> *y){
    if(y!=NULL){
        Nodo<H> *x=y->getdx();

        if(x!=NULL){
            y->setdx(x->getsx());
            if(y->getdx()!=NULL){
                y->getdx()->setp(y);
            }
            trapianta(y,x);
            x->setsx(y);
            y->setp(x);
        }
    }
}

template<class H> void RBT<H>::rright(Nodo<H> *y){
    if(y!=NULL){
        Nodo<H> *x=y->getsx();
        if(x!=NULL){
            y->setsx(x->getdx());
            if(y->getsx()!=NULL){
                y->getsx()->setp(y);
            }
            trapianta(y,x);
            x->setdx(y);
            y->setp(x);
        }
    }
}

template<class H> void RBT<H>::inorder(Nodo<H> *x, ofstream& out){
    if(x!=NULL){
        inorder(x->getsx(),out);
        out<<"("<<x->gete()<<" "<<x->get_color()<<") ";
        inorder(x->getdx(),out);
    }
}

template<class H> void RBT<H>::preorder(Nodo<H> *x,ofstream& out){
    if(x!=NULL){
        out<<"("<<x->gete()<<" "<<x->get_color()<<") ";
        preorder(x->getsx(),out);
        preorder(x->getdx(),out);
    }
}

template<class H> void RBT<H>::postorder(Nodo<H> *x,ofstream& out){
    if(x!=NULL){
        postorder(x->getsx(),out);
        postorder(x->getdx(),out);
        out<<"("<<x->gete()<<" "<<x->get_color()<<") ";
    }
}

template<class H> void RBT<H>::print(ofstream& out, string s){
    if(s=="inorder"){
        inorder(root,out);
    }
    else if(s=="preorder"){
        preorder(root,out);
    }
    else{
        postorder(root,out);
    }
    out<<endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int task=0; task<100; task++){
        string type; in>>type;
        int N; in>>N;
        string stamp; in>>stamp;

        if(type=="int"){
            RBT<int> *r=new RBT<int>();
            for(int i=0; i<N; i++){
                int x; in>>x;
                r->insert(x);
            }
            r->print(out,stamp);
            delete r;
        }
        else{
            RBT<double> *r=new RBT<double>();
            for(int i=0; i<N; i++){
                double x; in>>x;
                r->insert(x);
            }
            r->print(out,stamp);
            delete r;
        }
    }
}