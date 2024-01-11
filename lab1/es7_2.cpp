// approssimazione del valore di pigreco con un errore minore di epsilon, con epsilon immessa dall'utente.
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    double pi1=0,j=0,epsilon, pi2=0;
    cout << "epsilon = ";
    cin >> epsilon;
    pi2 = pi1 + pow(-1, j)*4/(2*j+1);
    j++;
    while(abs(pi2-pi1)>=epsilon){
        pi1 = pi2;
        pi2 = pi1 + pow(-1, j)*4/(2*j+1);
        j++;
    }
    cout << setprecision(12) << "pi = " << pi2 << endl;
    return 0;
}