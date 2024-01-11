// crea un triangolo rettangolo lxl di "*"
#include<iostream>
using namespace std;

int main() {
    int r=0,c,l;
    cout << "l = ";
    cin >> l;
    while(r<l){
        c=0;
        while(c<=r){
            cout << "*";
            c++;
        }
        cout << endl;
        r++;
    } 
    return 0;   
}