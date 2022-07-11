#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;

template<class H>
class Nodo{
      private:
      H element;
      Nodo<H>* P;
      Nodo<H>* DX;
      Nodo<H>* SX;
      
      public:
      Nodo(H x){
         element=x;
         P=NULL;
         DX=NULL;
         SX=NULL;
      }
      
      Nodo<H>* getDX(){
          return DX;
      }
      Nodo<H>* getSX(){
          return SX;
      }
      Nodo<H>* getP(){
          return P;
      }
      H getE(){
         return element;
      }
      
      void setDX(Nodo<H>* x){
           DX=x;
      }
      void setSX(Nodo<H>* x){
           SX=x;
      }
      void setP(Nodo<H>* x){
           P=x;
      }
      
    
};



template<class H>
class BST{
      private:
       Nodo<H>* root;
       
       void trapianta(Nodo<H>*,Nodo<H>*);
       void preorder(Nodo<H>*,ofstream&);
       void inorder(Nodo<H>*,ofstream&);
       void postorder(Nodo<H>*,ofstream&);
      public:
      BST(){
         root=NULL;
      }
      
      void insert(H);
      void canc(H);
      Nodo<H>* search(H);
      Nodo<H>* findmin(Nodo<H>*);
      
      void rotate(char, H);
      void rLeft(Nodo<H>*);
      void rRight(Nodo<H>*);
      void print(string,ofstream&);
};

template<class H> void BST<H>::trapianta(Nodo<H>* u, Nodo<H>* v){
     if(u->getP()==NULL){
       root=v;
     }
     else if(u==u->getP()->getDX()){
          u->getP()->setDX(v);
     }
     else{
         u->getP()->setSX(v);
     }
     
     if(v!=NULL){
        v->setP(u->getP());
     }
}

template<class H> void BST<H>::insert(H x){
    Nodo<H>* nuovo=new Nodo<H>(x);
    if(root==NULL){
       root=nuovo;
    }
    else{
       Nodo<H>* ptr=root;
       Nodo<H>* tmp=NULL;
       
       while(ptr!=NULL){
          tmp=ptr;
          if(x>ptr->getE()){
            ptr=ptr->getDX();
          }
          else{
            ptr=ptr->getSX();
          }
       }
       
       nuovo->setP(tmp);
       if(x>tmp->getE()){
         tmp->setDX(nuovo);
       }
       else{
         tmp->setSX(nuovo);
       }
    }
}

template<class H> void BST<H>::canc(H x){
       Nodo<H>* ptr=search(x);
       
       if(ptr!=NULL){
          if(ptr->getSX()==NULL){
            trapianta(ptr,ptr->getDX());
          }
          else if(ptr->getDX()==NULL){
            trapianta(ptr,ptr->getSX());
          }
          else{
              Nodo<H> *y=findmin(ptr->getDX());
              
              if(y->getP()!=ptr){
                trapianta(y,y->getDX());
                y->setDX(ptr->getDX());
                y->getDX()->setP(y);
              }
              trapianta(ptr,y);
              y->setSX(ptr->getSX());
              y->getSX()->setP(y);
          }
       }
}

template<class H> Nodo<H>* BST<H>::search(H x){
       Nodo<H>* ptr=root;
       
       while(ptr!=NULL && x!=ptr->getE()){
           if(x>ptr->getE()){
             ptr=ptr->getDX();
           }
           else{
             ptr=ptr->getSX();
           }
       }
       
       return ptr;
}

template<class H> Nodo<H>* BST<H>::findmin(Nodo<H> *x){
     Nodo<H>* iter=x;
     while(iter->getSX()!=NULL){
          iter=iter->getSX();
     }
     return iter;
}

template<class H> void BST<H>::rotate(char t, H x){
       Nodo<H>* ptr=search(x);
       if(ptr!=NULL){
         if(t=='l'){
           rLeft(ptr);
         }
         else{
           rRight(ptr);
         }
       }
}

template<class H> void BST<H>::rLeft(Nodo<H>* y){
       if(y!=NULL){
         Nodo<H>* x=y->getP();
         Nodo<H>* z=y->getDX();
         if(z!=NULL){
           y->setDX(z->getSX());
           z->setSX(y);
           
           trapianta(y,z);
           
           z->setP(x);
           y->setP(z);
           
           if(y->getDX()){
             y->getDX()->setP(y);
           }
         }
       }
}

template<class H> void BST<H>::rRight(Nodo<H>* y){
       if(y!=NULL){
         Nodo<H>* x=y->getP();
         Nodo<H>* z=y->getSX();
         if(z!=NULL){
           y->setSX(z->getDX());
           z->setDX(y);
           
           trapianta(y,z);
           
           z->setP(x);
           y->setP(z);
           
           if(y->getSX()){
             y->getSX()->setP(y);
           }
         }
       }
}

template<class H> void BST<H>::print(string type,ofstream &out){
     if(type=="inorder"){
        inorder(root,out);
     }
     else if(type=="postorder"){
        postorder(root,out);
     }
     else{
        preorder(root,out);
     }
     
     out<<endl;
}

template<class H> void BST<H>::inorder(Nodo<H> *x, ofstream&out){
     if(x!=NULL){
       inorder(x->getSX(),out);
       out<<x->getE()<<" ";
       inorder(x->getDX(),out);
     }
}

template<class H> void BST<H>::postorder(Nodo<H> *x, ofstream&out){
     if(x!=NULL){
       postorder(x->getSX(),out);
       postorder(x->getDX(),out);
       out<<x->getE()<<" ";
     }
}

template<class H> void BST<H>::preorder(Nodo<H> *x, ofstream&out){
     if(x!=NULL){
       out<<x->getE()<<" ";
       preorder(x->getSX(),out);
       preorder(x->getDX(),out);
     }
}
int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int task=0; task<100; task++){
  
        string type;
        in>>type;
        int N;
        in>>N;
        int M;
        in>>M;
        string ordine;
        in>>ordine;
        
        if(type=="int"){
           BST<int>* B=new BST<int>();
           
           for(int i=0; i<N; i++){
              string op;
              in>>op;
              if(op[0]=='i'){
                string op1=op.substr(4,op.length());
                int a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->insert(a);
              }
              if(op[0]=='c'){
                string op1=op.substr(5,op.length());
                int a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->canc(a);
              }
           }
           
           for(int i=0; i<M; i++){
              string op;
              in>>op;
              if(op[0]=='l'){
                string op1=op.substr(5,op.length());
                int a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->rotate(op[0],a);
              }
              else{
                 string op1=op.substr(6,op.length());
                int a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->rotate(op[0],a);
              }
           }
           
           B->print(ordine,out);
           delete B;
        }
        
        else{
           BST<double>* B=new BST<double>();
           for(int i=0; i<N+M; i++){
              string op;
              in>>op;
             if(op[0]=='i'){
                string op1=op.substr(4,op.length());
                double a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->insert(a);
              }
              else if(op[0]=='c'){
                string op1=op.substr(5,op.length());
                double a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->canc(a);
              }
              else if (op[0]=='l'){
                string op1=op.substr(5,op.length());
                double a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->rotate(op[0],a);
              }
              else {
                string op1=op.substr(6,op.length());
                double a;
                stringstream ss;
                ss<<op1;
                ss>>a;
                B->rotate(op[0],a);
              }
           }
           
           B->print(ordine,out);
           delete B;
        }
        
        
    }
}
