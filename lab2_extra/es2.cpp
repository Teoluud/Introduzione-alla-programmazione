/*
risolvere il problema della torre di Hanoi con n dischi
- OBIETTIVO: 
    spostare tutti i dischi dal paletto A al paletto C
- REGOLE:
    1. è consentito spostare un solo disco alla volta
    2. se due dischi sono sovrapposti, quello sottostante è più grande.
*/
#include<iostream>
using namespace std;

int count=0;

void hanoi(int n, int from, int to)
{
    static int count1=0;
    count1++;
    cout << "Chiamata numero " << count1 << " della funzione\n";
    if(n<=0)
        return;
    if (n==1)
        cout << from << " -> " << to << endl;
    else 
    {
        int aux = 6-from-to;
        hanoi(n-1,from, aux);
        hanoi(1, from, to);
        hanoi(n-1, aux, to);
    }
    
    ::count++;
}

int main()
{
    int n, from, to;
    cout << "Quanti dischi? ";
    cin >> n;
    cout << "Da quale paletto?[1/2/3] ";
    cin >> from;
    cout << "A quale paletto?[1/2/3] ";
    cin >> to;
    hanoi(n, from, to);
    cout << "La funzione è stata chiamata " << ::count << " volte.\n";
    
    return 0;
}