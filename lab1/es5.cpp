// fattoriale di un intero dato dall'utente
#include<iostream>
using namespace std;

int main() {
    int n,count;
    do{
        cout << "n = ";
        cin >> n;
    }while(n<0);
    if(n==0){
        n=1;
    }
    else{
        count=n-1;
        while(count>0){
            n = n*count;
            count--;
        }
    }
    cout << "n! = " << n << endl;
    return 0;
}