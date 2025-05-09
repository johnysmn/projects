#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Configurações específicas para Windows/Linux
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(msec) Sleep(msec)
    #define CLEAR_SCREEN() system("cls")
#else
    #include <unistd.h>
    #include <termios.h>
    #include <fcntl.h>
    #define SLEEP_MS(msec) usleep(msec * 1000)
    #define CLEAR_SCREEN() system("clear")
#endif

#define LARGURA 80
#define ALTURA 25
#define PADDLE_TAM 4

// Função para verificar tecla pressionada (cross-platform)
int key_pressed() {
    #ifdef _WIN32
        return _kbhit();
    #else
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if(ch != EOF) return ch;
        return 0;
    #endif
}

int main() {
    int jogador1 = ALTURA/2 - PADDLE_TAM/2;
    int jogador2 = ALTURA/2 - PADDLE_TAM/2;
    int bolaX = LARGURA/2;
    int bolaY = ALTURA/2;
    int dirBolaX = 1;
    int dirBolaY = 1;
    int pontos1 = 0, pontos2 = 0;

    // Loop principal do jogo
    while(true) {
        // Verificar entrada
        int tecla = key_pressed();
        switch(tecla) {
            case 'w': if(jogador1 > 1) jogador1--; break;
            case 's': if(jogador1 < ALTURA - PADDLE_TAM - 1) jogador1++; break;
            #ifdef _WIN32
                case 72: if(jogador2 > 1) jogador2--; break;  // Seta para cima
                case 80: if(jogador2 < ALTURA - PADDLE_TAM - 1) jogador2++; break;  // Seta para baixo
            #else
                case 'i': if(jogador2 > 1) jogador2--; break;  // Tecla I para cima
                case 'k': if(jogador2 < ALTURA - PADDLE_TAM - 1) jogador2++; break;  // Tecla K para baixo
            #endif
            case 27: exit(0);  // ESC para sair
        }

        // Atualizar posição da bola
        bolaX += dirBolaX;
        bolaY += dirBolaY;

        // Colisões com bordas
        if(bolaY <= 1 || bolaY >= ALTURA-2) dirBolaY *= -1;

        // Colisões com paddles
        if(bolaX <= 3 && bolaY >= jogador1 && bolaY <= jogador1 + PADDLE_TAM) dirBolaX *= -1;
        if(bolaX >= LARGURA-4 && bolaY >= jogador2 && bolaY <= jogador2 + PADDLE_TAM) dirBolaX *= -1;

        // Pontuação
        if(bolaX < 1) {
            pontos2++;
            bolaX = LARGURA/2;
            bolaY = ALTURA/2;
        }
        if(bolaX > LARGURA-1) {
            pontos1++;
            bolaX = LARGURA/2;
            bolaY = ALTURA/2;
        }

        // Desenhar tela
        CLEAR_SCREEN();

        // Bordas superiores
        for(int i = 0; i < LARGURA; i++) printf("#");
        printf("\n");

        // Conteúdo principal
        for(int y = 1; y < ALTURA-1; y++) {
            for(int x = 0; x < LARGURA; x++) {
                if((x == 2 && y >= jogador1 && y <= jogador1 + PADDLE_TAM) ||
                   (x == LARGURA-3 && y >= jogador2 && y <= jogador2 + PADDLE_TAM)) {
                    printf("|");
                }
                else if(x == bolaX && y == bolaY) {
                    printf("O");
                }
                else if(x == 0 || x == LARGURA-1) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Bordas inferiores
        for(int i = 0; i < LARGURA; i++) printf("#");
        printf("\n");

        // Placar
        printf("Jogador 1: %d  Jogador 2: %d\n", pontos1, pontos2);

        // Controle de velocidade
        SLEEP_MS(50);
    }

    return 0;
}
