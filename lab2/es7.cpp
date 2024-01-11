// funzione ricorsiva per la potenza
#include<iostream>
using namespace std;

int count1 = 0;
int count2 = 0;

int potenza_1(int a, int n) {
    if(n==0)
        return 1;
    int res;
    res = a*potenza_1(a, n-1);
    ::count1++;
    return res;
}

int potenza_2(int a, int n) {
    if(n==0)
        return 1;
    int res;
    int b=potenza_2(a,n/2);
    if(n%2==0)
        res = b*b;
    else
        res = a*b*b;
    ::count2++;
    return res;
}

int main() {
    int a,n;
    cout << "Inserire la base della potenza: ";
    cin >> a;
    do {
        cout << "Inserire l'esponente (intero non negativo): ";
        cin >> n;
    }while (n<0);
    cout << "Il risultato attraverso la prima ricorsione è: " << potenza_1(a,n);
    cout << ", chiamata: " << ::count1 << " volte.\n";
    cout << "Il risultato attraverso la seconda ricorsione è: " << potenza_2(a,n);
    cout << ", chiamata: " << ::count2 << " volte.\n";
    return 0;
}