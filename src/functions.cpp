#include "functions.hpp"

void GeneratorNumbers(const int size, string name_arq){

    random_device rd;
    mt19937  ra(rd());

    uniform_real_distribution<> distribution(MIN_VALUE,MAX_VALUE);

    for(int i = 0; i < size; i++){

        cout << fixed << setprecision(4) << distribution(ra) << endl;
    }
}