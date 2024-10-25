
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define LEN_ALPHA 9
#define MAX 1000
using namespace std;

int lenght_max(string words[], char* alphabet, int n,
            int total_letters) {
    int max_password, cnt;
    char letter;
    max_password = 0;

    // Pentru fiecare litera din alfabet vom construi matricea dp aferenta
    for (int i = 0; i < strlen(alphabet); i++) {
        letter = alphabet[i];
        int W = 0;
        int ap[MAX];
        for (int i = 0; i < n; i++) {
            int k;
            cnt = 0;
            k = 0;
            while (words[i][k] != '\0') {
                if (words[i][k++] == letter) {
                    cnt++;
                }
            }
            ap[i] = cnt;
        }
        int total_ap = 0;
        // Aflam numarul total de aparitii ale literei in toate cuvintele.
        for (int i = 0; i < n; i++) {
            total_ap += ap[i];
        }
        // W reprezinta numarul literelor nedominante
        W = total_letters - total_ap;

        /* Vom crea matricea necesara care va avea ca numar de linii, numarul
        total de cuvinte, iar ca numar de coloane numarul literelor
        nedominante. */
        vector< vector<int> > dp(n + 1, vector<int>(W + 1));

        // Cazul de baza cand nu avem cuvinte
        for (int cap = 0; cap <= W; cap++) {
            dp[0][cap] = 0;
        }
        for (int i = 1; i <= n; i++) {
            // Profitul este dat de lungimea cuvantului
            int p;
            p = words[i - 1].size();
            for (int cap = 0; cap <= W; cap++) {
                int w;
                // Greutatea fiecarui cuvant va fi numarul literelor nedomiante
                w = words[i - 1].size() - ap[i - 1];
                // Aleg sa nu adaug cuvantul curent la parola
                dp[i][cap] = dp[i-1][cap];
                // Verificam daca este posibila adaugarea cuvantului
                if (cap - w >= 0) {
                    /* Daca pot sa adaug cuvantul, inseamna ca pentru el trebuie
                    sa rezerv w litere nedominante. */
                    int sol_aux;
                    sol_aux = dp[i-1][cap - w] + p;
                    dp[i][cap] = max(dp[i][cap], sol_aux);
                }
            }
        }
        /* Parolele obtinute prin analiza tuturor cuvintelor se vor afla pe
        ultima linie. */
        for (int j = 0; j < W; j++) {
            int password, dominant_app;
            password = dp[n][j];
            dominant_app = password - j;
        // Vom alege parola maxima pentru care litera curenta ramane dominanta
            if (dominant_app > password / 2) {
                max_password = max(max_password, password);
            }
        }
    }

    return max_password;
}


int main() {
    int n, i, lenghtMax, j, total_letters;
    total_letters = 0;
    char alphabet[9];
    ifstream fin("criptat.in");
    fin >> n;
    string words[MAX + 1];
    for (i = 0; i < n; i++) {
        fin >> words[i];
        total_letters += words[i].size();
    }
    fin.close();

    int nr = 0;
    /* Vom parcurge fiecare cuvant in parte, pentru a forma alfabetul cu cele
    8 litere posibile */
    for (i = 0; i < n; i++) {
        j = 0;
        while (words[i][j] != '\0') {
            if (!strchr(alphabet, words[i][j])) {
                alphabet[nr++] = words[i][j];
            }
            j++;
        }
    }
    alphabet[nr] = '\0';

    lenghtMax = lenght_max(words, alphabet, n, total_letters);
    ofstream fout("criptat.out");
    fout << lenghtMax << endl;

    fout.close();

    return 0;
}

