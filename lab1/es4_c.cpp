// stampa un triangolo rettangolo "invertito" lxl di "*"
#include<iostream>
using namespace std;

int main() {
    int l,c,r;
    cout << "l = ";
    cin >> l;
    r = l;
    while(r>0){
        c=0;
        while(c<r){
            cout << "*";
            c++;
        }
        cout << endl;
        r--;
    }
    return 0;
}