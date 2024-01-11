// selection sorter (sorts in non-descending order)
#include <iostream>
using namespace std;

/*Creates an array by making the user input the elements*/
void read_array(int v[], int n)
{
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

/*Prints the array on screen*/
void print_array(int v[], int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

/*Searches the minimum between the elements in the interval: [first, last]*/
int search_min(int v[], int first, int last)
{
    int pos = first;
    for (int i = first + 1; i <= last; i++)
        if (v[i] < v[pos])
            pos = i;
    return pos;
}

/*Swaps two elements*/
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    int x[n];
    read_array(x, n);
    for (int i = 0; i <= n - 2; i++)
    {
        int min;
        min = search_min(x, i, n - 1);
        swap(x[i], x[min]);
    }
    cout << "The ordered array is: ";
    print_array(x, n);
    return 0;
}