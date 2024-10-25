#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int maxseq(vector<int>& sirA, vector<int>& sirB, int n, int m) {
    int sumA, sumB, cnt, i, j, reset;
    cnt = 0;
    i = 0;
    j = 0;
    reset = 1;
    // Pentru fiecare sir in parte vom considera cate un contor.
    while (i < n && j < m) {
        /* In cazul in care suntem la prima parcurgere sau daca am ajuns
        la sume egale, atunci va trebui sa incepem urmatoarea parcurgere
        cu elementele curente din cele doua siruri. */

        if (reset) {
            sumA = sirA[i];
            sumB = sirB[j];
        }
        // Daca sumele sunt egale, cresc ambii contori
        if (sumA == sumB) {
            reset = 1;
            cnt++;
            i++;
            j++;
        /* Daca in primul sir am o suma mai mare decat in al doilea sir, atunci
        va trebui sa adaug pentru sumaB urmatorul element. Cresc contorul j si
        adaug urmatorul element din B la suma. */
        } else if (sumA > sumB) {
            if (j + 1 > m) {
                continue;
            } else {
                reset = 0;
                sumB += sirB[++j];
            }
        /* Daca al doilea sir se constanta ca are o suma mai mare decat a 
        primului, atunci este necesara cresterea primul contor:i si adaugarea
        urmatorului element din primul sir la suma respectiva. */
        } else  if (sumA < sumB) {
            if (i + 1 > n) {
                continue;
            } else {
                reset = 0;
                sumA += sirA[++i];
            }
        }
    }
    /* Daca am ajuns la final doar cu un contor, cele doua siruri nu pot fi
    compresate. */
    if ((i == n && j != m) || (i != n && j == m)) {
        cnt = -1;
    }
    return cnt;
}

int main() {
    int n, m, i;
    ifstream fin("compresie.in");
    fin >> n;
    vector<int> sirA(n + 1);
    for (i = 0; i < n; i++) {
        fin >> sirA[i];
    }
    fin >> m;
    vector<int> sirB(m + 1);

    for (i = 0; i < m; i++) {
        fin >> sirB[i];
    }
    fin.close();
    int l;
    l = maxseq(sirA, sirB, n, m);
    ofstream fout("compresie.out");
    if (l == 0) {
        fout<< -1;
    } else {
        fout << l << endl;
    }
    fout.close();
    return 0;
}
