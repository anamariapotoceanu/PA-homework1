#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MOD 1000000007
long long power(long long x, long long n) {
    long long p = 1;
    if (n == 0) {
        return 1;
    }
    while (n) {
        if (n % 2 == 1) {
            p = (p % MOD * x % MOD) % MOD;
        }
        x = (x % MOD * x % MOD) % MOD;
        n = n / 2;
    }
    return p;
}

long long models(vector<char>&types, vector<int>&numbers, int n) {
    char type_prev;
    long long total_mod = 1;
    int i;
    /*Daca tabloul va incepe cu zone de tipul H atunci prima zona va fi
    colorata in 6 moduri, iar urmatoarele zone de acelasi tip in 3 moduri*/
    if (types[0] == 'H') {
        type_prev = 'H';
        int number;
        number = numbers[0];
        number--;
        numbers[0] = number;
        if (numbers[0] != 0) {
            long long result;
            result = (power(3, numbers[0])) % MOD;
            total_mod = 6 * result;
        }
    }
    /*Daca tabloul va incepe cu zone de tipul V atunci prima zona va fi
    colorata in 3 moduri, iar urmatoarele zone de acelasi tip in 2 moduri*/
     if (types[0] == 'V') {
        total_mod = 3;
        type_prev = 'V';
        int number;
        number = numbers[0];
        number--;
        numbers[0] = number;
        if (numbers[0] != 0) {
            long long result;
            // Aflam numarul de moduri in care vom colora urmatoarele zone V
            result = (power(2, numbers[0])) % MOD;
            total_mod *= result;
        }
    }

    /*Pentru urmatoarele secvente care urmeaza dupa prima, am dedus formule
    pentru toate combinatiile posibile */
    for (i = 1; i < n; i++) {
        /*Daca actuala zona este H, iar inainte am avut tot H, atunci fiecare
        zona se va putea colora in 3 moduri */
        if (types[i] == 'H' && type_prev == 'H') {
            long long result;
            result = (power(3, numbers[i])) % MOD;
            total_mod = (total_mod *  result) % MOD;
            type_prev = 'H';
                continue;
        }
        /* Daca zona actuala este V, iar inainte am avut H, atunci primul V
        va putea fi colorat doar intr-un mod, iar urmatoarele nr-1 zone in 2
        moduri*/
        if (types[i] == 'V' && type_prev == 'H') {
            long long result;
            int nr = numbers[i];
            result = (power(2, nr - 1)) % MOD;

            total_mod = (total_mod *  result) % MOD;
            type_prev = 'V';
            continue;
        }
        /* Daca zona actuala este H, iar inainte am avut V, atunci prima zona
        H va putea fi colorata in 2 moduri, iar urmatoarele nr-1 in 3 moduri*/
        if (types[i] == 'H' && type_prev == 'V') {
            long long result;
            total_mod *= 2;
            int nr = numbers[i];
            result = (power(3, nr - 1)) % MOD;

            total_mod = (total_mod *  result) % MOD;
            type_prev = 'H';
            continue;
            }
        /* Daca zona actuala este V, iar inainte am avut tot V, atunci toate
        zonele care urmeaza de tipul V vor putea fi colorate in 2 moduri*/
        if (types[i] == 'V' && type_prev == 'V') {
            long long result;
            result = (power(2, numbers[i])) % MOD;
            total_mod = (total_mod *  result) % MOD;
            type_prev = 'V';
            continue;
        }
    }
    return total_mod;
}

int main() {
    int n;
    ifstream fin("colorare.in");
    fin >> n;
    vector<int> numbers(n);
    vector<char> types(n);
    int i;
    for (i = 0; i < n; i++) {
        fin >> numbers[i] >> types[i];
    }
    fin.close();

    ofstream fout("colorare.out");
    long long total_mod;
    total_mod = models(types, numbers, n);
    fout<<total_mod<<endl;
    fout.close();
    return 0;
}
