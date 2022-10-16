#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "./trees/btree/btree.hpp"
#include<bits/stdc++.h>

#define MIN_VALUE 00000.00000
#define MAX_VALUE 99999.99999
#define PRECISION 5 
#define SIZE_FILE1 500
#define SIZE_FILE2 5000
#define SIZE_FILE3 50000
#define SIZE_FILE4 500000
using namespace std;

void GeneratorNumbers(const int size, string name_arq);

void InsertNumbersInBTree(BTree_Tree **root, string name_arq);



#endif