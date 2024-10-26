#include <stdio.h>
//Najpierw i tak musimy podać liczbę wierszy i kolumn dla dwóch rozpatrywanych macierzy w tym miejscu poniżej (są opisane)

int i = 2; //macierz 1 wiersze
int j = 2; // macierz 1 kolumny
int n = 2; // macierz 2 wiersze
int m = 2; // macierz 2 kolumny
int Dzialanie;
int macierz[10][10];
int wynik[10][10];
int macierz1[10][10], macierz2[10][10];

void Dodawanie(int macierz1[10][10], int macierz2[10][10], int wynik[10][10], int i, int j) {
    for (int w = 0; w < i; w++) {
        for (int k = 0; k < j; k++) {
            wynik[w][k] = macierz1[w][k] + macierz2[w][k];
        }
    }
}

void Odejmowanie(int macierz1[10][10], int macierz2[10][10], int wynik[10][10], int i, int j) {
    for (int w = 0; w < i; w++) {
        for (int k = 0; k < j; k++) {
            wynik[w][k] = macierz1[w][k] - macierz2[w][k];
        }
    }
}

void Mnozenie(int macierz1[10][10], int macierz2[10][10], int wynik[10][10], int i, int j, int m) {
    for (int w = 0; w < i; w++) {
        for (int k = 0; k < m; k++) {
            wynik[w][k] = 0;
            for (int l = 0; l < j; l++) {
                wynik[w][k] += macierz1[w][l] * macierz2[l][k];
            }
        }
    }
}

void macierzWynik(int macierz[10][10], int i, int j)
{
    for (int w = 0; w < i; w++) {
        for (int k = 0; k < j; k++) {
            printf("%d\t", macierz[w][k]);
        }
        printf("\n");
    }
}

int main() {

    void wyswietlMacierz1(int macierz1[10][10], int i, int j);
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            printf("element z macierz1[%d][%d] = ", x, y);
            scanf("%d", &macierz1[x][y]);
        }
    }
    printf("macierz pierwsza to: \n");
    for (int w=0; w<i; w++) {
        for (int k=0; k<j; k++)
        {
            printf("%d\t", macierz1[w][k]);
        }
        printf("\n");
    }


    void wyswietlMacierz2(int macierz2[10][10], int n, int m);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            printf("element z macierz2[%d][%d] = ", x, y);
            scanf("%d", &macierz2[x][y]);
        }
    }
    printf("macierz druga to: \n");
    for (int p=0; p<n; p++) {
        for (int r=0; r<m; r++) {
            printf("%d\t", macierz2[p][r]);
        }
        printf("\n");
    }

    printf("Podaj dzialanie, jakie chcesz wykonac, gdzie: \n 1 to dodawanie, 2 to odejmowanie, 3 to mnozenie. \n");
    printf("Przypominam tylko, ze dodawanie i odejmowanie wymaga, by wymiary macierzy byly takie same \n a mnozenie, by liczba kolumn macierzy 1 byla taka jak liczba wierszy macierzy 2 \n");
    scanf("%d", &Dzialanie);

    if (Dzialanie == 1) {
        if (i == n &&  j == m) {
        Dodawanie (macierz1, macierz2, wynik, i, j);
            printf("Wynik to:\n");
            macierzWynik(wynik, i, j);
        }
        else {
            printf("Wymiary macierzy zle");
        }
    }
    if (Dzialanie == 2) {
        if (i == n &&  j == m) {
            Odejmowanie (macierz1, macierz2, wynik, i, j);
            printf("Wynik to:\n");
            macierzWynik(wynik, i, j);
        }
        else {
            printf("Wymiary macierzy zle");
        }
    }
    if (Dzialanie == 3) {
        if (j == n)
            {
            Mnozenie(macierz1, macierz2, wynik, i, j, m);
            printf("Wynik mnozenia macierzy:\n");
            macierzWynik(wynik, i, m);
        }
        else {
            printf("Zle wymiary macierzy.\n");
        }
    }

    return 0;

}

