// stabilisce quale tra i 10 numeri inseriti dall'utente è il massimo e quale è il minimo.
#include<iostream>
using namespace std;

int main(){
    double max,min,n,count=0;
    cout << "n = ";
    cin >> n;
    max = n;
    min = n;
    count++;
    while(count<10){
        cout << "n = ";
        cin >> n;
        if(n<min){
            min = n;
        }
        else if(n>max){
            max = n;
        }
        count++;
    }
    cout << "min = " << min << endl;
    cout << "max = " << max << endl;
    return 0;
}