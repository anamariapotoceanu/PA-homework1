## Potoceanu Ana-Maria 321CA
## PA - Tema 1 - Tehnici de Programare

# Servere

- Pentru aceasta problema, m-am folosit de rezolvarea laboratorului 1, pus la
dispozitie pe Teams, de catre echipa PA.
-  Pentru aflarea curentului optim care aplicat serverelor va duce la cea
mai mare putere minima, vom cauta intre valorile de minim si de maxim ale
curentilor. 
- Calculam mijlocul si aflam in ce parte obtinem o valoare mai mare a puterii,
in stanga sau in dreapta. Acest lucru este necesar, deoarece trebuie sa obtinem
cea mai mare putere minima. Este important sa observam in ce parte putere se 
afla in crestere. Cautarea trebuie sa se realizeze din aproape in aproape,
astfel vom compara puterea corespunzatoare mijlocului si puterea
corespunzatoare unei valori foarte apropiate de mijloc. 
- Daca diferenta dintre puteri este una foarte mica (am considerat valoarea
0.01), inseamna ca am gasit o aproximare suficient de buna pentru curentul
optim cautat pentru care obtinem cea mai mare putere minima.
- Daca se constanta ca puterea mai mare se afla la stanga mijlocului, ajustam
intervalul: dreapta va deveni mijlocul, altfel stanga devine.
- Am ales un numar de 50 de pasi dupa care se va opri cautarea binara.
- Dupa aflarea curentului optim, am calculat minimul puterilor obtinute.
* Complexitate temporală : T = O(steps * n)
* Complexitate spațială : S = O(n)


# Colorare

- Pentru aceasta problema, am retinut intr-o variabila care este zona
precedenta care a fost colorata. Cazurile pentru prima zona, le-am tratat
separat, astfel:
* Daca prima secventa este pentru H, atunci am dedus ca prima zona H poate fi
colorata in 6 moduri, iar urmatoarele zone de acelasi tip doar in 3 moduri.
Pentru a afla numarul total de moduri in care pot fi colorate celelalte nr - 1
zone am aplicat ridicarea la putere in timp logaritmic. Acelasi procedeu l-am
aplicat si pentru V. In cazul lui V, prima zona poate fi colorata in 3 moduri,
iar urmatoarele doar in 2.
* Pentru secventele ramase, am considerat 4 cazuri, pentru toate combinatiile
posibile:
- H H: Daca zona actuala este H, iar zona de dinainte este tot H, atunci
fiecare zona va putea fi colorata in 3 moduri. Aflam numarul total prin
ridicare la putere. 
- H V: Daca zona actuala este H, iar zona de dinainte este V, atunci
fiecare zona V va fi colorata doar intr-un mod, iar urmatorele in 2 moduri.
- V H: Daca avem zona H si se constata ca zona precedenta este V, atunci
prima zona H poate fi colorata doar in 2 moduri, iar restul zonelor
ramase, de tipul H, in 3.
- V V: Daca avem doua secvente V atunci toate zonele pot fi colorate in 2
moduri.
* Numarul total de moduri pentru toate secventele se va inmulti la fiecare pas.
* Complexitate temporală : T = O(n)
* Complexitate spațială : S = O(n)

# Compresie

- Pentru a numara lungimea sirului obtinut prin comprimarea numerelor, am ales
sa folosesc o variabila pe care o cresc de fiecare data cand obtin sume comune.
- Initial, sumele le voi considera ca fiind primele elemente din cele doua siruri
si le compar. In cazul in care sumele sunt egale, atunci voi creste cei doi
contori pentru a putea parcurge sirurile pana la final. De asemenea, voi
creste si variabila care va numara lungimea totala a sirului care poate fi 
obtinut. Daca se constata faptul ca prima suma este mai mare decat a doua,
atunci va trebui sa cresc contorul doar pentru primul sir si sa adaug
la sumaA urmatorul numar. Fac acest lucru pana cand voi obtine in final
sume egale. 
- Poate fi si cazul cand cea de a doua suma este mai mare decat prima
caz in care va trebuie sa cresc al doilea contor si sa adaug la suma urmatorul
element. De fiecare data cand se constata ca am obtinut sume egale, inseamna
ca au putut fi comprimate numere din cele doua siruri pentru a obtine un nou
sir.
- Lungimea sirului este data de variabila pe care am crescut-o de fiecare data
cand aveam sume ale secventelor din cele doua siruri egale.
- Vom avea urmatoarele complexitati: 
* Complexitate temporală : T = O(n + m)
* Complexitate spațială : S = O(n + m)

