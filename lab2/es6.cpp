// funzione che scambia due valori
#include<iostream>
using namespace std;

void swap(double &a, double &b) {
    double t=a;
    a = b;
    b = t;
}

int main() {
    int x,y;
    cout << "Inserisci i due valori da scambiare [x y]: ";
    cin >> x >> y;
    swap(x,y);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}