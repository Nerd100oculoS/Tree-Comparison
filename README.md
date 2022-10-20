<div align="justify">

<div align="center">

# Comparação de Estruturas de Dados 

</div>

## 1 - Introdução

**Árvores de Pesquisa Binária (APB)**, Árvores Binárias balanceadas **AVL** e **Red-Black**, **Vetores Dinâmicos** - *vector* em C++ - e **Tabela Hash** - *unordered_map* e *map* em C++ - são as estruturas que foram comparadas neste repósitorio. Nos tópicos a seguir, será discutido brevemente o que são estas estruturas e o porquê de compará-las entre si, além de apresentar resultados obtidos e também discuti-los.

## 2 - Apresentação e objetivo

Por meio de 4 arquivos de entrada, *File1.txt*, *File2.txt*, *File3.txt* e *File4.txt* com respectivamente, 500 (Quinhentos), 5.000 (Cinco Mil), 50.000 (Cinquenta Mil) e 500.000 (Quinhentos Mil) números decimais que variam de `00000.00000` até `99999.99999`. Cada **Estrutura de Dados (ED)** citada no tópico anterior, foi implementada 4 vezes, a mesma  **ED** para cada arquivo. Ou seja, 4 **APB's**, 4 **AVL's**, 4 **Red-Black's**, 4 **Vetores**, 8 **Tabelas Hash** - ***4 unodered_map's e 4 map's***. Totalizando 24 estruturas criadas por meio da *inserção*.

Após a criação de cada estrutura tem-se o arquivo *search.txt* com 10.000 (Dez Mil) números decimais. Este arquivo foi criado copiando de forma aleatória e embaralhando números presentes nos 4 arquivos iniciais de entrada. O arquivo *search.txt*  é utilizado para *pesquisa* em cada uma das estruturas criadas.

Fazendo cada um dos procedimentos descritos nos parágrafos acima para cada uma das **ED's** criadas, entra a parte de remoção. Utilizando o mesmo arquivo para a pesquisa, os elementos que estiverem presente na pesquisa são removidos.

O objetivo é executar cada uma das etapas, *inserção*, *pesquisa* e *remoção*, calcular seus tempos de forma independente para cada uma das estruturas e assim, análisar, apresentar seus resultados e discuti-los.

## 3 - Metodologia

Os tempos das etapas são computados por meio da biblioteca **`chronos`**. Como exemplo geral, nos parágrafos abaixo será monstrado passo-a-passo a medição de tempo para todas as etapas da estrutura de **APB**. Além disso, também será evidenciado alguns casos especiais que diferem do formato geral.

Por meio da função **`InsertNumbersInBTree(Btree **root, string name_arq)`** é feita a inserção na árvore. O primeiro parâmetro é o endereço da raiz da árvore, o segundo é o nome do arquivo com a sua extensão. É por meio do segundo parâmetro que a função sabe qual arquivo será lido como entrada para a estrutura - Exemplo: ***InsertNumbersInBTree(&root, "File1.txt")*** . A medição do tempo é feita a cada *inserção* na árvore e somado para obter o tempo total de *inserção* referente ao arquivo.

As etapas de *pesquisa* e *remoção* é feita pela função  **`SearchAndRemoveNumbersInBTree(BTree_Tree **root)`** - Exemplo: ***SearchAndRemoveNumbersInBTree(&root)*** , tendo como parâmetro apenas o endereço da raiz da árvore. No caso desta função, ao passar a raiz da árvore, é feita a leitura do arquivo *search.txt* e ao ler cada uma das entradas do arquivo, é realizada a *pesquisa*. Caso a pesquisa encontre o elemento que se está procurando, então é feita a remoção deste elemento da árvore. O tempo de *pesquisa* e *remoção* são calculados de forma idependente, da mesma forma que na inserção. A cada *pesquisa* e a cada provável *remoção* é feita a contabilização do tempo e é somado a cada nova entrada do arquivo *search.txt* para obter o tempo total para a *pesquisa* e para as possíveis remoções.

Para conseguir fazer uma média com o tempo de cada etapa, foi implementada a função **`MakeBTree()`**. Nela são criados 4 loops, que rodam 10 vezes cada - para que seja possível calcular uma média e um desvio-padrão -, e em cada loop é feita uma estrutura de **APB**. Uma árvore é criada em cada loop para cada arquivo, diferente - 4 loops para 4 arquivos. Chamando as funções criadas a cima para obter o tempo de *insercão*, *pesquisa* e *remoção* em cada loop. A figura 1 abaixo, evidencia como isso foi feito em código.

<div align="center">

![make](./assets/makebtree.png "makebtree.png")
Figura 1 - Código de Função **`MakeBTree()`**
</div>

De forma análoga ao explicado nos parágrafos anteriores, todas as **ED's** se baseiam neste formato de 3 funções para as etapas a serem executadas. Com a execessão do **Vetor(vector)** - que não é uma **ED**, mas sim, um **Vetor Dinâmico** -, cuja a função de *inserção*, o tempo é calculado juntamente com a **Ordenação** do vetor. Além disso, na função de *pesquisa* e *remoção* é tabém obtido o tempo de **Pesquisa Binária** no vetor. Na figura 2 a seguir, mostra o arquivo cabeçalho do código para melhor entendimento.

<div align="center">

![cabecalho](./assets/cabecalho.png "cabecalho.png")
Figura 2 - Arquivo cabeçalho (Funções de Implementação).
</div>


## 4 - Resultados e Discussão

## 5 - Conclusão

## 6 - Referências


</div>
