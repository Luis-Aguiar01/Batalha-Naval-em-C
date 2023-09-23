#include <stdio.h>

void escolherNomes(char jogador1[], char jogador2[]);
void imprimirTabuleiro(const int tabuleiro[8][8]);
int *definirPontoCentral(int tabuleiro[8][8]);
int *definirPontoAdjacente1(int tabuleiro[8][8], int *pontoCentPtr);
int *definirPontoAdjacente2(int tabuleiro[8][8], int *adjacente1Ptr, int *adjacente2Ptr);
void validarPontos(const int tabuleiro[8][8], int *linha, int *coluna);
int validarCoordenada1(const int *pontoCentPtr, const int *adjacente1Ptr, int coluna);
int validarCoordenada2(const int *pontoCentPtr, const int *adjacente1Ptr, const int *adjacente2Ptr, int coluna);
void imprimirGabarito(const int gabarito[8][8]);
int definirTiros(int gabarito[8][8], const int tabuleiro[8][8]);
void informarResultadoDoJogo(int pontos1, int pontos2, const char jogador1[], const char jogador2[]);
void informarInicio();
void nomeDoJogo();
void reiniciarMatriz(int matriz[8][8]);

int main() {

    int tabuleiro[8][8] = {0};
    int gabarito[8][8] = {0};
    int *pontoCentralPtr;
    int *pontoAdjacente1Ptr;
    int *pontoAdjacente2Ptr;
    char jogador1[50];
    char jogador2[50];
    int resultadoJogador1;
    int resultadoJogador2;
    
    system("cls");

    nomeDoJogo();

    escolherNomes(jogador1, jogador2);
    
    informarInicio();

    for(int i = 1; i <= 2; i++) {

        if(i == 1) {
            
            printf("\nRODADA %d: \n\n", i);
            
            printf("%s, escolha tres pontos adjacentes para serem o seu barco\n"
                "tres pontos na horizontal ou vertical"
                "\nfaca a sua escolha: \n", jogador1);

                imprimirTabuleiro(tabuleiro);

                pontoCentralPtr = definirPontoCentral(tabuleiro);
                *pontoCentralPtr = 1;

                imprimirTabuleiro(tabuleiro);

                pontoAdjacente1Ptr = definirPontoAdjacente1(tabuleiro, pontoCentralPtr);
                *pontoAdjacente1Ptr = 1;

                imprimirTabuleiro(tabuleiro);

                pontoAdjacente2Ptr = definirPontoAdjacente2(tabuleiro, pontoCentralPtr, pontoAdjacente1Ptr);
                *pontoAdjacente2Ptr = 1;

                imprimirTabuleiro(tabuleiro);
                
                printf("PRESSIONE ENTER PARA CONTINUAR: ");

                getchar();
                getchar();

                system("cls");

                printf("\n%s, agora e sua vez!!\n"
                "Escolha posicoes para os seus cinco tiros\n"
                "Se voce acertar, recebe mais um tiro\n"
                "Boa sorte!!\n", jogador2);

                resultadoJogador1 = definirTiros(gabarito, tabuleiro);

                printf("\nO gabarito: \n");

                imprimirTabuleiro(tabuleiro);

                printf("\nAs suas escolhas: \n");

                imprimirGabarito(gabarito);
                
                printf("\nPRESSIONE ENTER PARA A PROXIMA RODADA!");

                getchar();
                getchar();
        }

        if(i == 2) {

            system("cls");
            
            reiniciarMatriz(tabuleiro);
            reiniciarMatriz(gabarito);

            printf("RODADA %d: \n\n", i);

            printf("%s, escolha tres pontos adjacentes para serem o seu barco\n"
                "tres pontos na horizontal ou vertical"
                "\nfaca a sua escolha: \n", jogador2);

                imprimirTabuleiro(tabuleiro);

                pontoCentralPtr = definirPontoCentral(tabuleiro);
                *pontoCentralPtr = 1;

                imprimirTabuleiro(tabuleiro);

                pontoAdjacente1Ptr = definirPontoAdjacente1(tabuleiro, pontoCentralPtr);
                *pontoAdjacente1Ptr = 1;

                imprimirTabuleiro(tabuleiro);

                pontoAdjacente2Ptr = definirPontoAdjacente2(tabuleiro, pontoCentralPtr, pontoAdjacente1Ptr);
                *pontoAdjacente2Ptr = 1;

                imprimirTabuleiro(tabuleiro);

                printf("PRESSIONE ENTER PARA CONTINUAR: ");

                getchar();
                getchar();

                system("cls");

                printf("\n%s, agora e sua vez!!\n"
                "Escolha posicoes para os seus cinco tiros\n"
                "Se voce acertar, recebe mais um tiro\n"
                "Boa sorte!!\n", jogador1);

                resultadoJogador2 = definirTiros(gabarito, tabuleiro);

                printf("\nO gabarito: \n");

                imprimirTabuleiro(tabuleiro);

                printf("\nAs suas escolhas: \n");

                imprimirGabarito(gabarito);

                printf("\nPRESSIONE ENTER PARA VER O RESULTADO: \n");

                getchar();
                getchar();
        }
    }

    system("cls");

    informarResultadoDoJogo(resultadoJogador1, resultadoJogador2, jogador1, jogador2);
    
}

