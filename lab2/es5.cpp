// funzione non-ricorsiva che calcola l'n-esimo numero di Fibonacci
#include<iostream>
using namespace std;

int fibonacci(int n) {
    if(n<=1)
        return n;
    
    int a=0,b=1,c;
    for(int k=2;k<=n;k++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;
    cout << "L'n-esimo termine di Fibonacci è: " << fibonacci(n) << endl;
    return 0;
}