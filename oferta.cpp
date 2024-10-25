#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;


double findPrice(vector<int>& price, int n) {
    vector<double> dp(n + 1);
    int i;
    // In cazul in care nu avem produse, profitul va fi 0
    dp[0] = 0;

    // Daca vom cumpara un singur produs, profitul este egal cu pretul
    if (n >= 1) {
        dp[1] = price[1];
    }

    // Pentru doua produse, aplicam reducerea de 50% pentru produsul mai ieftin
    if (n >= 2) {
        int sumPrice, otherPrice, minPrice;
        double reducePrice;
        sumPrice = price[1] + price[2];
        minPrice = min(price[1], price[2]);
        otherPrice = sumPrice - minPrice;
        reducePrice = minPrice / 2.0;
        dp[2] = otherPrice + reducePrice;
    }

    // Daca avem 3 produse sau mai multe, vom trata toate cazurile
    for (i = 3; i <= n; i++) {
        int sumPrice, otherPrice, minPrice, restPrice;
        double reducePrice;
        // Cazul cand nu grupam produsele, acestea raman individuale
        dp[i] = dp[i - 1] + price[i];

        /* Cazul cand produsele vor fi grupate cate doua si vom aplica
        reducerea de 50% pentru produsul mai ieftin*/
        sumPrice = price[i - 1] + price[i];
        minPrice = min(price[i - 1], price[i]);
        otherPrice = sumPrice - minPrice;
        reducePrice = minPrice / 2.0;
        dp[i] = min(dp[i], dp[i - 2] + otherPrice + reducePrice);

        /* Cazul cand produsele vor fi grupate cate 3 si vom avea gratuitate
        pentru produsul cel mai ieftin*/
        sumPrice += price[i - 2];
        minPrice = min(minPrice, price[i - 2]);
        restPrice = sumPrice - minPrice;
        dp[i] = min(dp[i], dp[i - 3] + restPrice);
    }

    return dp[n];
}

int main() {
    ifstream fin("oferta.in");

    int n, k, i;
    fin >> n >> k;
    vector<int> price(n + 1);
    for (i = 1; i <= n; i++) {
        fin >> price[i];
    }
    fin.close();

    ofstream fout("oferta.out");
     if (k != 1) {
        fout << "-1";
        fout << '\n';
    }
    double priceMin;
    priceMin = findPrice(price, n);
    fout << fixed << setprecision(1) << priceMin;
    fout << '\n';

    fout.close();

    return 0;
}