void imprimirTabuleiro(const int tabuleiro[8][8]) {
    
    printf("\n---------------------------------------");
    printf("\nCOORD|  0   1   2   3   4   5   6   7  |");

    printf("\n---------------------------------------\n");

    for(int i = 0; i < 8; i++) {

        for(int j = 0; j < 8; j++) {
            
            if(j == 0) {
                printf("%2d", i);
                printf("   |");
            }

            printf("%3d ", tabuleiro[i][j]);

            if(j == 7) {
                printf(" |");
            }
        }

        printf("\n");
    }

    printf("---------------------------------------\n");

}

void validarPontos(const int tabuleiro[8][8], int *linha, int *coluna) {

    while(*linha > 7 || *coluna > 7 || *linha < 0 || *coluna < 0 || tabuleiro[*linha][*coluna] != 0) {    
        printf("\n\n -------- Escolha invalida. Pontos fora da coordenada ou espaco ja ocupado. -------\n\nEscolha novamente: \n");
        printf("Linha: ");
        scanf("%d", linha);
        printf("Coluna: ");
        scanf("%d", coluna);
    }
}

int *definirPontoCentral(int tabuleiro[8][8]) {

    int pontoCent1, pontoCent2;

    printf("\nEscolha a posicao central: \n");
    
    printf("Valor da linha: ");
    scanf("%d", &pontoCent1);
    
    printf("Valor da coluna: ");
    scanf("%d", &pontoCent2);

    validarPontos(tabuleiro, &pontoCent1, &pontoCent2);

    return &tabuleiro[pontoCent1][pontoCent2];

}

int *definirPontoAdjacente1(int tabuleiro[8][8], int *pontoCentPtr) {

    int adj1, adj2;

    printf("\n\nEscolha a posicao adjacente do ponto 1: \n");
    
    printf("Valor da linha: ");
    scanf("%d", &adj1);
    
    printf("Valor da coluna: ");
    scanf("%d", &adj2);

    validarPontos(tabuleiro, &adj1, &adj2);

    while(validarCoordenada1(pontoCentPtr, &tabuleiro[adj1][adj2], adj2) != 1) {
        
        printf("\n\n ------- As coordenadas inseridas nao formam um navio. -------\n\nDigite novamente\n");
        
        printf("Valor da linha: ");
        scanf("%d", &adj1);
       
        printf("Valor da coluna: ");
        scanf("%d", &adj2);
        
        validarPontos(tabuleiro, &adj1, &adj2);
    }

    printf("\nCoordenadas corretas!\n");

    return &tabuleiro[adj1][adj2];
}

