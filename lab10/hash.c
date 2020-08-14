#include "hash.h"
#include <string.h>

#define MODINC(i, m) (i = (i + 1) % (m))

void inicializa_hash(tabela_hash *h, int m) {
  int i;
  for (i = 0; i < m; i++)
    h[i] = VAZIO;
}

void inserir(tabela_hash h[], long long int k, int p, int a, int b, int m) {
  int start, i;
  start = i = func_hash(k, p, a, b, m);
  do
    if (h[i] == VAZIO || h[i] == DUMMY) {
      h[i] = k;
      return;
    }
  while (MODINC(i, m) != start);
}

void remover_rehash(tabela_hash h[], long long int k, int p, int a, int b,
                    int m) {
  tabela_hash aux[MAX_TABELA];
  int i = buscar(h, k, p, a, b, m), j;

  if (i == -1) // Nao esta na tabela
    return;

  h[i] = VAZIO;
  for (MODINC(i, m), j = 0; h[i] != VAZIO; MODINC(i, m), j++) {
    aux[j] = h[i];
    h[i] = VAZIO;
  }
  for (i = 0; i < j; i++)
    inserir(h, aux[i], p, a, b, m);
}

void remover_dummy(tabela_hash h[], long long int k, int p, int a, int b,
                   int m) {
  int start, i;
  start = i = buscar(h, k, p, a, b, m);
  if (i == -1) // Nao esta na tabela
    return;

  do
    if (h[i] == VAZIO)
      return;
    else if (h[i] == DUMMY) {
      MODINC(i, m);
    } else {
      h[i] = DUMMY; // "Remove" o valor encontrado
      return;
    }
  while (i != start);
}

long long int converte_chave_para_llint(char *chave) {
  int i;
  long long int ret = 0;
  for (i = 0; i < strlen(chave); i++)
    ret = 256 * ret + chave[i];
  return ret;
}

int func_hash(long long int k, int p, int a, int b, int m) {
  long long int aux = a * k + b;
  return (aux % p) % m;
}

int buscar(tabela_hash h[], long long int k, int p, int a, int b, int m) {
  int start, i;
  start = i = func_hash(k, p, a, b, m);
  do
    if (h[i] == VAZIO) // Tabela nao possui elemento com esse valor
      return -1;
    else if (h[i] == k) // Achou o valor
      return i;
  while (MODINC(i, m) != start);
  return -1; // Tabela cheia
}
