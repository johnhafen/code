#include <iostream>
#include <fstream> 

#define INPUT   "input.txt"
#define OUTPUT  "output.txt"

using namespace std; 

class Activity {

    public: 

        int s, e; 

        Activity(int s, int e) 
        {
            this->s = s; 
            this->e = e; 
        }

        friend bool operator<(const Activity& a, const Activity& b);
        friend ostream& operator<<(ostream& os, const Activity& a);

};

bool operator<(const Activity& a, const Activity& b) 
{
    return a.e < b.e; 
}

ostream& operator<<(ostream& os, const Activity& a) 
{
    os << "[" << a.s << ", " << a.e << "]"; 
}

Activity* parse(string str) 
{
    str = str.substr(1, str.length()-2);
    int comma = str.find(' '); 

    int s = atoi((str.substr(0, comma)).c_str());
    int e = atoi((str.substr(comma+1)).c_str());

    return new Activity(s, e);  
}

void sort(Activity** a, int len) 
{
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (*a[j] < *a[i]) {

                Activity *tmp = a[i];
                a[i] = a[j]; 
                a[j] = tmp; 
                 
            }
        }
    }
}

int activities(Activity** S, int n) 
{
    int c = 1; 
    int e = (S[0])->e; 

    for (int i = 1; i < n; i ++) {
        if ((S[i])->s >= e) {
            e = (S[i])->e; 
            c ++; 
        }
    }
    
    return c; 
}

int main()
{
    fstream infile, outfile; 
    infile.open(INPUT, fstream::in);
    outfile.open(OUTPUT, fstream::out); 

    while (!infile.eof()) {

        int N; 
        infile >> N; 

        if (!infile.eof()) {

            Activity* S[N]; 

            for (int i = 0; i < N; i++) {
                string str_1, str_2; 
                infile >> str_1 >> str_2;
                str_1 += " " + str_2;
                S[i] = parse(str_1);
            } 

            sort(S, N); 

            // for (int i = 0; i < N; i++) {
                // cout << S[i] << " "; 
            // }
            // cout << endl; 

            outfile << activities(S, N) << endl; 

        }

    }
}