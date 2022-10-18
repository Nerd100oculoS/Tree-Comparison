#include "functions.hpp"

int main(){
    
    int op = -1;

    while(op != 0){

        cout << "[0] - SAIR!\n";
        cout << "[1] - Árvore Binária Simples\n" << "[2] - Árvore Binária AVL\n"
        << "[3] - Árvore Binária Red-Black\n" << "[4] - Vetor(vector)\n" <<
        "[5] - Unodered_map\n" << "[6] - Map\n\n>>>>>>>> ";
        cin >> op;

        switch(op){

        case 0:
            cout << "Fim do programa!\n\n";
        break;
        
        case 1:

            
            cout << "--------------> Árvore Binária Simples\n\n";
            MakeBinaryTree();
        break;
        
        case 2:

            cout << "--------------> Árvore Binária AVL\n\n";
            MakeAVLTree();
        break;

        case 3:

            cout << "--------------> Árvore Binária Red-Black\n\n";
            MakeRBTree();
        break;

        case 4:

            cout << "--------------> Vetor(vector)\n\n";
            MakeVector();
        break;

        case 5:

            cout << "--------------> Unordered_map\n\n";
            MakeUnorderedMap();
        break;

        case 6:

            cout << "--------------> Map\n\n";
            MakeMap();
        break;

        default:
            break;
        }
    }
    
    return 0;
}