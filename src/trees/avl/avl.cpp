#include "avl.hpp"

AVL_Tree* AVL_CreateTree(){
	return NULL;
}

void AVL_insert(AVL_Tree **t, AVL_Record r){

  if(*t == NULL){
    *t = (AVL_Tree*)malloc(sizeof(AVL_Tree));
    (*t)->left   = NULL; 
    (*t)->right  = NULL; 
    (*t)->weight = 0;
    (*t)->reg = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      AVL_insert(&(*t)->left, r);
      if ((AVL_getWeight(&(*t)->left) - AVL_getWeight(&(*t)->right)) == 2){
      	if(r.key < (*t)->left->reg.key)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      AVL_insert(&(*t)->right, r);
      if ((AVL_getWeight(&(*t)->right) - AVL_getWeight(&(*t)->left)) == 2){
      	if(r.key > (*t)->right->reg.key)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = AVL_getMaxWeight(AVL_getWeight(&(*t)->left), AVL_getWeight(&(*t)->right)) + 1;
}


void AVL_pesquisa(AVL_Tree **t, AVL_Tree **aux, AVL_Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ AVL_pesquisa(&(*t)->left, aux, r); return;}
	if((*t)->reg.key < r.key){ AVL_pesquisa(&(*t)->right, aux, r); return;}

	*aux = *t;
}

int AVL_isInTree(AVL_Tree *t, AVL_Record r){
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || AVL_isInTree(t->left, r) || AVL_isInTree(t->right, r);
}


void AVL_antecessor(AVL_Tree **t, AVL_Tree *aux){ 

	if ((*t)->right != NULL){ 
		AVL_antecessor(&(*t)->right, aux);
		return;
  	}
  	
  	aux->reg = (*t)->reg;
  	aux = *t; 
  	*t = (*t)->left;
  	free(aux);
} 

void AVL_rebalanceTree(AVL_Tree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = AVL_getWeight(&(*t)->left) - AVL_getWeight(&(*t)->right);
	if((*t)->left)
		left = AVL_getWeight(&(*t)->left->left) - AVL_getWeight(&(*t)->left->right);
	if((*t)->right)
		right = AVL_getWeight(&(*t)->right->left) - AVL_getWeight(&(*t)->right->right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if(balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t); 	

}

void AVL_remove(AVL_Tree **t, AVL_Tree **f, AVL_Record r){
	AVL_Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: AVL_Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ AVL_remove(&(*t)->left, t, r); return;}
  	if (r.key > (*t)->reg.key){ AVL_remove(&(*t)->right, t, r); return;}

  	if ((*t)->right == NULL){ 
  		aux = *t;  
  		*t = (*t)->left;
    	free(aux);
    	AVL_rebalanceTree(f);
    	return;
  	}

  	if ((*t)->left != NULL){ 
  		AVL_antecessor(&(*t)->left, *t);
  		AVL_rebalanceTree(t);
  		AVL_rebalanceTree(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->right;
  	free(aux);
  	AVL_rebalanceTree(t);
  	AVL_rebalanceTree(f); 	
  	
}

void AVL_preordem(AVL_Tree *t)
{
  if(!(t == NULL)){
    printf("%lf:%d\t", t->reg.key, t->weight);
    AVL_preordem(t->left); 
    AVL_preordem(t->right); 
  }
}


void AVL_central(AVL_Tree *t)
{
  if(!(t == NULL)){
    AVL_central(t->left); 
    printf("%lf\t", t->reg.key);
    AVL_central(t->right); 
  }
}

void AVL_posordem(AVL_Tree *t)
{
  if(!(t == NULL)){
    AVL_posordem(t->left); 
    AVL_posordem(t->right); 
    printf("%lf\t", t->reg.key);
  }
}


int AVL_getWeight(AVL_Tree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int AVL_getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(AVL_Tree **t){
	AVL_Tree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = AVL_getMaxWeight(AVL_getWeight(&(*t)->left), AVL_getWeight(&(*t)->right)) + 1;
	aux->weight  = AVL_getMaxWeight(AVL_getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(AVL_Tree **t){
	AVL_Tree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = AVL_getMaxWeight(AVL_getWeight(&(*t)->left), AVL_getWeight(&(*t)->right)) + 1;
	aux->weight  = AVL_getMaxWeight(AVL_getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(AVL_Tree **t){
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(AVL_Tree **t){
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}













