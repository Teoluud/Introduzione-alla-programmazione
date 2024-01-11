// funzione ricorsiva per l'n-esimo numero di Fibonacci
#include<iostream>
using namespace std;

int count=0;

int fibonacci(int n) {
    if(n<=1)
        return n;
    int res;
    res = fibonacci(n-1)+fibonacci(n-2);
    ::count++;
    return res;
}

int main() {
    int n;
    cout << "Inserire n: ";
    cin >> n;
    cout << "L'n-esimo termine della sequenza di Fibonacci è: " << fibonacci(n) << endl;
    cout << "La funzione è stata chiamata " << ::count << " volte\n";
    return 0;
}