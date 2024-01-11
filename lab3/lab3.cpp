#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int *alloca_vettore(int n);

void dealloca_vettore(int *v);

int *legge_vettore(int n);

void stampa_vettore(int *s, int k);

int numero_casuale(int m, int M);

int *vettore_casuale(int k, int mm, int MM);

int *somma_vettori(int *v1, int *v2, int k);

int *differenza_vettori(int *v1, int *v2, int k);

int *prodotto_scalare_vettore(int *v1, int n, int k);

int prodotto_scalare(int *v1, int *v2, int k);

double norma_vettore(int *v, int k);

int search_max(int *v, int first, int last);

void swap(int &a, int &b);

void selection_sort(int *v, int k);

int partizione_vettore(int *v, int inf, int sup);

void quick_sort(int *v, int inf, int sup, int k);

int *massima_sequenza_crescente(int *v, int k, int &size);

int *differenza_tra_vettori(int *v1, int *v2, int k1, int k2, int &size);

int main()
{
	srand(time(0)); // si inizializza la generazione di numeri casuali
					// e' necessario farlo una volta all'inizio dell'esecuzione

	int *v1, *v2, s;

	do
	{
		cout << "Dimensione del vettore? ";
		cin >> s;
		if (s <= 0)
			cout << "La dimensione deve essere > 0" << endl;
	} while (s <= 0);

	v1 = legge_vettore(s);
	cout << "v1: ";
	stampa_vettore(v1, s);

	/*int indice_perno = partizione_vettore(v1, 0, s - 1);
	cout << "L'indice del perno è: " << indice_perno << endl;*/


	int *seq;
	int size;
	seq = massima_sequenza_crescente(v1, s, size);
	cout << "Massima sequenza di v1: ";
	stampa_vettore(seq, size);


	// dopo aver completato vettore_casuale
	// si può testarlo con le seguenti righe:
	// v2=vettore_casuale(20, 5, 10);
	// stampa_vettore(v2,20);
	// delete[] v2;
	v2 = vettore_casuale(s, 0, 5);
	cout << "v2: ";
	stampa_vettore(v2, s);

	int *vettore_differenza;
	int dimensione;
	vettore_differenza=differenza_tra_vettori(v1,v2,s,s, dimensione);
	cout << "vettore differenza: ";
	stampa_vettore(vettore_differenza, dimensione);

	quick_sort(v1, 0, s - 1, s);
	cout << "v1 riordinato: ";
	stampa_vettore(v1, s);

	/*int *somma, *diff, *scal;
	int prod_scal, max;
	double norma;

	somma = somma_vettori(v1, v2, s);
	cout << "v1 + v2: ";
	stampa_vettore(somma, s);

	diff = differenza_vettori(v2, v1, s);
	cout << "v2 - v1: ";
	stampa_vettore(diff, s);

	int n;
	cout << "Inserire n: ";
	cin >> n;
	scal = prodotto_scalare_vettore(v1, n, s);
	cout << "v1 * n: ";
	stampa_vettore(scal, s);

	prod_scal = prodotto_scalare(v1, v2, s);
	cout << "v1 * v2: " << prod_scal << endl;

	norma = norma_vettore(v1, s);
	cout << "||v1||: " << norma << endl;

	max = search_max(v1, 1, s - 1);
	cout << "Indice del valore massimo tra il secondo e il penultimo elemento: " << max << endl;

	double start = clock();
	selection_sort(v2, s);
	double end = clock();
	double seconds = (end - start) / CLOCKS_PER_SEC;
	cout << "Tempo per eseguire 'selection_sort(v2)': " << seconds << endl;

	delete[] somma;
	delete[] diff;
	delete[] scal;
	delete[] v2;*/
	delete[] v1;
	return 0;
}

// alloca memoria per un array di n int
// restituisce l'indirizzo dell'array
int *alloca_vettore(int n)
{
	int *v;
	v = new int[n];
	return v;
}

// libera la memoria occupata da un array di int
void dealloca_vettore(int *v)
{
	delete[] v;
}

// legge dalla tastiera un array di n int
// l'array è creata nella funzione con allocazione dinamica
// restituisce l'indirizzo dell'array
int *legge_vettore(int n)
{
	int *v;
	v = alloca_vettore(n); // alloca memoria per l'array
	for (int i = 0; i < n; i++)
	{
		cout << "elemento numero " << i + 1 << ": ";
		cin >> v[i];
	}
	return v; // restituisce l'indirizzo dell'array
}

// stampa un array di k int a video
void stampa_vettore(int *s, int k)
{
	for (int j = 0; j < k; j++)
		cout << s[j] << " ";
	cout << endl;
}

// restituisce un int casuale fra m e M
int numero_casuale(int m, int M)
{
	int r;
	r = rand() % (M - m + 1) + m;
	return r;
}

