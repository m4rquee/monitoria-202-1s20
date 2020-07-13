#include "arvorebin.h"
#include <stdio.h>
#include <stdlib.h>

int vet_pos(int *vet, int tam, int v) {
  int i;
  for (i = 0; i < tam; i++)
    if (vet[i] == v)
      return i;
  return -1;
}

p_no cria_arv(int *pre, int *in, int ini, int tam) {
  if (tam <= 0)
    return NULL;

  int n_val = pre[ini];
  p_no n_no = cria_no(n_val);
  int pos = vet_pos(in, tam, n_val);

  n_no->esq = cria_arv(pre, in, ++ini, pos);
  n_no->dir = cria_arv(pre, &in[pos + 1], ini + pos, tam - pos - 1);

  return n_no;
}

int *le_int_vet(int tam) {
  int i;
  int *ret = (int *)malloc(tam * sizeof(int));
  for (i = 0; i < tam; i++)
    scanf("%d", &ret[i]);
  return ret;
}

int main() {
  int tam;
  int *pre;
  int *in;

  // Leitura:
  scanf("%d", &tam);
  pre = le_int_vet(tam);
  in = le_int_vet(tam);

  // Cria a arvore e printa em pos ordem:
  p_no arvore = cria_arv(pre, in, 0, tam);
  pos_ordem(arvore);

  libera_arvore(arvore);
  free(pre);
  free(in);
  return 0;
}
