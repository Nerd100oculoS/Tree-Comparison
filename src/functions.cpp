#include "functions.hpp"

/**
 * @brief Gerador de n\u00fameros
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
 * @brief Insere na arvore
 * 
 * @param root 
 */
void InsertNumbersInBTree(BTree_Tree **root, string name_arq){

    // clock_t start, end;

    // double soma = 000.0000000000;
    string name_file = "./src/files/" + name_arq;
    ifstream file(name_file);
    
    string token_string;
    double token_number;

    BTree_Record reg;

    if(file.is_open()){

        while(getline(file,token_string)){

            token_number = stod(token_string);
            reg.key = token_number;
            // start = clock();
            BTree_insert(root,reg);
            // end = clock();

            // soma += (double)(end - start)/(double)(CLOCKS_PER_SEC);

            // cout << "Tempo: " << fixed << setprecision(10) << (double)(end - start)/(double)(CLOCKS_PER_SEC) << endl;
        }
        
        // cout << fixed << setprecision(10) << (double)soma/SIZE_FILE4 << endl;
    }else{cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;}

    file.close();
}

void SearchAndRemoveNumbersInBTree(BTree_Tree **root){

    steady_clock::time_point start, end;

    int cont = 0;
    int i = 0;

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
            
            start = steady_clock::now();
            BTree_pesquisa(root,&aux,r);
            cont++;
            end = steady_clock::now();

            auto elapsed_seconds = duration_cast<duration<double>>(end - start);
	        
            cout << (double)elapsed_seconds.count() << endl;
		    
            soma_search += (double)elapsed_seconds.count();
		
            

            // if(aux->reg.key == r.key){
               
            //     BTree_remove(root,aux->reg);
            //     i++;
            // }
            
        }
        cout << cont << endl;
        cout << endl <<  (double)(soma_search/cont) << endl;
    
    }else{
        cout << "erro!" << endl;
    }
}