int *definirPontoAdjacente2(int tabuleiro[8][8], int *pontoCentPtr, int *adjacente1Ptr) {

    int adj3, adj4;

    printf("\n\nEscolha a posicao adjacente do ponto 2: \n");
    
    printf("Valor da linha: ");
    scanf("%d", &adj3);
    
    printf("Valor da coluna: ");
    scanf("%d", &adj4);

    validarPontos(tabuleiro, &adj3, &adj4);

    while( validarCoordenada2(pontoCentPtr, adjacente1Ptr, &tabuleiro[adj3][adj4], adj4) == 0 ) {
        
        printf("\n\n ------- As coordenadas inseridas nao formam um navio. -------\n\nDigite novamente\n");
        
        printf("Valor da linha: ");
        scanf("%d", &adj3);
       
        printf("Valor da coluna: ");
        scanf("%d", &adj4);
        
        validarPontos(tabuleiro, &adj3, &adj4);
    }

    printf("\nCoordenadas corretas!\n");

    return &tabuleiro[adj3][adj4];
}

int validarCoordenada1(const int *pontoCentPtr, const int *adjacente1Ptr, int coluna) { 
    
    if( ( adjacente1Ptr == (pontoCentPtr - 8) ) || 
        ( adjacente1Ptr == (pontoCentPtr + 8) ) || 
        ( ( adjacente1Ptr == (pontoCentPtr + 1) )  && ( coluna != 0) ) || 
        ( ( adjacente1Ptr == (pontoCentPtr - 1) ) && (coluna != 7) ) ) 
    {
        return 1;
    } 
    else {
        return 0;
    }
}

int validarCoordenada2(const int *pontoCentPtr, const int *adjacente1Ptr, const int *adjacente2Ptr, int coluna) {

    if( ( adjacente1Ptr == (pontoCentPtr - 8) ) || ( adjacente1Ptr == (pontoCentPtr + 8) ) ) {
        
        if( ( ( adjacente2Ptr == (pontoCentPtr - 8) ) && ( *(pontoCentPtr - 8) == 0 ) ) || 
        ( ( adjacente2Ptr == (pontoCentPtr + 8) ) && ( *(pontoCentPtr + 8) == 0 ) ) || 
        ( ( adjacente2Ptr == (adjacente1Ptr - 8) ) && ( *(adjacente1Ptr - 8) == 0 ) ) || 
        ( ( adjacente2Ptr == (adjacente1Ptr + 8) ) && ( *(adjacente1Ptr + 8) == 0 ) ) ) 
        {
            return 1;
        } 
        else {
            return 0;
        }
    }

    else if( ( adjacente1Ptr == ( pontoCentPtr + 1 ) ) || ( adjacente1Ptr == (pontoCentPtr - 1 ) ) ) {

        if( ( ( adjacente2Ptr == (pontoCentPtr - 1) ) && ( *(pontoCentPtr - 1) == 0 ) && (coluna != 7)) || 
            ( ( adjacente2Ptr == (pontoCentPtr + 1) ) && ( *(pontoCentPtr + 1) == 0 ) && (coluna != 0)) ||
            ( ( adjacente2Ptr == (adjacente1Ptr - 1) ) && ( *(adjacente1Ptr - 1) == 0 ) && (coluna != 7)) || 
            ( ( adjacente2Ptr == (adjacente1Ptr + 1) ) && ( *(adjacente1Ptr + 1) == 0)  && (coluna != 0) ) ) 
        {
            return 1;
        } 
        else {
            return 0;
        }
    }   
}

void escolherNomes(char jogador1[], char jogador2[]) {

    printf("\n\n------------------------------------------\n");
    printf("|                                        |\n");
    printf("|      ESCOLHA OS NOMES DOS JOGADORES    |\n");
    printf("|                                        |\n");
    printf("------------------------------------------\n");

    printf("\nJOGADOR 1: ");
    scanf(" %[^\n]", jogador1);

    getchar();

    printf("JOGADOR 2: ");
    scanf(" %[^\n]", jogador2);

    getchar();

    printf("\n\n----------------------------------------------------------------------------\n");
    printf("|                               BEM VINDOS!                                 |\n");
    printf("|                                                                           |\n");
    printf("|   JOGADOR 1: %-20s                                         |\n", jogador1);
    printf("|   JOGADOR 2: %-20s                                         |\n", jogador2);
    printf("----------------------------------------------------------------------------\n\n");
}

