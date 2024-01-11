// funzione che stabilisce se un punto è all'interno di un cerchio.
#include<iostream>
#include<cmath>
using namespace std;

bool inCircle(double x, double y, double xc, double yc, double r) {
    double d;
    d = sqrt((x-xc)*(x-xc) + (y-yc)*(y-yc));
    return d <= r;
}

int main() {
    double xp,yp,xc,yc,r;
    cout << "Inserire coordinate del punto [xp yp]: ";
    cin >> xp >> yp;
    cout << "Inserire coordinate del centro del cerchio [xc yp]: ";
    cin >> xc >> yc;
    cout << "Inserire lunghezza del raggio: ";
    cin >> r;
    if (inCircle(xp,yp,xc,yc,r))
        cout << "Il punto è nel cerchio.\n";
    else
        cout << "Il punto non è nel cerchio.\n";
    return 0;
}