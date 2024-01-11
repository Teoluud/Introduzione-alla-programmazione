// Funzione che restituisce la posizione di un corpo in un moto uniformemente accelerato
#include<iostream>
using namespace std;

double position(double t, double a, double v0, double s0) {
    double s;
    s = s0 + v0*t + 1/2*a*t*t;
    return s;
}

int main() {
    double a,v0,s0,t=0;
    int deltaT,n;

    cout << "Dammi l'accelerazione, la velocita' e la posizione iniziali: ";
    cin >> a >> v0 >> s0;
    cout << "Ogni quanti secondi vuoi stampare la posizione? ";
    cin >> deltaT;
    cout << "Per quante volte vuoi stampare la posizione? ";
    cin >> n;

    int i=0;

    while(i<n){
        cout << i+1 << ") Posizione: " << position(t, a, v0, s0) << " al tempo: " << t << " secondi\n";
        t += deltaT;
        i++;
    }
    return 0;
}