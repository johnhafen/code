#include <iostream>
#include <fstream>

#define INPUT   "input.txt"
#define OUTPUT  "output.txt"

using namespace std; 

void sort(int *v, int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (v[i] > v[j]) {
                int tmp = v[i]; 
                v[i] = v[j]; 
                v[j] = tmp; 
            }
        }
    }
}

int main() 
{
    fstream infile, outfile; 
    infile.open(INPUT, fstream::in);
    outfile.open(OUTPUT, fstream::out); 

    while (!infile.eof()) {

        int n, w; 

        infile >> n >> w; 

        if (!infile.eof()) {

            int v[n];

            for (int i = 0; i < n; i++) 
                infile >> v[i];

            sort(v, n); 

            int i = n - 1; 
            int k = 0; 

            while(w > 0 && i >= 0) {
                k += v[i--];  
                w--; 
            }
            
            outfile << k << endl; 
        }
    }
}