#include "functions.hpp"

int main(){
    
    // GeneratorNumbers(SIZE_FILE1,"File1.txt");
    // GeneratorNumbers(SIZE_FILE2,"File2.txt");
    // GeneratorNumbers(SIZE_FILE3,"File3.txt");
    // GeneratorNumbers(SIZE_FILE4,"File4.txt");
    
    BTree_Tree *root = BTree_CreateTree();

    InsertNumbersInBTree(&root,"File4.txt");

    //BTree_posordem(root);

    SearchAndRemoveNumbersInBTree(&root);
    // InsertNumbersInBTree(&root,"File2.txt");
    // InsertNumbersInBTree(&root,"File3.txt");
    //InsertNumbersInBTree(&root,"File4.txt");

    return 0;
}