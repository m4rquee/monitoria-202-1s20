#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

no_lista *cria_no_lista(p_no arvore) {
  no_lista *ret =
      calloc(1, sizeof(no_lista)); /* Inicia todos os valores com 0 */
  ret->arvore = arvore;
  return ret;
}

floresta cria_floresta() {
  floresta ret;
  ret.comeco = ret.fim = NULL;
  return ret;
}

void enfileira(floresta *p_floresta, p_no arvore) {
  no_lista *p_novo = cria_no_lista(arvore);
  if (p_floresta->comeco == NULL) /* Lista vazia */
    p_floresta->comeco = p_novo;
  else
    p_floresta->fim->proximo = p_novo;

  p_floresta->fim = p_novo;
}

p_no desenfileira(floresta *p_floresta) {
  no_lista *primeiro = p_floresta->comeco;
  p_no ret = primeiro->arvore;
  p_floresta->comeco = p_floresta->comeco->proximo;

  if (p_floresta->comeco == NULL) /* Ao remover o ultimo no */
    p_floresta->fim = NULL;

  free(primeiro);
  return ret;
}

char esta_vazia(floresta floresta) { return floresta.comeco == NULL; }

void limpa_lista(no_lista *lista) {
  if (lista != NULL) {
    limpa_lista(lista->proximo);
    free(lista);
  }
}

void limpa_floresta(floresta *p_floresta) {
  limpa_lista(p_floresta->comeco);
  p_floresta->comeco = p_floresta->fim = NULL;
}
