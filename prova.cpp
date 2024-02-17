#include<iostream>
using namespace std;

int f(int v[], int n)
{
    int m = 0, m2 = 1;
    if ( m2 > m)
    {
        m = 1;
        m2 = 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (v[i] > v[m])
        {
            m2 = m;
            m = i;
        }
        else if (v[i] > v[m2])
        {
            m2 = i;
        }
    }
    return v[m2];
}

int main()
{
    int a[]={120,5,6,9,14};
    cout << f(a,5) << endl;
    return 0;
}
