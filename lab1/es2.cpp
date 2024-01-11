// dati due interi dall'utente, verifica se il primo è multiplo del secondo
#include<iostream>
using namespace std;

int main() {
    int a,b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    if(a%b == 0)
        cout << a << " è multiplo di " << b << endl;
    else
        cout << a << " non è multiplo di " << b << endl;
    return 0; 
}