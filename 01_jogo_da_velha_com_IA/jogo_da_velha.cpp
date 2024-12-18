#include <iostream>
using namespace std;

// Função para imprimir o tabuleiro
void imprimirTabuleiro(const char tabuleiro[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Função para verificar se há dois em sequência
bool verificaDoisEmSequencia(const char tabuleiro[3][3], char jogador, int &linha, int &coluna) {
    // Verificar linhas
    for (int i = 0; i < 3; ++i) {
        int count = 0, vazio = -1;
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == jogador) count++;
            if (tabuleiro[i][j] == ' ') vazio = j;
        }
        if (count == 2 && vazio != -1) {
            linha = i;
            coluna = vazio;
            return true;
        }
    }

    // Verificar colunas
    for (int j = 0; j < 3; ++j) {
        int count = 0, vazio = -1;
        for (int i = 0; i < 3; ++i) {
            if (tabuleiro[i][j] == jogador) count++;
            if (tabuleiro[i][j] == ' ') vazio = i;
        }
        if (count == 2 && vazio != -1) {
            linha = vazio;
            coluna = j;
            return true;
        }
    }

    // Verificar diagonais
    int count = 0, vazio = -1;
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][i] == jogador) count++;
        if (tabuleiro[i][i] == ' ') vazio = i;
    }
    if (count == 2 && vazio != -1) {
        linha = vazio;
        coluna = vazio;
        return true;
    }

    count = 0; vazio = -1;
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][2 - i] == jogador) count++;
        if (tabuleiro[i][2 - i] == ' ') vazio = i;
    }
    if (count == 2 && vazio != -1) {
        linha = vazio;
        coluna = 2 - vazio;
        return true;
    }

    return false;
}

// Função para verificar se há uma jogada que cria duas sequências de dois
bool criaDuasSequencias(const char tabuleiro[3][3], char jogador, int &linha, int &coluna) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') {
                // Simular jogada
                char copia[3][3];
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y)
                        copia[x][y] = tabuleiro[x][y];
                copia[i][j] = jogador;

                int auxLinha, auxColuna;
                int sequencias = 0;
                if (verificaDoisEmSequencia(copia, jogador, auxLinha, auxColuna)) sequencias++;
                copia[auxLinha][auxColuna] = jogador;
                if (verificaDoisEmSequencia(copia, jogador, auxLinha, auxColuna)) sequencias++;

                if (sequencias >= 2) {
                    linha = i;
                    coluna = j;
                    return true;
                }
            }
        }
    }
    return false;
}

// Função principal para decidir a jogada do jogador inteligente
void decidirJogada(char tabuleiro[3][3], char jogador, char oponente, int &linha, int &coluna) {
    // Regra 1: Completar sequência ou bloquear oponente
    if (verificaDoisEmSequencia(tabuleiro, jogador, linha, coluna) || verificaDoisEmSequencia(tabuleiro, oponente, linha, coluna)) {
        return;
    }

    // Regra 2: Criar duas sequências de dois
    if (criaDuasSequencias(tabuleiro, jogador, linha, coluna)) {
        return;
    }

    // Regra 3: Central
    if (tabuleiro[1][1] == ' ') {
        linha = 1;
        coluna = 1;
        return;
    }

    // Regra 4: Canto oposto
    int cantos[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int k = 0; k < 4; ++k) {
        int x = cantos[k][0], y = cantos[k][1];
        int opX = 2 - x, opY = 2 - y;
        if (tabuleiro[x][y] == oponente && tabuleiro[opX][opY] == ' ') {
            linha = opX;
            coluna = opY;
            return;
        }
    }

    // Regra 5: Canto vazio
    for (int k = 0; k < 4; ++k) {
        int x = cantos[k][0], y = cantos[k][1];
        if (tabuleiro[x][y] == ' ') {
            linha = x;
            coluna = y;
            return;
        }
    }

    // Regra 6: Qualquer quadrado vazio
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro[i][j] == ' ') {
                linha = i;
                coluna = j;
                return;
            }
        }
    }

    linha = -1;
    coluna = -1; // Nenhuma jogada disponível (empate)
}

int main() {
    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char jogador = 'X';
    char oponente = 'O';

    cout << "Bem-vindo ao Jogo da Velha!" << endl;
    imprimirTabuleiro(tabuleiro);

    for (int turnos = 0; turnos < 9; ++turnos) {
        if (turnos % 2 == 0) {
            int linha, coluna;
            decidirJogada(tabuleiro, jogador, oponente, linha, coluna);
            tabuleiro[linha][coluna] = jogador;
            cout << "Jogador inteligente jogou em (" << linha << ", " << coluna << ")\n";
        } else {
            int x, y;
            cout << "Sua vez! Digite as coordenadas (linha e coluna): ";
            cin >> x >> y;
            if (tabuleiro[x][y] == ' ') {
                tabuleiro[x][y] = oponente;
            } else {
                cout << "Jogada inválida! Tente novamente.\n";
                --turnos;
                continue;
            }
        }
        imprimirTabuleiro(tabuleiro);
    }

    cout << "Fim de jogo!" << endl;
    return 0;
}
