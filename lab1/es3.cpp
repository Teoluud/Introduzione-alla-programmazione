// stampa n "*", con n immesso dall'utente
#include<iostream>
using namespace std;

int main() {
    int n, count=0;
    cout << "n = ";
    cin >> n;
    while(count<n){
        cout << "*";
        count++;
    }
    cout << endl;
    return 0;
}