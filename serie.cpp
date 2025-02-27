#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Definizione della successione
double a(int n)
{
    return 1.0 / n / n / n;
}

// Calcolo somme parziali
double SommaParziale(int N)
{
    double sum = 0.0;
    for(int i = 1; i <= N; i++)
    {
        sum += a(i);
    }
    return sum;
}

// Discutere la convergenza
void convergenza(int MaxIterazioni, double precisione)
{
    double SommaPrecedente = 0.0;
    for(int N = 1; N <= MaxIterazioni; N++)
    {
        double SommaCorrente = SommaParziale(N);
        cout << "S(" << N << ") = " << fixed << setprecision(6) << SommaCorrente << endl;

        //Verifica convergenza
        if(N > 1 && fabs(SommaCorrente - SommaPrecedente) < precisione)
        {
            cout << "La serie converge con una somma approssimata di " << SommaCorrente << endl;
            return;
        }

        SommaPrecedente = SommaCorrente;
    }
    cout << "La serie non converge entro il numero massimo di iterazioni specificato" << endl;
}

int main()
{
    int MaxIterazioni;
    double precisione;
    cout << "Massimo di Iterazioni-> ";
    cin >> MaxIterazioni;
    cout << "Precisione-> ";
    cin >> precisione;
    convergenza(MaxIterazioni, precisione);
    return 0;
}