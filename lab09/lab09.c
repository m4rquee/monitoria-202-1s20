#include "ordenacao.h"
#include <stdio.h>
#include <string.h>

void le_int_vet(int vet[MAX], int tam) {
  int i;
  for (i = 0; i < tam; i++)
    scanf("%d", &vet[i]);
}

int main() {
  int tam, contadorHeap, contadorMerge, contadorQuick;
  int vetorHeap[MAX], vetorMerge[MAX], vetorQuick[MAX];
  contadorHeap = contadorMerge = contadorQuick = 0;

  // Leitura:
  scanf("%d", &tam);
  le_int_vet(vetorHeap, tam);

  // Faz as copias:
  memcpy(vetorMerge, vetorHeap, tam * sizeof(int));
  memcpy(vetorQuick, vetorHeap, tam * sizeof(int));

  // Chama as funcoes de ordenacao:
  heapsort(vetorHeap, tam, &contadorHeap);
  mergesort(vetorMerge, 0, tam - 1, &contadorMerge);
  quicksort(vetorQuick, 0, tam - 1, &contadorQuick);

  // Avalia o resultado:
  avalia_ordenacao(vetorHeap, vetorMerge, vetorQuick, contadorHeap,
                   contadorMerge, contadorQuick, tam);

  return 0;
}