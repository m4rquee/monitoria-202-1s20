#ifndef MC202_FILA_H
#define MC202_FILA_H

#include "arvorebuscabinaria.h"

typedef struct no_lista {
  p_no arvore;
  struct no_lista *proximo;
} no_lista;

typedef struct fila {
  no_lista *comeco;
  no_lista *fim;
} floresta;

floresta cria_floresta(); /* Cria uma fila vazia */

void enfileira(floresta *p_floresta, p_no arvore);

p_no desenfileira(floresta *p_floresta);

char esta_vazia(floresta floresta);

void limpa_floresta(floresta *p_floresta);

#endif
