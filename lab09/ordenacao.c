#include "ordenacao.h"

#define TROCA(a, b)                                                            \
  int c = a;                                                                   \
  a = b;                                                                       \
  b = c
#define SOMA(x, k) *(x) += k
#define INC(x) SOMA(x, 1)

void desce_no_heap(int v[MAX], int n, int k, int *contador) {
  int maior_filho;
  if (F_ESQ(k) < n) {
    maior_filho = F_ESQ(k);
    if (F_DIR(k) < n && v[F_ESQ(k)] < v[F_DIR(k)])
      maior_filho = F_DIR(k);
    SOMA(contador, 2);

    if (v[k] < v[maior_filho]) {
      TROCA(v[k], v[maior_filho]);
      desce_no_heap(v, n, maior_filho, contador);
    }
    INC(contador);
  }
  INC(contador);
}

void heapsort(int v[MAX], int n, int *contador) {
  int k;
  for (k = n / 2; k >= 0; k--) {
    INC(contador);
    desce_no_heap(v, n, k, contador);
  }
  INC(contador);

  while (n > 1) {
    TROCA(v[0], v[n - 1]);
    n--;
    desce_no_heap(v, n, 0, contador);
    INC(contador);
  }
  INC(contador);
}

void merge(int v[MAX], int l, int m, int r, int *contador) {
  int aux[MAX];
  int i = l, j = m + 1, k = 0;

  while (i <= m && j <= r) {
    if (v[i] <= v[j])
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
    SOMA(contador, 3);
  }
  while (i <= m) {
    aux[k++] = v[i++];
    INC(contador);
  }
  while (j <= r) {
    aux[k++] = v[j++];
    INC(contador);
  }
  SOMA(contador, 4); // Whiles

  for (i = l, k = 0; i <= r; i++, k++) {
    v[i] = aux[k];
    INC(contador);
  }
  INC(contador);
}

void mergesort(int v[MAX], int l, int r, int *contador) {
  int m = (l + r) / 2;
  if (l < r) {
    mergesort(v, l, m, contador);
    mergesort(v, m + 1, r, contador);
    merge(v, l, m, r, contador);
  }
  INC(contador);
}

int particao(int v[MAX], int l, int r, int *contador) {
  int i, pivo = v[l], pos = r + 1;
  for (i = r; i >= l; i--) {
    if (v[i] >= pivo) {
      pos--;
      TROCA(v[i], v[pos]);
    }
    SOMA(contador, 2);
  }
  INC(contador);
  return pos;
}

void quicksort(int v[MAX], int l, int r, int *contador) {
  INC(contador);
  if (r <= l)
    return;
  int i = particao(v, l, r, contador);
  quicksort(v, l, i - 1, contador);
  quicksort(v, i + 1, r, contador);
}
