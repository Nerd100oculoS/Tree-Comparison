#include "functions.hpp"

// -------------------------------------------------> Binary Tree:
/**
 * @brief Gerador de números
 * 
 * @param size Quantidade de n\u00fameros a serem gerados.
 * @param name_arq Nome do arquivo a ser criado.
 */
void GeneratorNumbers(const int size, string name_arq){
    
    //clock_t start, end;
    
    random_device rd;
    mt19937  ra(rd());

    string name_file = "./src/files/" + name_arq;
    ofstream file(name_file);

    cout << name_file << endl;
    uniform_real_distribution<> distribution(MIN_VALUE,MAX_VALUE);
    
    if(file.is_open()){
        
        //start = clock();
        for(int i = 0; i < size; i++){

            file << fixed << setprecision(PRECISION) << distribution(ra) << endl;

        }
        // end = clock();
        // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        // cout << "Tempo para gerar " << size << " n\u00fameros: " << fixed << time_taken << setprecision(5)
        //     << " segundos" << endl;

    }else{

        cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;
    }

    file.close();
}


/**
 * @brief Insere na Árvore Binária.
 * 
 * @param root Endereço do ponteiro da BTree (&root).
 */
void InsertNumbersInBTree(BTree_Tree **root, string name_arq){

    // Para calculo da media de tempo
    steady_clock::time_point start, end;
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    BTree_Record reg;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            reg.key = token_number;
            
            start = steady_clock::now();
            BTree_insert(root,reg);
            end = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end-start);

            soma += (double)time.count();

        }
        
        cout << "Tempo médio de inserção: " << 
         fixed <<  setprecision (10) << (double)(soma/cont) <<
        "s"  << endl;  
        
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

/**
 * @brief Cálculo de Tempo para pesquisa e remoção
 * 
 * @param root Endereço do ponteiro da BTree (&root).
 */
void SearchAndRemoveNumbersInBTree(BTree_Tree **root){

    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;
    
    int cont_s, cont_r;
    cont_s = cont_r = 0;

    double soma_search = 0.0;
    double soma_remove = 0.0;

    BTree_Record r; 
    BTree_Tree *aux = BTree_CreateTree();

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            r.key = token_number;
            
            start_s = steady_clock::now();
            BTree_pesquisa(root,&aux,r);
            end_s = steady_clock::now();
            cont_s++;

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(!(aux == NULL) && (*aux).reg.key == r.key){
                
                start_r = steady_clock::now();
                BTree_remove(root,aux->reg);
                end_r = steady_clock::now();
                cont_r++;

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo Médio de pesquisa: " << fixed << setprecision(10) <<
         (double)(soma_search/cont_s) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo Médio de remoção: " << fixed << setprecision(10) <<
         (double)(soma_remove/cont_r) << "s" << endl;
    
    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

/**
 * @brief Execução para o cálculo de tempo da Árvore Binária Simples.
 */
void MakeBinaryTree(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        BTree_Tree *root = BTree_CreateTree();

        InsertNumbersInBTree(&root,"File1.txt");
        SearchAndRemoveNumbersInBTree(&root);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        BTree_Tree *root = BTree_CreateTree();

        InsertNumbersInBTree(&root,"File2.txt");
        SearchAndRemoveNumbersInBTree(&root);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        BTree_Tree *root = BTree_CreateTree();

        InsertNumbersInBTree(&root,"File3.txt");
        SearchAndRemoveNumbersInBTree(&root);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        BTree_Tree *root = BTree_CreateTree();

        InsertNumbersInBTree(&root,"File4.txt");
        SearchAndRemoveNumbersInBTree(&root);
        cout << endl << endl;

    }

}

// -------------------------------------------------> AVL Tree:
/**
 * @brief Insere na Árvore Binária AVL.
 * 
 * @param root Endereço do ponteiro da AVL_Tree (&root).
 */
void InsertNumbersInAVL(AVL_Tree **root, string name_arq){

    // Para calculo da media de tempo
    steady_clock::time_point start, end;
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    AVL_Record reg;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            reg.key = token_number;
            
            start = steady_clock::now();
            AVL_insert(root,reg);
            end = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end-start);

            soma += (double)time.count();
        }
        
        cout << "Tempo médio de inserção: " << 
         fixed <<  setprecision (10) << (double)(soma/cont) <<
        "s"  << endl;  
        
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

/**
 * @brief Cálculo de Tempo para pesquisa e remoção
 * 
 * @param root Endereço do ponteiro da AVL_Tree (&root).
 */
void SearchAndRemoveNumbersInAVL(AVL_Tree **root){

    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;
    
    int cont_s, cont_r;
    cont_s = cont_r = 0;

    double soma_search = 0.0;
    double soma_remove = 0.0;

    AVL_Record r; 
    AVL_Tree *aux = AVL_CreateTree();

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            r.key = token_number;
            
            start_s = steady_clock::now();
            AVL_pesquisa(root,&aux,r);
            end_s = steady_clock::now();
            cont_s++;

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(!(aux == NULL) && (*aux).reg.key == r.key){
                
                start_r = steady_clock::now();
                AVL_remove(root, root, aux->reg);
                end_r = steady_clock::now();
                cont_r++;

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo Médio de pesquisa: " << fixed << setprecision(10) <<
         (double)(soma_search/cont_s) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo Médio de remoção: " << fixed << setprecision(10) <<
         (double)(soma_remove/cont_r) << "s" << endl;
    
    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

void MakeAVLTree(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        AVL_Tree *root = AVL_CreateTree();

        InsertNumbersInAVL(&root,"File1.txt");
        SearchAndRemoveNumbersInAVL(&root);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        AVL_Tree *root = AVL_CreateTree();

        InsertNumbersInAVL(&root,"File2.txt");
        SearchAndRemoveNumbersInAVL(&root);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        AVL_Tree *root = AVL_CreateTree();

        InsertNumbersInAVL(&root,"File3.txt");
        SearchAndRemoveNumbersInAVL(&root);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        AVL_Tree *root = AVL_CreateTree();

        InsertNumbersInAVL(&root,"File4.txt");
        SearchAndRemoveNumbersInAVL(&root);
        cout << endl << endl;

    }

}