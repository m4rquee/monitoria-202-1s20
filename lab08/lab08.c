#include "arvrn.h"
#include <stdlib.h>

#define tostr(cor) (cor == PRETO ? "PRETO" : "VERMELHO")
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int arv_ceil(p_no raiz, int k) {
    if (raiz == NULL)
        return -1;
    else if (k == raiz->chave)
        return k;
    if (k > raiz->chave)
        return arv_ceil(raiz->dir, k);
    int aux = arv_ceil(raiz->esq, k);
    return aux == -1 ? raiz->chave : min(aux, raiz->chave);
}

int arv_floor(p_no raiz, int k) {
    if (raiz == NULL)
        return -1;
    else if (k == raiz->chave)
        return k;
    if (k < raiz->chave)
        return arv_floor(raiz->esq, k);
    return max(arv_floor(raiz->dir, k), raiz->chave);
}

int alt_negra_no(p_no raiz) {
    if (raiz == NULL) return 0;
    return raiz->cor + alt_negra_no(raiz->dir);// So precisa olhar um dos lados (propriedade 5)
}

void imprime_info(p_no raiz, int prf_negra) {
    if (raiz != NULL) {
        int alt_negra = alt_negra_no(raiz);
        printf("valor = %d ; cor = %s ; altura negra = %d; profundidade negra = %d;\n",
               raiz->chave, tostr(raiz->cor), alt_negra, prf_negra);
        imprime_info(raiz->esq, prf_negra + raiz->cor);
        imprime_info(raiz->dir, prf_negra + raiz->cor);
    }
}

p_no cria_arvore(int *vet, int tam) {
    int i;
    p_no ret = NULL;
    for (i = 0; i < tam; i++)
        ret = inserir(ret, vet[i]);
    return ret;
}

int *le_int_vet(int tam) {
    int i;
    int *ret = malloc(tam * sizeof(int));
    for (i = 0; i < tam; i++)
        scanf("%d", &ret[i]);
    return ret;
}

int main() {
    p_no avr;
    int tam, *vet, k;

    // Leitura:
    scanf("%d", &tam);
    vet = le_int_vet(tam);
    scanf("%d", &k);

    // Cria a arvore:
    avr = cria_arvore(vet, tam);
    free(vet);

    // Alturas e Profundidades:
    imprime_info(avr, 0);

    // Ceil e Floor:
    printf("teto de %d = %d \n", k, arv_ceil(avr, k));
    printf("piso de %d = %d \n", k, arv_floor(avr, k));

    destroi_arvore(avr);
    return 0;
}
