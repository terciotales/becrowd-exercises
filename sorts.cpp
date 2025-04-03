#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selection_sort(vector<int> vet, int n) {
    for (int i = 0; i < n; i++) {
        int aux = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < aux) {
                aux = j;
            }
        }

        if (aux != i) {
            swap(vet[i], vet[aux]);
        }
    }
}

void insertion_sort(vector<int> vet, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;

        while (j > 0 && vet[j] < vet[j - 1]) {
            swap(vet[j], vet[j - 1]);
            j--;
        }
    }
}

void merge(vector<int> &vector, int n, int ini, int fim) {
    int m = (ini + fim) / 2;
    int i = ini, j = m + 1, k = ini;
    int aux[n];

    while (i <= m && j <= fim) {
        if (vector[i] < vector[j]) {
            aux[k] = vector[i];
            i++;
        } else {
            aux[k] = vector[j];
            j++;
        }
        k++;
    }

    while (i <= m) {
        aux[k] = vector[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = vector[j];
        j++;
        k++;
    }

    for (i = ini; i <= fim; i++) {
        vector[i] = aux[i];
    }
}

void merge_sort(vector<int> &vector, int ini, int fim) {
    int m = (ini + fim) / 2;
    if (ini < fim) {
        merge_sort(vector, ini, m);
        merge_sort(vector, m + 1, fim);
        merge(vector, fim + 1, ini, fim);
    }
}

// Função para gerar um vetor aleatório
vector<int> generate_random_vector(size_t size) {
    vector<int> vec(size);
    mt19937 rng(random_device{}()); // Gerador de números aleatórios
    uniform_int_distribution<int> dist(1, 1000000); // Números entre 1 e 1.000.000

    for (size_t i = 0; i < size; i++) {
        vec[i] = dist(rng);
    }
    return vec;
}

// Função para medir o tempo de ordenação
template<typename SortFunction>
double measure_sort_time(vector<int> vec, int size, SortFunction sort_function) {
    auto start = high_resolution_clock::now();
    sort_function(vec, 0, size);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count(); // Tempo em milissegundos
}

int main() {
    vector<size_t> sizes = {1000, 10000, 100000}; // Tamanhos dos vetores
    cout << "Tamanho\tMergeSort\n";

    // vector<int> vetor = {10, 9, 124, 5, 1, 2, 4, 14, 12, 12};
    // merge_sort(vetor, 0, 9);
    // for (int i = 0; i < 10; i++) {
    // cout << vetor[i] << '\n';
    // }

    for (size_t size: sizes) {
        vector<int> original_vec = generate_random_vector(size);

        // Medir tempo do Bubble Sort
        double bubble_time = measure_sort_time(original_vec, size, merge_sort);

        cout << size << "\t" << bubble_time << "ms\t" << "ms\n";
    }

    return 0;
}
