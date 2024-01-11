// funzione che riduce ai minimi termini numeratore e denominatore una frazione tramite algoritmo di Euclide
#include<iostream>
using namespace std;

void minimi_termini(int &numeratore, int &denominatore)
{
    if(denominatore==0)
    {
        cout << "Il denominatore deve essere diverso da 0!";
        return ;
    }
    int m=numeratore, n=denominatore;
    while(m != 0)       /*trova il massimo comun divisore (algoritmo di Euclide)*/
    {
        if(m<n)
        {
            int t=m;
            m = n;
            n = t;
        }
        m = m-n;
    }

    numeratore /= n;
    denominatore /= n;
}

void minimi_termini_ric(int &num, int &den)
{
    if(den==0)
    {
        cout << "Il denominatore deve essere diverso da 0!";
        return;
    }
    int m=num, n=den;
    if(m==0)
        return;
    if(m<n)
        minimi_termini_ric(n, m);
    m = m-n;
    num /= n;
    den /= n;
}

int main()
{
    int a,b,c,d;

    cout << "Dammi il numeratore: ";
    cin >> a;
    c=a;
    cout << "Dammi il denominatore: ";
    cin >> b;
    d=b;

    minimi_termini(a,b);
    cout << a << "/" << b << endl;
    minimi_termini_ric(c,d);
    cout << c << "/" << d << endl;
    return 0;
}