#include "functions.hpp"

// -------------------------------------------------> Binary Tree:
/**
 * @brief Gerador de números
 * 
 * @param size Quantidade de n\u00fameros a serem gerados.
 * @param name_arq Nome do arquivo a ser criado.
 */
void GeneratorNumbers(const int size, string name_arq){
    
    random_device rd;
    mt19937  ra(rd());

    string name_file = "./src/files/" + name_arq;
    ofstream file(name_file);

    cout << name_file << endl;
    uniform_real_distribution<> distribution(MIN_VALUE,MAX_VALUE);
    
    if(file.is_open()){
        
        //start_s = clock();
        for(int i = 0; i < size; i++){

            file << fixed << setprecision(PRECISION) << distribution(ra) << endl;

        }

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
    steady_clock::time_point start_s, end_s;
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
            
            start_s = steady_clock::now();
            BTree_insert(root,reg);
            end_s = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end_s-start_s);

            soma += (double)time.count();

        }
        
        cout << "Tempo de inserção: " << 
         fixed <<  setprecision(6) << (double)(soma) <<
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
        

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(!(aux == NULL) && (*aux).reg.key == r.key){
                
                start_r = steady_clock::now();
                BTree_remove(root,aux->reg);
                end_r = steady_clock::now();
                

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo de pesquisa: " << fixed << setprecision(6) <<
         (double)(soma_search) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;
    
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
    steady_clock::time_point start_s, end_s;
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
            
            start_s = steady_clock::now();
            AVL_insert(root,reg);
            end_s = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end_s-start_s);

            soma += (double)time.count();
        }
        
        cout << "Tempo de inserção: " << 
         fixed <<  setprecision (6) << (double)(soma) <<
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
        

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(!(aux == NULL) && (*aux).reg.key == r.key){
                
                start_r = steady_clock::now();
                AVL_remove(root, root, aux->reg);
                end_r = steady_clock::now();
                

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo de pesquisa: " << fixed << setprecision(6) <<
         (double)(soma_search) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;
    
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

void InsertNumbersInRB(rb_tree<double> *root, string name_arq){

    // Para calculo da media de tempo
    steady_clock::time_point start_s, end_s;
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            root->insert(token_number);
            end_s = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end_s-start_s);

            soma += (double)time.count();
        }
        
        cout << "Tempo de inserção: " << 
         fixed <<  setprecision (6) << (double)(soma) <<
        "s"  << endl;  
        
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

void SearchAndRemoveNumbersInRB(rb_tree<double> *root){

    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;

    double soma_search = 0.0;
    double soma_remove = 0.0;

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            int i = root->search(token_number); //Apenas para retorno caso encontre.
            end_s = steady_clock::now();

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(i == 1){
                
                start_r = steady_clock::now();
                root->erase(token_number);
                end_r = steady_clock::now();

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo de pesquisa: " << fixed << setprecision(6) <<
         (double)(soma_search) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;
    
    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

void MakeRBTree(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        rb_tree<double> root;

        InsertNumbersInRB(&root,"File1.txt");
        SearchAndRemoveNumbersInRB(&root);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        rb_tree<double> root;

        InsertNumbersInRB(&root,"File2.txt");
        SearchAndRemoveNumbersInRB(&root);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        rb_tree<double> root;

        InsertNumbersInRB(&root,"File3.txt");
        SearchAndRemoveNumbersInRB(&root);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        rb_tree<double> root;

        InsertNumbersInRB(&root,"File4.txt");
        SearchAndRemoveNumbersInRB(&root);
        cout << endl << endl;

    }
}

void InsertAndOrdenateNumbersInVector(vector<double> &vec, string name_arq){

    // Para calculo da media de tempo
    steady_clock::time_point start_s, end_s, start_o, end_o; 
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            vec.push_back(token_number);
            cont++;

        }
        
        sort(vec.begin(), vec.end());
        end_s = steady_clock::now();

        auto time_s = duration_cast<duration<double>>(end_s-start_s);
        soma += (double)time_s.count();

        cout << "Tempo de inserção: " << 
         fixed <<  setprecision (6) << (double)(soma) <<
        "s"  << endl;  

    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

void SearchBinaryAndRemoveInVector(vector<double> &vec){

    steady_clock::time_point start_sb, end_sb;
    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;
    

    double soma_searchBinary = 0.0;
    double soma_search = 0.0;
    double soma_remove = 0.0;

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_sb = steady_clock::now();
            bool pesq_bina = binary_search(vec.begin(),vec.end(),token_number);
            end_sb = steady_clock::now();

            auto time_sb = duration_cast<duration<double>>(end_sb - start_sb);
            soma_searchBinary += (double)time_sb.count();

            vector<double>::iterator it;
            
            start_s = steady_clock::now();
            it = find(vec.begin(),vec.end(),token_number);
            end_s = steady_clock::now();

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(it != vec.end()){
                
                start_r = steady_clock::now();
                vec.erase(it);
                end_r = steady_clock::now();

                auto time_s = duration_cast<duration<double>>(end_s - start_s);
                soma_remove += (double)time_sb.count();
                
            }
        }


        cout << "Tempo de pesquisa binária: " << fixed << setprecision(6) <<
         (double)(soma_searchBinary) << "s" << endl;
        
        cout << "Tempo de pesquisa normal: " << fixed << setprecision(6) << 
        (double)(soma_search) << "s" << endl;
        
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;

    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

void MakeVector(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        vector<double> vec;

        InsertAndOrdenateNumbersInVector(vec, "File1.txt");
        SearchBinaryAndRemoveInVector(vec);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        vector<double> vec;

        InsertAndOrdenateNumbersInVector(vec, "File2.txt");
        SearchBinaryAndRemoveInVector(vec);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        vector<double> vec;

        InsertAndOrdenateNumbersInVector(vec, "File3.txt");
        SearchBinaryAndRemoveInVector(vec);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        vector<double> vec;

        InsertAndOrdenateNumbersInVector(vec, "File4.txt");
        SearchBinaryAndRemoveInVector(vec);
        cout << endl << endl;
    }
}