void informarInicio(){
    system("cls");

    printf("\n\n==========================================\n");
    printf("|           A PARTIDA COMECOU!           |\n");
    printf("==========================================\n");
}

void imprimirGabarito(const int gabarito[8][8]) {

printf("\n---------------------------------------");
    printf("\nCOORD|  0   1   2   3   4   5   6   7  |");

    printf("\n---------------------------------------\n");

    for(int i = 0; i < 8; i++) {

        for(int j = 0; j < 8; j++) {
            
            if(j == 0) {
                printf("%2d", i);
                printf("   |");
            }

            printf("%3d ", gabarito[i][j]);

            if(j == 7) {
                printf(" |");
            }
        }

        printf("\n");
    }

    printf("---------------------------------------\n");
}

int definirTiros(int gabarito[8][8], const int tabuleiro[8][8]) {

    int tiros = 5;
    int linha;
    int coluna;
    int acertos = 0;

    printf("\nEscolha as posicaos dos seus tiros(1 para casa certa e 5 para casa errada): \n");

    imprimirGabarito(gabarito);

    while(tiros != 0 && acertos != 3) {

        printf("\nLinha: ");
        scanf("%d", &linha);

        printf("Coluna: ");
        scanf("%d", &coluna);

        validarPontos(gabarito, &linha, &coluna);

        if(tabuleiro[linha][coluna] == 1) {
            printf("\n\nVoce acertou!!!\nVoce ganhou mais um tiro!\n");
            gabarito[linha][coluna] = 1;
            acertos++;
        } 
        else if(tabuleiro[linha][coluna] == 0 && tiros != 1) {
            printf("\n\nVoce errou!\nTente mais uma vez!\n");
            gabarito[linha][coluna] = 5;
            tiros--;
        } else {
            printf("\nAcabaram as suas chances!\n");
            tiros--;
            gabarito[linha][coluna] = 5;
        }

        printf("TIROS: %d\n", tiros);

        imprimirGabarito(gabarito);
    }

    if(acertos == 3) {
        printf("\n-----------------------------------\n");
        printf("|     VOCE DESTRUIU O NAVIO!!     |\n");
        printf("|      VOCE GANHOU UM PONTO!!     |\n");
        printf("-----------------------------------\n");
    } else {
        printf("\n----------------------------------------\n");
        printf("|  Que pena! Voce nao acertou o navio. |\n");
        printf("----------------------------------------\n");
    }

    if(acertos == 3) {
        return 1;
    }

    return 0;
}

void informarResultadoDoJogo(int pontos1, int pontos2, const char jogador1[], const char jogador2[]) {

    if(pontos1 > pontos2) {
        printf("\n===========================================\n");
        printf("\n");
        printf("                %s, VENCEU!!           ", jogador1);
        printf("\n");
        printf("Pontos %s: %d\n", jogador1, pontos1);
        printf("Pontos %s: %d\n", jogador2, pontos2);
        printf("\n===========================================\n");
    }

    if(pontos2 > pontos1) {
        printf("\n===========================================\n");
        printf("\n");
        printf("                %s, VENCEU!!           ", jogador2);
        printf("\n");
        printf("Pontos %s: %d\n", jogador1, pontos1);
        printf("Pontos %s: %d\n", jogador2, pontos2);
        printf("\n===========================================\n");
    }

    if(pontos1 == pontos2) {
        printf("\n===========================================\n");
        printf("\n");
        printf("                  EMPATE!!           ");
        printf("\n");
        printf("Pontos %s: %d\n", jogador1, pontos1);
        printf("Pontos %s: %d\n", jogador2, pontos2);
        printf("\n===========================================\n");
    }
}

void nomeDoJogo() {
    printf("\n=================================\n");
    printf("|          BATALHA NAVAL        |");
    printf("\n=================================\n");
}

void reiniciarMatriz(int matriz[8][8]) {

    for(int i = 0; i < 8; i++) {

        for(int j = 0; j < 8; j++) {
            matriz[i][j] = 0;
        }
    }
}