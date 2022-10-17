#ifndef AVL_HPP 
#define AVL_HPP

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct AVL_Record AVL_Record;
typedef struct AVL_Tree AVL_Tree;

struct AVL_Record{
	double key;
};

struct AVL_Tree{
	AVL_Record reg;
	AVL_Tree *left, *right;
	int weight;
};

AVL_Tree* AVL_CreateTree();
void AVL_insert(AVL_Tree **t, AVL_Record r);
void AVL_pesquisa(AVL_Tree **t, AVL_Tree **aux, AVL_Record r);
int AVL_isInTree(AVL_Tree *t, AVL_Record r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void AVL_remove(AVL_Tree **t, AVL_Tree **f, AVL_Record r);
void AVL_antecessor(AVL_Tree **t, AVL_Tree *aux);
void AVL_rebalanceTree(AVL_Tree **t);

void AVL_preordem(AVL_Tree *t);
void AVL_central(AVL_Tree *t);
void AVL_posordem(AVL_Tree *t);


int AVL_getWeight(AVL_Tree **t);
int AVL_getMaxWeight(int left, int right);


void rotacaoSimplesDireita(AVL_Tree **t);
void rotacaoSimplesEsquerda(AVL_Tree **t);
void rotacaoDuplaDireita(AVL_Tree **t);
void rotacaoDuplaEsquerda(AVL_Tree **t);


#endif
