<div align="justify">

<div align="center">

# Comparação de Estruturas de Dados 

</div>

## 1 - Introdução

**Árvores de Pesquisa Binária (APB)**, Árvores Binárias balanceadas **AVL** e **Red-Black**, **Vetores Dinâmicos** - *vector* em C++ - e **Tabela Hash** - *unordered_map* e *map* em C++ - são as estruturas que foram comparadas neste repósitorio. Nos tópicos a seguir, será discutido brevemente o que são estas estruturas e o porquê de compará-las entre si, além de apresentar resultados obtidos e também discuti-los.

## 2 - Apresentação e objetivo

Por meio de 4 arquivos de entrada, *File1.txt*, *File2.txt*, *File3.txt* e *File4.txt* com respectivamente, 500 (Quinhentos), 5.000 (Cinco Mil), 50.000 (Cinquenta Mil) e 500.000 (Quinhentos Mil) números decimais que variam de `00000.00000` até `99999.99999`. Cada **Estrutura de Dados (ED)** citada no tópico anterior, foi implementada 4 vezes, a mesma  **ED** para cada arquivo. Ou seja, 4 **APB's**, 4 **AVL's**, 4 **Red-Black's**, 4 **Vetores**, 8 **Tabelas Hash** - ***4 unodered_map's e 4 map's***. Totalizando 24 estruturas criadas por meio da *inserção*.

Após a criação de cada estrutura pega-se o arquivo *search.txt* com 10.000 (Dez Mil) números decimais. Este arquivo foi criado copiando de forma aleatória e embaralhando números presentes nos 4 arquivos iniciais de entrada. O arquivo *search.txt*  é utilizado para *pesquisa* em cada uma das estruturas criadas.

Fazendo cada um dos procedimentos descritos nos parágrafos acima para cada uma das **ED's** criadas, entra a parte de remoção. Utilizando o mesmo arquivo para a pesquisa, os elementos que estiverem presente na pesquisa são removidos.
O objetivo é pegar cada uma das etapas, *inserção*, *pesquisa* e *remoção*, calcular seus tempos de forma independente para cada uma das estruturas e assim, análisa-las, apresentar seus resultados e discuti-las.

## 3 - Metodologia

Os tempos das etapas são computados por meio da biblioteca **`chronos`**. Para exemplificar de maneira geral, nos parágrafos abaixo será monstado passo-a-passo medição de tempo de todas as estapas da estrutura de **ABP**. Além disso, também será evidenciado alguns casos especiais que diferem do casual.

## 5 - Conclusão

## 6 - Referência

## 7 - Compilação e Execução

</div>
