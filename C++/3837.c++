#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <queue>

using namespace std;

int main() {
    string *fichas = new string[52];
    queue<string> jogadores[4];

    for (int i = 0; i < 52; i++) {
        cin >> fichas[i];
    }

    map<int, char> cores{{0, 'A'}, {1, 'V'}, {2, 'R'}, {3, 'B'}};
    map<char, int> coresJogadores;

    for (int i = 0; i < 52; i++) {
        string ficha = fichas[i];
        int jogador = ficha[0] - '1';
        char cor = ficha[1];

        jogadores[jogador].push(ficha);

        if (cor != 'P') {
            coresJogadores[cor] = jogador;
        }
    }

    stack<char> torres[6];

    int count = 0;

    while (count < 36) {
        for (int i = 0; i < 4; i++) {
            int jogador = coresJogadores[cores[i]];
            string ficha = jogadores[jogador].front();
            char cor = ficha[1];
            int torre = ficha[2] - '1';

            if (cor != 'P') {
                bool allFull = true;

                for (int j = 0; j < 6; j++) {
                    if (torres[j].size() < 6) {
                        allFull = false;
                    }
                }

                if (!allFull) {
                    while (torres[torre].size() == 6) {
                        torre = (torre + 1) % 6;
                    }

                    if (torres[torre].size() < 6) {
                        torres[torre].push(cor);
                        count++;
                    }

                    jogadores[jogador].pop();
                }
            } else {
                if (!torres[torre].empty()) {
                    torres[torre].pop();
                    count--;
                }

                jogadores[jogador].pop();
            }

        }
    }

    map<char, int> coresCount{{'A', 0}, {'V', 0}, {'R', 0}, {'B', 0}};
    queue<char> tabuleiro[6];

    int maior = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (j == i) {
                coresCount[torres[j].top()]++;

                if (coresCount[torres[j].top()] > maior) {
                    maior = coresCount[torres[j].top()];
                }
            }

            tabuleiro[j].push(torres[j].top());

            // cout << torres[j].top() << " ";
            torres[j].pop();
        }
        // cout << "\n";
    }

    cout << "Vencedores:\n";
    int countVencedores = 0;

    for (int i = 0; i < 4; i++) {
        if (coresCount[cores[i]] == maior) {
            if (countVencedores) {
                cout << " ";
            }

            cout << cores[i];

            countVencedores++;
        }
    }

    cout << "\n";

    for (int i = 0; i < 4; i++) {
        cout << "Mao do jogador " << i + 1 << ":";

        if (!jogadores[i].empty()) {
            while (!jogadores[i].empty()) {
                cout << " " << jogadores[i].front();
                jogadores[i].pop();
            }
        } else {
            cout << " Vazia";
        }

        cout << "\n";
    }

    cout << "Tabuleiro final:\n";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << tabuleiro[j].front();
            tabuleiro[j].pop();

            if (j != 5) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
