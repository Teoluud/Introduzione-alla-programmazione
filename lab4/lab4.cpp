#include <iostream>
#include <cmath>

using namespace std;

class poly
{

private:
    double *v; // vettore di coefficienti
    int g;     // grado del polinomio

public:
    // costruttore senza parametri:
    poly()
    {
        v = NULL;
        g = -1;
    }
    // costruttore con grado e coefficienti:
    poly(double *vv, int gg)
    {
        g = gg;
        v = new double[g + 1];
        for (int i1 = 0; i1 <= g; i1++)
            v[i1] = vv[i1];
    }
    // distruttore
    ~poly()
    {
        if (g != -1)
            delete[] v;
    }

    // altre funzioni:
    void print();
    void read();
    void set(double coefficiente, int grado);
    void set_all(double *vv, int gg);
    double *coefficienti();
    int grado();
    double evaluate(double);
    void sum(const poly &, poly &);
    void product(const poly &, poly &);
    void derive(poly &);
    double root(double);
};

// stampa polinomio
void poly::print()
{
    for (int i1 = 0; i1 <= g; i1++)
    {
        cout << v[i1] << "*x^" << i1;
        if (i1 != g)
            cout << " + ";
    }
    cout << endl;
}

// legge polinomio da tastiera
void poly::read()
{
    cout << "Grado del polinomio: ";
    cin >> g;
    cout << "Coefficienti:\n";
    v = new double[g + 1];
    for (int i1 = 0; i1 <= g; i1++)
        cin >> v[i1];
}

// modifica il coefficiente del grado corrispondente
void poly::set(double coefficiente, int grado)
{
    v[grado] = coefficiente;
}

// modifica tutti i coefficienti del polinomio.
void poly::set_all(double *vv, int gg)
{
    if (g != -1)
        delete[] v;
    g = gg;
    v = new double[g + 1];
    for (int i = 0; i <= g; i++)
        v[i] = vv[i];
}

// getter per i coefficienti
double *poly::coefficienti()
{
    return v;
}

// getter per il grado
int poly::grado()
{
    return g;
}

// calcola il valore del polinomio sostituendo x reale.
double poly::evaluate(double x)
{
    double s = 0.0, pow = 1.0;
    for (int i1 = 0; i1 <= g; i1++)
    {
        s += v[i1] * pow;
        pow *= x;
    }
    return s;
}

// somma di polinomi
// i due polinomi sono descritti da this e p
// risultato e` creato in r
void poly::sum(const poly &p, poly &r)
{
    r.g = g;
    if (p.g > g)
        r.g = p.g;
    r.v = new double[r.g + 1];
    for (int ir = 0; ir <= r.g; ir++)
    {
        r.v[ir] = 0.0;
        if (ir <= g)
            r.v[ir] += v[ir];
        if (ir <= p.g)
            r.v[ir] += p.v[ir];
    }
}

// prodotto di due polinomi
void poly::product(const poly &p, poly &r)
{
    r.g = g + p.g;
    r.v = new double[r.g + 1];
    // rendere nulli tutti gli elementi del vettore risultato
    for (int k = 0; k <= r.g; k++)
        r.v[k] = 0.0;
    // aggiungere al coefficiente di grado n tutti i possibili prodotti dei coefficienti t.c. deg(p1.v[i]*p2.v[j]) = n
    for (int i = 0; i <= g; i++)
    {
        for (int j = 0; j <= p.g; j++)
        {
            r.v[i + j] += v[i] * p.v[j];
        }
    }
}

// calcola la derivata di un polinomio
void poly::derive(poly &r)
{
    r.g = g-1;
    r.v = new double[r.g + 1];
    for (int i = g; i > 0; i--)
    {
        r.v[i - 1] = v[i] * i;
    }
}

// calcola uno zero del polinomio con il metodo di Newton
double poly::root(double x0)
{
    double xn, xn1;
    poly der;
    derive(der);
    xn = x0;
    xn1 = xn - evaluate(xn)/der.evaluate(xn);
    while (abs(xn1-xn) >= 1.e-6)
    {
        xn = xn1;
        xn1 = xn - evaluate(xn)/der.evaluate(xn);
    }
    return xn1;
}

int main()
{
    double coeff[] = {-1.2, 2.0, 3.0};
    poly a(coeff, 2), b, c, prodotto, derivata;
    double root, x0;

    cout << "Il primo polinomio e': ";
    a.print();

    b.read();
    cout << "Il secondo polinomio e': ";
    b.print();

    a.sum(b, c);
    cout << "La somma dei due polinomi e':";
    c.print();

    a.product(b, prodotto);
    cout << "Il prodotto dei due polinomi e': ";
    prodotto.print();

    b.derive(derivata);
    cout << "La derivata del secondo polinomio e': ";
    derivata.print();

    cout << "Inserire il punto di partenza per il metodo di Newton: ";
    cin >> x0;
    root = b.root(x0);
    cout << "Una radice del secondo polinomio e': " << root << endl;


    /*cout << "Modifica il primo polinomio: ";
    double newcoeff[] = {1, 2, -2, 3};
    a.set_all(newcoeff, 3);
    a.print();*/
    return 0;
}
