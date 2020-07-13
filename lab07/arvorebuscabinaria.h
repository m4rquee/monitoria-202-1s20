/**
   arvorebuscabinaria.h

   @author Elisa Dell'Arriva
   @version 1.0 6/22/20
    
   @desc Biblioteca auxiliar na implementação da Tarefa de programação 07, da disciplina Estrutura de Dados (MC202) oferecida em 2s/2020.
*/

#ifndef ARVOREBUSCABINARIA_H_INCLUDED
#define ARVOREBUSCABINARIA_H_INCLUDED

/*********************
 * Macros
 *********************/
#define N_MAX_NODES 4000
#define NULL_NODE -1
#define NODE_VALUE_LB 0
#define NODE_VALUE_UB 999999
#define POSITIVE_INFINITY (NODE_VALUE_UB + 1)
#define NEGATIVE_INFINITY (NODE_VALUE_LB - 1)

/*********************
 * Tipos e estruturas
 *********************/

/* t_bst
 * Diz se um nó de árvore é raiz de uma árovore de busca binária.
 *
 * NONE: não é raiz de abb;
 * LEAF: é uma folha;
 * ONLY_LEFT: é raiz de abb, subárvore à direita é vazia e subárvore à esquerda é não vazia;
 * ONLY_RIGHT: é raiz de abb, subárove à esquerda é vazia e subárvore à direita é não vazia;
 * ONLY_LEFT: é raiz de abb e ambas subároves são não vazias;
 */
typedef enum{BOTH=0, ONLY_LEFT, ONLY_RIGHT, LEAF, NONE} t_bst;

/* bool
 * Definição do tipo booleano
 */
typedef enum{False=0, True = 1} bool;

/* no
 * Estrutura que representa um nó da árvore
 * 
 * esq, dir: apontadores para filhos à esquerda e à direita do nó, respectivamente;
 * value: valor numérico associado ao nó (chave do nó);
 * soma: caso o nó seja raiz de uma bst, soma dos valores de todos os nós que a compõem;
 * is_bst: indicador se nó é raiz de uma bst (True) ou não (False).
 */
typedef struct no {
  //  struct no *pai = NULL; // TODO
  struct no *esq;
  struct no *dir;
  int value, soma;
  bool is_bst;
}no, *p_no;

/***************
 * Funções 
 ***************/

/* create_node
 * Cria e inicializa um novo nó da árvore de busca binária
 *
 * chave  valor do nó a ser criado
 */
p_no create_node(int chave);

/* find_maxBST
 * Encontra uma subárvore de busca binária com soma máxima
 *
 * raiz     apontador para a árvore binária
 * max_bst  guarda a soma da subárvore de busca binária encontrada
 */
void find_maxBST(p_no raiz, int *max_bst);

/* update_maxBST
 * Atualiza, se for o caso, a soma da subárvore de busca binária máxima
 *
 * node apontador para uma subárvore de busca binária
 * max  soma da atual subárvore de busca binária máxima
 */
void update_maxBST(p_no node, int *max);

/* is_bst_root
 * Determina se o nó <root> é raiz de uma subárove de busca binária.
 * Se não, devolve NONE; caso contrário, devolve o tipo da subárvore, sendo:
 * LEAF: a subárove é uma folha;
 * ONLY_LEFT: a subárove não tem filhos à direita;
 * ONLY_RIGHT: a subárove não tem filhos à esquerda;
 * BOTH: a subárove tem filhos à direita e à esquerda; // TODO
 *
 * root apontador para uma subárvore possivelmente de busca
 */
t_bst is_bst_root(p_no root);

/* destroy_binaryTree
 * Libera memória alocada para uma árvore binária.
 *
 * raiz apontador para raiz da árvore que deve ser destruída.
 */
void destroy_binaryTree(p_no raiz);


#endif // ARVOREBUSCABINARIA_H_INCLUDED
