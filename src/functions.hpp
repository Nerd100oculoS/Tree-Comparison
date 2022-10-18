#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "./trees/btree/btree.hpp"
#include "./trees/avl/avl.hpp"
#include "./trees/rbtree/rbtree.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <ratio>
#include <ctime>
#include <algorithm>
#include <vector>

#define MIN_VALUE 00000.00000
#define MAX_VALUE 99999.99999
#define PRECISION 5 
#define SIZE_FILE1 500
#define SIZE_FILE2 5000
#define SIZE_FILE3 50000
#define SIZE_FILE4 500000

using namespace std;
using namespace std::chrono;

void GeneratorNumbers(const int size, string name_arq);

void InsertNumbersInBTree(BTree_Tree **root, string name_arq);
void SearchAndRemoveNumbersInBTree(BTree_Tree **root);
void MakeBinaryTree();

void InsertNumbersInAVL(AVL_Tree **root, string name_arq);
void SearchAndRemoveNumbersInAVL(AVL_Tree **root);
void MakeAVLTree();

void InsertNumbersInRB(rb_tree<double> *root, string name_arq);
void SearchAndRemoveNumbersInRB(rb_tree<double> *root);
void MakeRBTree();


void InsertAndOrdenateNumbersInVector(vector<double> &vec, string name_arq);
void SearchBinaryInVector(const vector<double> vec);
template<typename T>
int binarySearch(const vector<T> &vec, T &item, int s1, int s2);
template<typename T>
int searchVector(const vector<T> &vec, T &item);

#endif