#include "btree.hpp"

BTree_Tree* BTree_CreateTree(){
  return NULL;
}

bool BTree_TVazia(BTree_Tree **t){
  return *t == NULL;
}

void BTree_insert(BTree_Tree **t, BTree_Record r){

  if(BTree_TVazia(t)){
    *t = (BTree_Tree*)malloc(sizeof(BTree_Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      BTree_insert(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      BTree_insert(&(*t)->dir, r);
    }
  
  }

}

void BTree_pesquisa(BTree_Tree **t, BTree_Tree **aux, BTree_Record r){

  if(*t == NULL){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ BTree_pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ BTree_pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}


int BTree_isInTree(BTree_Tree *t, BTree_Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || BTree_isInTree(t->esq, r) || BTree_isInTree(t->dir, r);
}


void BTree_antecessor(BTree_Tree **t, BTree_Tree *aux){ 

	if ((*t)->dir != NULL){ 
		BTree_antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void BTree_remove(BTree_Tree **t, BTree_Record r){
	BTree_Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: BTree_Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ BTree_remove(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ BTree_remove(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ BTree_antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}


void BTree_preordem(BTree_Tree *t)
{
  if(!(t == NULL)){
    printf("%lf ", t->reg.key);
    BTree_preordem(t->esq); 
    BTree_preordem(t->dir); 
  }
}


void BTree_central(BTree_Tree *t)
{
  if(!(t == NULL)){
    BTree_central(t->esq); 
    printf("%lf ", t->reg.key);
    BTree_central(t->dir); 
  }
}

void BTree_posordem(BTree_Tree *t)
{
  if(!(t == NULL)){
    BTree_posordem(t->esq); 
    BTree_posordem(t->dir); 
    printf("%lf ", t->reg.key);
  }
}