void InsertInUnorderedMap(unordered_map<double, int> *umap, string name_arq){

    steady_clock::time_point start_s, end_s;
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            if(umap->find(token_number) != umap->end()){

                (*umap)[token_number]++;
            
            }else{

                umap->insert({token_number,0});

            }
            end_s = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end_s-start_s);

            soma += (double)time.count();
        }
        
        cout << "Tempo de inserção: " << 
         fixed <<  setprecision (6) << (double)(soma) <<
        "s"  << endl;  
        
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

void SearchAndRemoveUnorderedMap(unordered_map<double, int> *umap){

    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;
    
    int cont_s, cont_r, i = 0;
    cont_s = cont_r = 0;

    double soma_search = 0.0;
    double soma_remove = 0.0;

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            if(umap->find(token_number) != umap->end()){
                i = 1;
            }else{
                i = 0;
            }
            end_s = steady_clock::now();
        

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(i == 1){
                
                start_r = steady_clock::now();
                umap->erase(token_number);
                end_r = steady_clock::now();
                
                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo de pesquisa: " << fixed << setprecision(6) <<
         (double)(soma_search) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;
    
    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

void MakeUnorderedMap(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        unordered_map<double,int> umap;
        InsertInUnorderedMap(&umap, "File1.txt");
        SearchAndRemoveUnorderedMap(&umap);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        unordered_map<double,int> umap;
        InsertInUnorderedMap(&umap, "File2.txt");
        SearchAndRemoveUnorderedMap(&umap);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        unordered_map<double,int> umap;
        InsertInUnorderedMap(&umap, "File3.txt");
        SearchAndRemoveUnorderedMap(&umap);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        unordered_map<double,int> umap;
        InsertInUnorderedMap(&umap, "File4.txt");
        SearchAndRemoveUnorderedMap(&umap);
        cout << endl << endl;
    }
}

void InsertInMap(map<double, int> *mmap, string name_arq){

    steady_clock::time_point start_s, end_s;
    double soma = 0.0;
    int cont = 0;

    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            if(mmap->find(token_number) != mmap->end()){

                (*mmap)[token_number]++;
            
            }else{

                mmap->insert({token_number,0});

            }
            end_s = steady_clock::now();
            cont++;

            auto time = duration_cast<duration<double>>(end_s-start_s);

            soma += (double)time.count();
        }
        
        cout << "Tempo de inserção: " << 
         fixed <<  setprecision (6) << (double)(soma) <<
        "s"  << endl;  
        
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}
void SearchAndRemoveMap(map<double, int> *mmap){

    steady_clock::time_point start_s, end_s;
    steady_clock::time_point start_r, end_r;
    
    int cont_s, cont_r, i = 0;
    cont_s = cont_r = 0;

    double soma_search = 0.0;
    double soma_remove = 0.0;

    ifstream file("./src/files/search.txt");

    string token_string;
    double token_number;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            
            start_s = steady_clock::now();
            if(mmap->find(token_number) != mmap->end()){
                i = 1;
            }else{
                i = 0;
            }
            end_s = steady_clock::now();
        

            auto time_s = duration_cast<duration<double>>(end_s - start_s);
            soma_search += (double)time_s.count();

            if(i == 1){
                
                start_r = steady_clock::now();
                mmap->erase(token_number);
                end_r = steady_clock::now();
                

                auto time_r = duration_cast<duration<double>>(end_r - start_r);
                soma_remove += (double)time_r.count();
            }
        }
        //cout << endl << cont_s << endl;
        cout << "Tempo de pesquisa: " << fixed << setprecision(6) <<
         (double)(soma_search) << "s" << endl;

        //cout << endl << cont_r << endl;
        cout << "Tempo de remoção: " << fixed << setprecision(6) <<
         (double)(soma_remove) << "s" << endl;
    
    }else{
        cout << "erro!" << endl;
    }

    file.close();
}

/**
 * @brief 
 * 
 */
void MakeMap(){

    cout << "\nFile1.txt" << endl;
    for(int i = 0; i < 10; i++){

        map<double,int> mmap;
        InsertInMap(&mmap, "File1.txt");
        SearchAndRemoveMap(&mmap);
        cout << endl << endl;

    }

    cout << "\nFile2.txt" << endl;
    for(int i = 0; i < 10; i++){

        map<double,int> mmap;
        InsertInMap(&mmap, "File2.txt");
        SearchAndRemoveMap(&mmap);
        cout << endl << endl;

    }

    cout << "\nFile3.txt" << endl;
    for(int i = 0; i < 10; i++){

        map<double,int> mmap;
        InsertInMap(&mmap, "File3.txt");
        SearchAndRemoveMap(&mmap);
        cout << endl << endl;

    }

    cout << "\nFile4.txt" << endl;
    for(int i = 0; i < 10; i++){

        map<double,int> mmap;
        InsertInMap(&mmap, "File4.txt");
        SearchAndRemoveMap(&mmap);
        cout << endl << endl;
    }
}