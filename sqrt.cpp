#include<iostream>
#include<cmath>
using namespace std;

int main(){
  char scelta = 'n';
  int n;
  do{
    do {
      cout << "Inserire numero positivo: ";
      cin >> n;
    } while(n<0);
	  
    cout << "La radice del numero è: " << sqrt(n) << endl;
    cout << endl;
    cout << "Vuoi continuare a usare il programma?(y/n): ";
    cin >> scelta;
    cout << string(30, '*') << endl;
    }while(scelta == 'y');
  return 0;
}