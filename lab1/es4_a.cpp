// stampa un quadrato lxl di "*"
#include<iostream>
using namespace std;

int main() {
    int r=0,c,l;
    cout << "l = ";
    cin >> l;
    while(r<l){
        c = 0;
        while(c<l){        
            cout << "*";
            c++;
        }                   // stampa una riga di 5 "*"
        cout << endl;
        r++;
    }                      // stampa 5 righe di 5 "*"
    return 0;
}