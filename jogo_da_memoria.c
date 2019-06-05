#include <stdio.h>
#include <stdlib.h> // sleep()
#include <time.h> // time()


// Tela inicial 

void screen() {
	system("echo [93m");
	printf(
"                       .-\"-.           \n"           
"                    .-\"     \"-.       \n"            
"                   /\"-.     .-|                   \n"
"                  /    \"-.-\"  |                   \n"
"                 /      /     |                   \n"
"        .-\"-.   /      /      |       .-\"-.       \n"
"     .-\"     \"-/      /       |    .-\"     \"-.    \n"
"     |-.     .-\"\\    /        |   /\"-.     .-|    \n"
"     |  '-.-\"    \\  /         | /'    \"-.-\"  |    \n"
"     |     \\      \\/   .-\"-.  /'        |    |    \n"
"     |      \\      \\.-\"     \"-.         |    |    \n"
"     |       \\      |-.     .-\"\\        |    |    \n"
"     |        \\     |  \"-.-\"    '\\      |    |    \n"
"     |         \\    |    |        '\\    |    |    \n"
"     |    |\\    \\   |    |          '\\  |    |    \n"
"     |    | \\    \\  |    |            '\\|    |    \n"
"     |    |  \\    \\ |    |    :\\.            |    \n"
"     |    |   \\    \\|    |    |  \\.          |    \n"
"     |    |    \\         |    |    \\.        |    \n"
"     '-.  |  .-\"\\        |    |    '.\\.    .-'    \n"
"        \"-|-\"    \\       |    |      \"-\\.-\"     \n"  
"                  \\      |    |                   \n"
"                   \\     |    |                   \n"
"                    \"-.  |  .-'                   \n"
"                       \"-|-\"\n"
"\n Desenvolvido por Gilmar Silva !!!!!! \t\n"
" Todos os direitos reservados (C) \t\n"
" Bugs envie um issue para o projeto no github -> github.com/heavenh/jogo_3_uni_ufrn/issues \t\n"
	);
	sleep(2);
	system("cls");                                     

}

/* Modelo das cartas */

const char *moldecarta = "\n,---,\t,---,\t,---,\t,---,\n"
                         "| %c |\t| %c |\t| %c |\t| %c |\n"
                         "'---'\t'---'\t'---'\t'---'\n\n";

/* Modelo das cartas Viradas */

int cartasJogo[12] = {'?', '?', '?', '?',
                      '?', '?', '?', '?',
                      '?', '?', '?', '?'};
                      
/* Imprimir Fileira de Cartas */
void imprimefileira(char letra1, char letra2, char letra3, char letra4) {
	system("echo [96m");
    printf(moldecarta, letra1, letra2, letra3, letra4);
}

/* Atualizar as fileiras depois de ser vista  */

void atualizafileiras() {
    system("cls");
    imprimefileira(cartasJogo[0], cartasJogo[1], cartasJogo[2], cartasJogo[3]);
    imprimefileira(cartasJogo[4], cartasJogo[5], cartasJogo[6], cartasJogo[7]);
    imprimefileira(cartasJogo[8], cartasJogo[9], cartasJogo[10], cartasJogo[11]);
}

int main() {
	screen();
    srand(time(NULL));

    int i = 0;

    int cartas[12]; // Definindo quantas cartas quero no jogo
    int posicoes[6] = {0, 0, 0, 0, 0, 0}; // as posições das cartas viradas
    char letras[] = { 'A', 'B', 'C', 'D', 'E', 'F' }; // as letras para ser achada os pares

    for(; i<12; i++) {
        repete:
        cartas[i] = rand() % 6;

        /* esse é um algoritmo de sort pra espalhar
           os pares aleatoriamente */
        switch(cartas[i]) {
        case 0: if(posicoes[0]!=2) posicoes[0]++; else goto repete; break;
        case 1: if(posicoes[1]!=2) posicoes[1]++; else goto repete; break;
        case 2: if(posicoes[2]!=2) posicoes[2]++; else goto repete; break;
        case 3: if(posicoes[3]!=2) posicoes[3]++; else goto repete; break;
        case 4: if(posicoes[4]!=2) posicoes[4]++; else goto repete; break;
        case 5: if(posicoes[5]!=2) posicoes[5]++; else goto repete; break;
        default: break;
        }
    }
    
    /* Imprimir as fileiras depois de ser informadas */
    system("echo [32m");
	printf("\nO jogo começa em 3 segundos.. prepare-se !!!");
	sleep(3);
	system("cls");

    imprimefileira(letras[cartas[0]], letras[cartas[1]], letras[cartas[2]], letras[cartas[3]]);
    imprimefileira(letras[cartas[4]], letras[cartas[5]], letras[cartas[6]], letras[cartas[7]]);
    imprimefileira(letras[cartas[8]], letras[cartas[9]], letras[cartas[10]], letras[cartas[11]]);
	
    sleep(6);
    unsigned int tentativa = 0, acertos = 0;

    escolha:
    atualizafileiras();

    char pos, num;
    printf("Escolha uma carta (A-C)[1-4]: ", tentativa);

    struct {
        int pos;
        char letra;

    } escolhaJogo;

    fscanf(stdin, "%c%c", &pos, &num);
    getchar();
    fflush(stdin);

    if ( num>48 ) num-=48;

	/* Comparação se as cartas são iguais */

    if (((pos>=65 && pos<=67) || (pos>=97 && pos<=99))
       &&(num>=1 && num <=4 )) {
        tentativa++;

        int mpos;
        if ( pos == 'a' || pos == 'A' ) mpos=0;
        if ( pos == 'b' || pos == 'B' ) mpos=1;
        if ( pos == 'c' || pos == 'C' ) mpos=2;

        if ( cartasJogo[(mpos*4)+num-1] != '?' ) {
            printf("Carta já escolhida.\n");
            goto escolha;
        }

        if ( !(tentativa%2) ) {
            if ( letras[cartas[(mpos*4)+num-1]] == escolhaJogo.letra )
            {
                cartasJogo[(mpos*4)+num-1] = letras[cartas[(mpos*4)+num-1]];
                cartasJogo[escolhaJogo.pos] = escolhaJogo.letra;

                acertos++;
                if ( acertos == 6 ) goto fim;

            }
            else
            {
                cartasJogo[(mpos*4)+num-1] = letras[cartas[(mpos*4)+num-1]];
                atualizafileiras();
                printf("Errou Loko :P\n");
                sleep(1);

                cartasJogo[(mpos*4)+num-1] = '?';
                cartasJogo[escolhaJogo.pos] = '?';
            }
        }
        else {
            cartasJogo[(mpos*4)+num-1] = letras[cartas[(mpos*4)+num-1]];
        }

        escolhaJogo.pos = (mpos*4)+num-1;
        escolhaJogo.letra = letras[cartas[(mpos*4)+num-1]];

        goto escolha;
    }
    else {
        printf("Selecao invlida!\n");
        goto escolha;
    }

    fim:
    atualizafileiras();
    printf("Voce completou em %d tentativas!\nObrigado por jogar.\n\n", tentativa+1);

    return 0;
}
