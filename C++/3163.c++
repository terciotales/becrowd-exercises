#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<string> avioes[4];
    queue<string> fila;
    string ponto, entrada = "1";
    int count = 0;

    // -1: oeste - 1º
    // -3: norte - 2º
    // -2: sul - 3º
    // -4: leste - 4º
    map<string, int> pontos{{"-1", 0}, {"-2", 2}, {"-3", 1}, {"-4", 3}};

    cin >> entrada;

    while (entrada != "0") {
        if (entrada == "-1" || entrada == "-2" || entrada == "-3" || entrada == "-4") {
            ponto = entrada;
        } else if (ponto == "-1" || ponto == "-2" || ponto == "-3" || ponto == "-4") {
            avioes[pontos[ponto]].push(entrada);
            count++;
        }

        cin >> entrada;
    }

    while (count) {
        for (int j = 0; j < 4; j++) {
            if (!avioes[j].empty()) {
                fila.push(avioes[j].front());
                avioes[j].pop();
                count--;
            }
        }
    }

    int size = fila.size();

    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << " ";
        }

        cout << fila.front();
        fila.pop();
    }

    cout << "\n";

    return 0;
}
