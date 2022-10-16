#include "functions.hpp"

void GeneratorNumbers(const int size, string name_arq){
    
    clock_t start, end;
    
    random_device rd;
    mt19937  ra(rd());

    string name_file = "./src/files/" + name_arq;
    ofstream file(name_file);

    cout << name_file << endl;
    uniform_real_distribution<> distribution(MIN_VALUE,MAX_VALUE);
    
    if(file.is_open()){
        
        start = clock();
        for(int i = 0; i < size; i++){

            file << fixed << setprecision(PRECISION) << distribution(ra) << endl;

        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Tempo para gerar " << size << " números: " << fixed << time_taken << setprecision(5)
            << " segundos" << endl;

    }else{

        cout << "\nERRO AO ABRIR O ARQUIVO!\n" << endl;
    }

    file.close();

}