#include <iostream>
#include <fstream> 

#define INPUT   "input.txt"
#define OUTPUT  "output.txt"

using namespace std; 

void countingSort(int* A, int len, fstream& out); 

int main() 
{
    fstream infile, outfile; 
    infile.open(INPUT, fstream::in); 
    outfile.open(OUTPUT, fstream::out); 

    while (!infile.eof()) {

        int N; 
        infile >> N; 

        if (!infile.eof()) {
            int A[N];  
            for (int i = 0; i < N; i++) infile >> A[i]; 
            countingSort(A, N, outfile); 
        }

    }

}

void countingSort(int* a, int len, fstream& out) 
{
    int min = a[0]; 
    int max = a[0]; 

    for (int i = 1; i < len; i++) {
        max = a[i] > max ? a[i] : max; 
        min = a[i] < min ? a[i] : min; 
    }

    int  k = max - min + 1;
    int* c = new int[k]; 
    int* b = new int[len]; 

    // l'i-esimo elemento di A va ad incrementare
    // in C la cella relativa alla propria chiave
    // sottratta al minimo (l'array C parte da 0)
    for (int i = 0; i < len; i++)   c[a[i]-min] ++; 

    // ogni elemento in C viene sommato al precedente
    // così da ottenere la posizione esatta dell'
    // elemento di A durante l'ordinamento in B
    for (int i = 1; i < k; i++)     c[i] += c[i-1]; 

    // partendo dall'ultimo elemento, per l'operazione
    // svolta precedentemente, sappiamo dove verrà 
    // posizionato l'iesimo elemento di A in B 
    for (int i = len - 1; i >= 0; i--) {
        b[c[a[i]-min]-1] = a[i]; 
        c[a[i]-min] --;  
    }

    // output dell'esercizio
    for (int i = 0; i < k; i++ )    out << c[i] << " "; 
    for (int i = 0; i < len; i++)   out << b[i] << " "; 
    out << endl;
    return; 
}