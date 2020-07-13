#include "arvorebin.h"
#include <stdio.h>
#include <stdlib.h>

p_no cria_no(int valor) {
  p_no ret = (p_no)malloc(sizeof(No));
  ret->esq = ret->dir = NULL;
  ret->valor = valor;
  return ret;
}

void pos_ordem_rec(p_no no_atual) {
  if (no_atual != NULL) {
    pos_ordem_rec(no_atual->esq);
    pos_ordem_rec(no_atual->dir);
    printf("%d ", no_atual->valor);
  }
}

void pos_ordem(p_no no_atual) {
  pos_ordem_rec(no_atual);
  printf("\n");
}

void libera_arvore(p_no no_atual) {
  if (no_atual != NULL) {
    libera_arvore(no_atual->esq);
    libera_arvore(no_atual->dir);
    free(no_atual);
  }
}
