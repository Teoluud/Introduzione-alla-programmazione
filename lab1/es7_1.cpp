// approssimazione di pigreco di grado n, con n immesso dall'utente
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    double pi=0,j=0;
    cout << "n = ";
    cin >> n;
    while(j<=n){
        pi = pi + pow(-1, j)*4/(2*j+1);
        j++;
    }
    cout << "pi = " << pi << endl;
    return 0;
}