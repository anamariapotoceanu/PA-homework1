#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define LIM 0.01

using namespace std;

// Determinarea puterii minime
double find_power(int n, int P[], int C[], double optimCurrent) {
    double minPower, power;
    int i;
    minPower = P[0];
    for (i = 0; i < n; i++) {
        power = P[i] - abs(optimCurrent - C[i]);
        minPower = min(minPower, power);
    }
    return minPower;
}

// Gasirea curentului minim se realizeaza prin cautare binara
double find_current(int n, int P[], int C[]) {
    int minCurrent, maxCurrent, i, steps;
    double optimCurrent;
    // Calculam minimul curentului de alimentare
    minCurrent = C[0];
    for (i = 0; i < n; i++) {
        minCurrent = min(minCurrent, C[i]);
    }
    double left;
    left = minCurrent;

    // Calculam maximul curentului de alimentare
    maxCurrent = C[0];
    for (i = 0; i < n; i++) {
        maxCurrent = max(maxCurrent, C[i]);
    }
    double right;
    right = maxCurrent;

    steps = 50;

    /* Cautarea binara se va realiza intre valorile de minim si maxim ale
    curentului de alimentare. */
    while (steps--) {
        // Oprim cautarea binara dupa un numar de pasi stabilit
        double middle, powerLeft, powerMiddle, dif;
        middle = (left + right) / 2.0;
        /* Intial vom considera curentul cautat ca fiind mijlocul intervalului.
        Vom verifica sa vedem unde avem o putere mai mare, la stanga sau la
        dreapta. */
        powerLeft = find_power(n, P, C, middle - LIM);
        powerMiddle = find_power(n, P, C, middle);
        dif = powerLeft - powerMiddle;
        /* Daca diferenta dintre puteri este una foarte mica, inseamna ca
        am gasit o aproximare suficient de buna pentru curentul cautat. */

        if (dif <= LIM) {
            optimCurrent = middle;
        }
        // Se ajusteaza intervalul
        if (dif > 0) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return optimCurrent;
}

int main() {
    ifstream fin("servere.in");
    int n, i;
    fin >> n;

    int P[n], C[n];

    for (i = 0; i < n; i++)
        fin >> P[i];
    for (i = 0; i < n; i++)
        fin >> C[i];
    fin.close();

    double optimCurrent, minPower;
    optimCurrent = find_current(n, P, C);
    minPower = find_power(n, P, C, optimCurrent);

    ofstream fout("servere.out");
    fout << fixed << setprecision(1) << minPower << "\n";
    fout.close();

    return 0;
}
