#ifndef BTREE_H 
#define BTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BTree_Record BTree_Record;
typedef struct BTree_Tree BTree_Tree;

struct BTree_Record{
	double key;
};

struct BTree_Tree{
	BTree_Record reg;
	BTree_Tree *esq, *dir;
};

BTree_Tree* BTree_CreateTree();
bool BTree_TVazia(BTree_Tree **t);
void BTree_insert(BTree_Tree **t, BTree_Record r);
void BTree_pesquisa(BTree_Tree **t, BTree_Tree **aux, BTree_Record r);
int BTree_isInTree(BTree_Tree *t, BTree_Record r);

void BTree_remove(BTree_Tree **t, BTree_Record r);
void BTree_antecessor(BTree_Tree **t, BTree_Tree *aux);

void BTree_preordem(BTree_Tree *t);
void BTree_central(BTree_Tree *t);
void BTree_posordem(BTree_Tree *t);

#endif
