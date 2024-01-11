// triangolo di Floyd
#include<iostream>
using namespace std;

void floyd(int n) {
    int num = 1;
    int c = 0;
    for(int i=0;i<n;i++){
        for (int a=0; a<=c;a++){
            cout << num << " ";
            num++;
        }
        cout << endl;
        c++;
    }
}

int main() {
    int n;
    cout << "Quante righe del triangolo di Floyd vuoi stampare? ";
    cin >> n;
    floyd(n);
    return 0;
}