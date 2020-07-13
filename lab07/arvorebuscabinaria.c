#include "arvorebuscabinaria.h"
#include <stdlib.h>

// Auxiliares: -----------------------------------------------------------------
int min(p_no root) {
  if (root == NULL)
    return POSITIVE_INFINITY;
  else
    return root->esq != NULL ? min(root->esq) : root->value;
}

int max(p_no root) {
  if (root == NULL)
    return NEGATIVE_INFINITY;
  else
    return root->dir != NULL ? max(root->dir) : root->value;
}

int sum(p_no root) {
  if (root == NULL)
    return 0;
  return root->soma = sum(root->esq) + root->value + sum(root->dir);
}

int max_sum_bst(p_no raiz) {
  int maxe, maxd;
  if (raiz == NULL)
    return NEGATIVE_INFINITY;
  else if (raiz->is_bst)
    return raiz->soma;

  maxe = max_sum_bst(raiz->esq);
  maxd = max_sum_bst(raiz->dir);
  return maxe > maxd ? maxe : maxd;
}

// Principais: -----------------------------------------------------------------
p_no create_node(int chave) {
  if (chave == -1)
    return NULL;

  p_no ret = (p_no)malloc(sizeof(no));
  ret->esq = ret->dir = NULL;
  ret->value = ret->soma = chave;
  ret->is_bst = False;
  return ret;
}

void find_maxBST(p_no raiz, int *max_bst) {
  sum(raiz);
  is_bst_root(raiz);
  *max_bst = max_sum_bst(raiz);
}

void update_maxBST(p_no node, int *max) {
  int sum = node->soma;
  if (node->esq != NULL)
    sum += node->esq->soma;
  if (node->dir != NULL)
    sum += node->dir->soma;

  if (sum > *max)
    *max = sum;
}

t_bst is_bst_root(p_no root) {
  int mind, maxe;
  t_bst esq, dir;

  // Casos base:
  if (root == NULL)
    return BOTH; // Considero, por conveniencia, que nulo e uma BST
  else if (root->esq == NULL && root->dir == NULL) {
    root->is_bst = True;
    return LEAF;
  }

  // Preenche os descendentes de forma recursiva:
  esq = is_bst_root(root->esq);
  dir = is_bst_root(root->dir);

  // Para ser BST os dois filhos tambem sao:
  if (dir == NONE || esq == NONE)
    return NONE;

  // Checa a propriedade de BST para o no atual:
  maxe = max(root->esq);
  if (maxe >= root->value)
    return NONE;
  mind = min(root->dir);
  if (mind <= root->value)
    return NONE;

  // Distingue o tipo de BST:
  root->is_bst = True;
  if (root->esq == NULL)
    return ONLY_RIGHT;
  else if (root->dir == NULL)
    return ONLY_LEFT;
  else
    return BOTH;
}

void destroy_binaryTree(p_no raiz) {
  if (raiz != NULL) {
    destroy_binaryTree(raiz->esq);
    destroy_binaryTree(raiz->dir);
    free(raiz);
  }
}