# Criptat

- In cadrul acestei probleme, am folosit integral implementarea algoritmului
RUCSAC din cadrul laboratorului. 
(https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03)
- Dupa citirea listei de cuvinte, am construit un alfabet care contine maxim
8 litere, potrivit cerintei. Alfabetul il construim pe baza faptului ca stim
ca nu vor exista mai mult de 8 litere distincte din care vor fi construite
cuvintele.
- Pentru fiecare litera din alfabet consideram ca este dominanta. Vom crea
o matrice bidimensionala care va avea ca numar de linii numarul total de
cuvinte posibile + 1, iar ca numar de coloane numarul de litere nedominante +1.
Vom incepe prin calcularea numarul de aparitii ale literei considerata
dominanta in toate cuvintele disponibile. Prin analogie cu problema RUCSAC,
greutatea totala va fi de fapt numarul total de litere nedominante pe care le
putem adauga in parola, cu conditia ca litera dominanta sa-si pastreze
proprietatea. In cazul in care nu avem cuvinte, profitul este zero.
- In cadrul algoritmului, consider initial cazul cand aleg sa nu adaug cuvantul
la parola. In acest caz, se va alege cea mai buna parola formata din celelalte
i - 1 cuvinte. Pentru fiecare cuvant in parte, vom calcula greutatea sa. 
Greutatea reprezinta de fapt numarul de litere nedominante pe care le are
cuvantul. Daca alegem sa adaugam cuvantul la parola, trebuie luat in
considerare ca fiecare cuvant poate avea litere care ingreuneaza construirea
parolei.
- In cazul daca aleg sa adaug cuvantul la parola, inseamna ca trebuie sa
verific daca exista suficiente litere nedominante permise. Profitul care
se adauga va fi de fapt lungimea cuvantului.
- In final, dupa ce am luat in considerare toate literele, vom alege lungimea
maxima a parolei cu mentiunea ca litera dominanta sa ramana dominanta.
Numarul de aparitii al literei dominante va fi lungimea parolei din care se
scade numarul de aparitii pentru literele nedominante.
* Complexitate temporală: T = O(n∗W)
* Complexitate spațială: S = O(n∗W)

# Oferta

- Pentru aceasta problema am considerat dp[i] pretul pe care il obtinem grupand
produsele in diferite variante posibile. Pretul minim pe care il obtinem prin
gruparea produsele va fi, in final, dp[n].
* Pentru inceput am considerat cazurile de baza. Mai exact, prima data am luat
cazul cand nu avem produse pe banda, in acest caz profitul va fi 0. 
* Daca se constata ca avem cel putin un produs, atunci profitul pentru primul
element va fi chiar pretul sau. Daca avem cel putin doua produse, din punct
de vedere matematic, daca le vom grupa cate doua, vom obtine un pret mai mic
decat cazul cand alegem sa le luam individuale. Astfel, pentru acest caz am
aplicat reducerea de 50% pentru produsul mai ieftin. 
* Cazul general este reprezentat de situatia in care avem cel putin trei
produse. In aceasta situatie, putem alege cum sa le grupam si vom avea trei
variante. 
- Daca alegem ca ultimul produs sa ramana individual, atunci vom mai
avea de analizat i-1 produse. La pretul minim pe care trebuie sa-l obtinem vom
adauga pretulul produsului.
- Daca alegem ca ultimele doua produse sa fie grupate, atunci trebuie sa
aplicam reducerea de 50% produsului mai ieftin.
- Ultimul caz este reprezentat de cazul cand ultimele 3 produse vor fi luate
impreuna, iar produsul mai ieftin va fi gratuit. Pentru aceasta problema, vom
alege la fiecare pas minimul dintre preturile obtinute prin gruparea produselor
de pe banda.
* Complexitate temporală: T = O(n)
* Complexitate spațială: S = O(n)
