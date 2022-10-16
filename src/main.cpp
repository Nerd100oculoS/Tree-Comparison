#include "functions.hpp"

int main(){

    clock_t start, end;

    start = clock();
    GeneratorNumbers(SIZE_FILE1,"File1.txt");
    GeneratorNumbers(SIZE_FILE2,"File2.txt");
    GeneratorNumbers(SIZE_FILE3,"File3.txt");
    GeneratorNumbers(SIZE_FILE4,"File4.txt");
    end = clock();

    cout << "Tempo total: " << fixed << (double)(end - start)/(double)(CLOCKS_PER_SEC) << setprecision(5) << endl;
    return 0;
}