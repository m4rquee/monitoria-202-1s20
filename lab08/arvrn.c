#include "arvrn.h"
#include <stdlib.h>

p_no cria_no(int chave) {
    p_no ret = malloc(sizeof(No));
    ret->esq = ret->dir = NULL;
    ret->chave = chave;
    ret->cor = VERMELHO;
    return ret;
}

p_no corrige_arvrn(p_no raiz) {
    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
        raiz = rotaciona_para_esquerda(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
        raiz = rotaciona_para_direita(raiz);
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
        sobe_vermelho(raiz);
    return raiz;
}

p_no inserir(p_no raiz, int chave) {
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}

p_no inserir_rec(p_no raiz, int chave) {
    if (raiz == NULL)
        return cria_no(chave);
    if (chave < raiz->chave)
        raiz->esq = inserir_rec(raiz->esq, chave);
    else
        raiz->dir = inserir_rec(raiz->dir, chave);
    return corrige_arvrn(raiz);
}

void sobe_vermelho(p_no raiz) {
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

p_no rotaciona_para_direita(p_no raiz) {
    p_no aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return aux;
}

p_no rotaciona_para_esquerda(p_no raiz) {
    p_no aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    aux->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return aux;
}

int ehPreto(p_no x) {
    return x == NULL || x->cor == PRETO;
}

int ehVermelho(p_no x) {
    return x != NULL && x->cor == VERMELHO;
}

void destroi_arvore(p_no raiz) {
    if (raiz != NULL) {
        destroi_arvore(raiz->esq);
        destroi_arvore(raiz->dir);
        free(raiz);
    }
}
