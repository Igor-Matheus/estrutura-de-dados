## Como Compilar e Executar:

1°) Compile o arquivo utilizando um compilador C++ (g++ por exemplo):

    g++ -o grafo GrafoMatriz.cpp GrafoLista.cpp main.cpp
    

2°) Em seguida, ainda no mesmo diretório da compilação, execute o programa:

    ./grafo <tipo> <arquivo_de_entrada> <origem> <destino>

3°) Exemplos:

    Com matriz de adjacência: ./grafo matriz grafo.txt 0 5

    Com lista de adjacência: ./grafo lista grafo.txt 0 5
