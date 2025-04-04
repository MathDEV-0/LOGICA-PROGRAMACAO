/*
As teclas direcionais são usadas para realizar jogadas (cima, baixo, esquerda e direita). A cada vez que uma tecla é pressionada, os blocos numerados tentam deslizar pela matriz caso haja espaço. No exemplo da imagem acima, se a tecla para esquerda for pressionada, 5 blocos irão se mover (8, 2, 16, 2, 32).

Além de tentar deslizar, blocos adjacentes com o mesmo número se juntam em um único bloco com um número dobrado caso tentem deslizar na direção certa. No exemplo da imagem acima, se a tecla para baixo for pressionada, dois blocos 2 irão se transformar em um bloco 4 e dois blocos 32 irão se transformar em um bloco 64.

Durante o jogo, além de fazer as jogadas, surgem aleatoriamente blocos na matriz com números iguais a potências de 2. O objetivo é fazer os blocos se juntarem para que um bloco com número 2048 seja formado. Quando isso acontece, o jogador vence o jogo e não é possível fazer mais jogadas.

Porém, também pode acontecer do jogador não ter mais jogadas possíveis antes de formar o número 2048. No exemplo da imagem, apertar a tecla para a direita não é uma jogada válida, pois nenhum bloco pode se mover ou se juntar a outro bloco.

Sua tarefa nesse problema é dizer quais são as jogadas válidas para uma determinada situação do jogo.

Entrada
A entrada é iniciada por uma linha que contém o número de casos de teste. Para cada caso de teste, a entrada consiste em 4 linhas contendo uma matriz quadrada de dimensão 4. Os números da matriz são iguais a 0 para indicar que não bloco na posição, ou são iguais a potências de 2 entre 2 e 2048 inclusive.

Saída
Para cada teste, a saída consiste de uma linha contendo todas as jogadas possíveis para a entrada. As jogadas são indicadas por DOWN (baixo), LEFT (esquerda), RIGHT (direita) e UP (cima). As jogadas devem ser escritas em ordem alfabética. Caso não haja nenhuma jogada possível, imprima NONE.
*/


#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int matriz[4][4];

        bool check2048 = false;

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cin>>matriz[i][j]; 
                if(matriz[i][j] == 2048) check2048 = true;
            }
        }

        if(check2048){
            cout<<"NONE\n";
            continue;
        }

        bool Left = false, Right = false, Up = false, Down = false; //Condições de verificação

        //A lógica é ver se na direita (j+1), esquerda (j-1), cima(i-1) ou baixo(i+1) há um valor 0 ou igual ao valor da posicao[i][j] de uma matriz M

        //Verificação da esquerda
        for(int i = 0; i < 4; i++){ //i começa de 0 (não estamos mexendo diretamente com linhas diferentes)
            for(int j = 1; j < 4; j++){ //j deve começar com 1 (afinal, se acessarmos j-1 de 0 j= -1 o que é um índice inválido)
                if ((matriz[i][j] != 0 && matriz[i][j - 1] == 0) || (matriz[i][j] != 0 && matriz[i][j] == matriz[i][j - 1])) {
                    Left = true; ////Se o atual da coluna não for 0 ou for igual ao anterior, então movimenta-se para a esquerda
                }
            }
        }

        //Verificação da direita
        for(int i = 0; i < 4; i++){ //i começa de 0 (não estamos mexendo diretamente com linhas diferentes)
            for(int j = 0; j < 3; j++){ //j deve começar com 0 (afinal, se acessarmos j-1 de 0 j= -1 o que é um índice inválido), mas terminar em 3, afinal j+1 de 4 = 5 e 5 é um índice inválido
                if ((matriz[i][j] != 0 && matriz[i][j + 1] == 0) || (matriz[i][j] != 0 && matriz[i][j] == matriz[i][j + 1])) {
                    Right = true; ////Se o atual da coluna não for 0 ou for igual ao posterior, então movimenta-se para a direita
                }
            }
        }

        //Verificação de cima
        for(int i = 1; i < 4; i++){ //i começa de 1 (afinal, se acessarmos i-1 de 0, temos o índice inválido '-1')
            for(int j = 0; j < 4; j++){ //j deve começar com 0 (não estamos mexendo diretamente com colunas diferentes)
                if ((matriz[i][j] != 0 && matriz[i-1][j] == 0) || (matriz[i][j] != 0 && matriz[i][j] == matriz[i-1][j])) {
                    Up = true; ////Se o atual da linha não for 0 ou for igual ao de cima, então movimenta-se para cima
                }
            }
        }

        //Verificação de baixo
        for(int i = 0; i < 3; i++){ //i começa de 0, mas vai até 3 (afinal, se usarmos o i+1 de 4 acessamos o índice inválido 5)
            for(int j = 0; j < 4; j++){ //j deve começar com 0 (não estamos mexendo diretamente com colunas diferentes)
                if ((matriz[i][j] != 0 && matriz[i+1][j] == 0) || (matriz[i][j] != 0 && matriz[i][j] == matriz[i+1][j])) {
                    Down = true; ////Se o atual da linha não for 0 ou for igual ao de biaxo, então movimenta-se para baixo
                }
            }
        }

        if (!Left && !Right && !Up && !Down) {
            cout << "NONE\n"; //Se nenhum dos bool ativar, então escreve NONE
        } 
        else {
            char espaco = '\0'; // Inicializa com o valor nulo (sem separador no início)
 
             if (Down) {
                 if (espaco) cout << espaco; 
                 cout << "DOWN";
                 espaco = ' '; 
             }
             if (Left) {
                 if (espaco) cout << espaco;
                 cout << "LEFT";
                 espaco = ' ';
             }
             if (Right) {
                 if (espaco) cout << espaco;
                 cout << "RIGHT";
                 espaco = ' ';
             }
             if (Up) {
                 if (espaco) cout << espaco;
                 cout << "UP";
             }
             cout << "\n";//Aquele quebra-linha que salva vidas no beecrowd
         }
     }
 
     return 0;
 }

  