// genera un array di k int casuali
// alloca memoria per l'array
// riempie l'array con numero casuali fra mm e MM
// restituisce l'indirizzo dell'array
int *vettore_casuale(int k, int mm, int MM)
{
	int *r;

	// allocare memoria per il vettore casuale chiamando alloca_vettore
	r = alloca_vettore(k);

	// riempire l'array con numeri casuali con un ciclo
	// chiamando numero_casuale
	for (int i = 0; i < k; i++)
		r[i] = numero_casuale(mm, MM);

	// restituire l'indirizzo dell'array
	return r;
}

// calcola la somma di due vettori v1 e v2 ciascuno con k elementi
// alloca memora per il vettore risultante
// calcola la somma elemento per elemento con un ciclo
// restituisce l'indirizzo dell'array risultante
int *somma_vettori(int *v1, int *v2, int k)
{
	int *ris;

	// allocare memoria per il vettore risultante chiamando alloca_vettore
	ris = alloca_vettore(k);
	// riempire l'array ris con la somma di v1 e v2 elemento per elemento
	// con un ciclo
	for (int i = 0; i < k; i++)
		ris[i] = v1[i] + v2[i];
	// restituire l'indirizzo dell'array
	return ris;
}

int *differenza_vettori(int *v1, int *v2, int k)
{
	int *ris;
	ris = alloca_vettore(k);
	for (int i = 0; i < k; i++)
		ris[i] = v1[i] - v2[i];
	return ris;
}

int *prodotto_scalare_vettore(int *v1, int n, int k)
{
	int *ris;
	ris = alloca_vettore(k);
	for (int i = 0; i < k; i++)
		ris[i] = v1[i] * n;
	return ris;
}

int prodotto_scalare(int *v1, int *v2, int k)
{
	int ris = 0;
	for (int i = 0; i < k; i++)
		ris += v1[i] * v2[i];
	return ris;
}

double norma_vettore(int *v, int k)
{
	double ris;
	ris = sqrt(prodotto_scalare(v, v, k));
	return ris;
}

int search_max(int *v, int first, int last)
{
	int pos = first;
	for (int i = first + 1; i <= last; i++)
		if (v[i] > v[pos])
			pos = i;
	return pos;
}

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void selection_sort(int *v, int k)
{
	int max;
	for (int i = 1; i < k; i++)
	{
		max = search_max(v, v[0], v[k - i]);
		swap(v[max], v[k - i]);
	}
}

// es 5
int partizione_vettore(int *v, int inf, int sup)
{
	int p = v[inf];
	int i = inf + 1;
	int j = sup;
	while (i <= j)
	{
		if (v[i] <= p)
		{
			i++;
			continue;
		}
		else if (v[i] > p && v[j] > p)
		{
			j--;
			continue;
		}
		else if (v[i] > p && v[j] <= p)
		{
			swap(v[i], v[j]);
			i++;
			j--;
			continue;
		}
	}
	swap(v[inf], v[j]);
	return j;
}

// es 6
void quick_sort(int *v, int inf, int sup, int k)
{
	if (k < 2)
	{
		return;
	}
	int p = partizione_vettore(v, inf, sup);
	quick_sort(v, inf, p, p - inf);
	quick_sort(v, p + 1, sup, sup - p - 1);
}

// es 7
int *massima_sequenza_crescente(int *v, int k, int &size)
{
	int c = 1;
	int d, max = 1, i_max = 0;
	for (int i = 0; i < k; i++)
	{
		if (v[i + 1] > v[i])
		{
			if (c == 1)
			{
				d = i;
			}
			c++;
		}
		else
		{
			if (c > max)
			{
				max = c;
				i_max = d;
			}
			c = 1;
		}
	}
	int *v1 = alloca_vettore(max);
	for (int i = 0; i < max; i++)
	{
		v1[i] = v[i_max + i];
	}
	size = max;
	return v1;
}

// es 8
int *differenza_tra_vettori(int *v1, int *v2, int k1, int k2, int &size)
{
	int n = 0;
	// trova il numero di elementi dell'array differenza
	for (int i = 0; i < k1; i++) /*per ogni elemento di v1*/
	{
		for (int j = 0; j < k2; j++) /*per ogni elemento di v2*/
		{
			if (v1[i] == v2[j]) /*controlla se l'elemento i-esimo di v1 sta in posizione j-esima di v2*/
			{
				break;
			}
			else if (j == k2-1)
			{
				n++;
			}
		}
	}
	int *v;
	v = alloca_vettore(n);
	// crea l'array-differenza
	int indice = 0;
	for (int i = 0; i < k1; i++) /*per ogni elemento di v1*/
	{
		for (int j = 0; j < k2; j++) /*per ogni elemento di v2*/
		{
			if (v1[i] == v2[j]) /*controlla se l'elemento i-esimo di v1 sta in posizione j-esima di v2*/
			{
				break;
			}
			else if (j == k2-1)
			{
				v[indice] = v1[i];
				indice++;
			}
		}
	}
	size = n;
	return v;
}