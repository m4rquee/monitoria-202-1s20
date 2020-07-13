#include "arvorebuscabinaria.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

p_no cria_arvore(int *vet, int tam) {
  int i = 0;
  if (tam == 0)
    return NULL;

  floresta fila = cria_floresta();
  p_no raiz = create_node(vet[i]);
  enfileira(&fila, raiz);
  while (!esta_vazia(fila) && i < tam) {
    p_no aux, frente = desenfileira(&fila);

    aux = ++i < tam ? create_node(vet[i]) : NULL;
    if (aux != NULL)
      enfileira(&fila, frente->esq = aux);

    aux = ++i < tam ? create_node(vet[i]) : NULL;
    if (aux != NULL)
      enfileira(&fila, frente->dir = aux);
  }

  limpa_floresta(&fila);
  return raiz;
}

int *le_int_vet(int tam) {
  int i;
  int *ret = (int *)malloc(tam * sizeof(int));
  for (i = 0; i < tam; i++)
    scanf("%d", &ret[i]);
  return ret;
}

int main() {
  int tam, max;
  int *vet;
  p_no arvore;

  // Leitura:
  scanf("%d", &tam);
  vet = le_int_vet(tam);

  // Cria a arvore e printa o valor:
  arvore = cria_arvore(vet, tam);
  find_maxBST(arvore, &max);
  printf("%d", max);

  destroy_binaryTree(arvore);
  free(vet);
  return 0;
}