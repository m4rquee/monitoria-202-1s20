#include "hash.h"
#include <stdio.h>

int main() {
  int m, p, a, b;
  int num, i;
  long long int k;
  char aux[MAX_PALAVRA];
  tabela_hash rehash[MAX_TABELA], dummy[MAX_TABELA];
  scanf("%d %d %d %d", &m, &p, &a, &b);

  // Inicializa tabelas:
  inicializa_hash(rehash, m);
  inicializa_hash(dummy, m);

  // Le e incere os valores:
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    scanf("%s", aux);
    k = converte_chave_para_llint(aux);
    inserir(rehash, k, p, a, b, m);
    inserir(dummy, k, p, a, b, m);
  }

  // Remove os valores:
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    scanf("%s", aux);
    k = converte_chave_para_llint(aux);
    remover_rehash(rehash, k, p, a, b, m);
    remover_dummy(dummy, k, p, a, b, m);
  }

  // Imprime a saida:
  imprimir_saida(rehash, dummy, m);
  return 0;
}