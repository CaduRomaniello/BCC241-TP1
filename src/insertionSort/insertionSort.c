#include "insertionSort.h"

void insertionSort(int* vet, int n) {
    int aux;
    int i, j;

    for (i = 1; i < n; i++) {             // Custo 2 (Por iteração)
        aux = vet[i];                     // Custo 1
        j = i - 1;                        // Custo 1
        while (j >= 0 && aux < vet[j]) {  // Custo 3
            vet[j + 1] = vet[j];          // Custo 1
            j--;                          // Custo 1
        }
        vet[j + 1] = aux;  // Custo 1
    }
}

/**
 * Análise da função insertionSort
 *
 * - Loop externo (for) executa um total de n vezes -> 2n operações
 * - Linhas 8,9,14 totalizam 3(n-1) operações
 * - loop interno (while) execute um total Ti + 1 vezes, onde Ti é a execução
 * das linhas 11~12
 * - Sendo assim, o bloco 10~13 tem uma complexidade (3 * ⅀(Ti+1) variando de i
 * = 1 até n-1) + (2 * ⅀Ti variando de i = 1 até n-1)
 *
 * Sendo assim temos que a função de complexidade da função insertionSort é:
 * - T(n) = 5n - 3 + 5 * ⅀Ti + 3 * ⅀1 variando de i = 1 até n-1
 * - T(n) = 8n - 6 + 5 * ⅀Ti variando de i = 1 até n-1
 *
 * - Melhor caso -> Ti = 0
 * - T(n) = 8n - 6 -> O(n)
 *
 * - Pior caso -> Ti = i-1
 * - T(n) = 8n - 6 + 5 * ⅀i variando de i = 0 até n-2
 * - T(n) = 8n - 6 + 5 * (0 + (n-2)) * (n-1) /2
 * - T(n) = 8n - 6 + 5 * (n^2 - 3n + 2) / 2
 * - T(n) = (5n^2 + n - 2) / 2 -> O(n^2)
 *
 * - Caso médio -> Ti = 1/i + ⅀j variando de j = 0 até i-1
 * - Ti = (i - 1) / 2
 * - T(n) = 8n - 6 + 5 * ⅀i/2 variando de i = 0 até n-2
 * - T(n) = 8n - 6 + 5/2 * ⅀i variando de i = 0 até n-2
 * - T(n) = 8n - 6 + 5/2 * (0 + (n-2)) * (n-1) /2
 * - T(n) = 8n - 6 + 5/2 * (n^2 - 3n + 2) / 2
 * - T(n) = (5n^2 + 17n - 14) / 4 -> O(n^2)
 *
 * - Ordem de complexidade:
 * - Pior caso -> O(n^2)
 * - Caso médio -> O(n^2)
 * - Melhor médio -> O(n)
 */