#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Códigos de cores ANSI
#define RESET "\033[0m"
#define VERMELHO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AMARELO "\033[1;33m"
#define AZUL "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CIANO "\033[1;36m"
#define BRANCO "\033[1;37m"
#define LARANJA "\033[38;5;208m"
#define CINZA "\033[1;90m"

// Tipos de Pokémon
#define TIPO_FOGO 1
#define TIPO_AGUA 2
#define TIPO_PLANTA 3
#define TIPO_ELETRICO 4
#define TIPO_GELO 5
#define TIPO_LUTADOR 6
#define TIPO_VOADOR 7
#define TIPO_PSIQUICO 8
#define TIPO_NOTURNO 9

// Função para obter cor do tipo
const char* getCor(int tipo) {
    switch(tipo) {
        case TIPO_FOGO: return VERMELHO;
        case TIPO_AGUA: return AZUL;
        case TIPO_PLANTA: return VERDE;
        case TIPO_ELETRICO: return AMARELO;
        case TIPO_GELO: return CIANO;
        case TIPO_LUTADOR: return LARANJA;
        case TIPO_VOADOR: return BRANCO;
        case TIPO_PSIQUICO: return MAGENTA;
        case TIPO_NOTURNO: return CINZA;
        default: return RESET;
    }
}

// Função para obter nome do tipo
const char* getNomeTipo(int tipo) {
    switch(tipo) {
        case TIPO_FOGO: return "Fogo";
        case TIPO_AGUA: return "Água";
        case TIPO_PLANTA: return "Planta";
        case TIPO_ELETRICO: return "Elétrico";
        case TIPO_GELO: return "Gelo";
        case TIPO_LUTADOR: return "Lutador";
        case TIPO_VOADOR: return "Voador";
        case TIPO_PSIQUICO: return "Psíquico";
        case TIPO_NOTURNO: return "Noturno";
        default: return "Desconhecido";
    }
}

// Função para exibir barra de HP
void mostrarBarraHP(int atual, int total) {
    int porcentagem = (atual * 100) / total;
    int barras = (atual * 20) / total;
    if (barras < 0) barras = 0;
    if (barras > 20) barras = 20;
    
    printf("[");
    const char* cor;
    if (porcentagem > 50) cor = VERDE;
    else if (porcentagem > 25) cor = AMARELO;
    else cor = VERMELHO;
    
    printf("%s", cor);
    for(int i = 0; i < barras; i++) printf("#");
    printf(RESET);
    for(int i = barras; i < 20; i++) printf("-");
    printf("] %d/%d HP", atual, total);
}

// Função para limpar tela 
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para pausar
void pausar() {
    printf("\n%sPressione ENTER para continuar...%s", CINZA, RESET);
    getchar();
    getchar();
}

// Função para ler inteiro com validação
int lerInteiro(const char* mensagem) {
    int valor;
    int resultado;
    while(1) {
        resultado = scanf("%d", &valor);
        if(resultado == 1) {
            // Limpar buffer
            while(getchar() != '\n');
            return valor;
        } else {
            // Entrada invalida, limpar buffer
            while(getchar() != '\n');
            printf("%sEntrada invalida! Digite um numero: %s", VERMELHO, RESET);
        }
    }
}

int ataquep (int nivelp, int tipo1){
    int atq;
    switch(tipo1) {
        case TIPO_FOGO: atq = nivelp*2 + 7; break;      // Fogo: alto ataque
        case TIPO_AGUA: atq = nivelp*2 + 4; break;       // Água: ataque médio
        case TIPO_PLANTA: atq = nivelp*2 + 2; break;     // Planta: ataque baixo
        case TIPO_ELETRICO: atq = nivelp*2 + 8; break;   // Elétrico: ataque muito alto
        case TIPO_GELO: atq = nivelp*2 + 6; break;       // Gelo: ataque alto
        case TIPO_LUTADOR: atq = nivelp*2 + 9; break;    // Lutador: ataque altíssimo
        case TIPO_VOADOR: atq = nivelp*2 + 5; break;     // Voador: ataque médio-alto
        case TIPO_PSIQUICO: atq = nivelp*2 + 7; break;   // Psíquico: ataque alto
        case TIPO_NOTURNO: atq = nivelp*2 + 6; break;    // Noturno: ataque alto
        default: atq = nivelp*2 + 5; break;
    }
    return atq;
}
int ataquer(int nivelr,int tipo2){
    int atq;
    switch(tipo2) {
        case TIPO_FOGO: atq = nivelr*2 + 7; break;
        case TIPO_AGUA: atq = nivelr*2 + 4; break;
        case TIPO_PLANTA: atq = nivelr*2 + 2; break;
        case TIPO_ELETRICO: atq = nivelr*2 + 8; break;
        case TIPO_GELO: atq = nivelr*2 + 6; break;
        case TIPO_LUTADOR: atq = nivelr*2 + 9; break;
        case TIPO_VOADOR: atq = nivelr*2 + 5; break;
        case TIPO_PSIQUICO: atq = nivelr*2 + 7; break;
        case TIPO_NOTURNO: atq = nivelr*2 + 6; break;
        default: atq = nivelr*2 + 5; break;
    }
    return atq;
}
int defesap(int nivelp, int tipo1){
    int def;
    switch(tipo1) {
        case TIPO_FOGO: def = trunc(nivelp*1.5 + 5); break;      // Fogo: defesa baixa
        case TIPO_AGUA: def = nivelp*2 + 5; break;                // Água: defesa média
        case TIPO_PLANTA: def = trunc(nivelp*2.5 + 5); break;    // Planta: defesa alta
        case TIPO_ELETRICO: def = trunc(nivelp*1.3 + 5); break;  // Elétrico: defesa baixa
        case TIPO_GELO: def = nivelp*2 + 4; break;                // Gelo: defesa média
        case TIPO_LUTADOR: def = trunc(nivelp*1.8 + 6); break;   // Lutador: defesa média-baixa
        case TIPO_VOADOR: def = trunc(nivelp*1.6 + 5); break;    // Voador: defesa baixa
        case TIPO_PSIQUICO: def = nivelp*2 + 6; break;            // Psíquico: defesa média
        case TIPO_NOTURNO: def = trunc(nivelp*2.2 + 6); break;   // Noturno: defesa média-alta
        default: def = nivelp*2 + 5; break;
    }
    return def;
}
int defesar(int nivelr, int tipo2){
    int def;
    switch(tipo2) {
        case TIPO_FOGO: def = trunc(nivelr*1.5 + 5); break;
        case TIPO_AGUA: def = nivelr*2 + 5; break;
        case TIPO_PLANTA: def = trunc(nivelr*2.5 + 5); break;
        case TIPO_ELETRICO: def = trunc(nivelr*1.3 + 5); break;
        case TIPO_GELO: def = nivelr*2 + 4; break;
        case TIPO_LUTADOR: def = trunc(nivelr*1.8 + 6); break;
        case TIPO_VOADOR: def = trunc(nivelr*1.6 + 5); break;
        case TIPO_PSIQUICO: def = nivelr*2 + 6; break;
        case TIPO_NOTURNO: def = trunc(nivelr*2.2 + 6); break;
        default: def = nivelr*2 + 5; break;
    }
    return def;
}
int saudep(int nivelp, int tipo1){
    int vida;
    switch(tipo1) {
        case TIPO_FOGO: vida = nivelp*2 + 9; break;       // Fogo: HP médio
        case TIPO_AGUA: vida = nivelp*2 + 12; break;      // Água: HP alto
        case TIPO_PLANTA: vida = nivelp*2 + 10; break;    // Planta: HP médio-alto
        case TIPO_ELETRICO: vida = nivelp*2 + 8; break;   // Elétrico: HP baixo
        case TIPO_GELO: vida = nivelp*2 + 9; break;       // Gelo: HP médio
        case TIPO_LUTADOR: vida = nivelp*2 + 11; break;   // Lutador: HP alto
        case TIPO_VOADOR: vida = nivelp*2 + 9; break;     // Voador: HP médio
        case TIPO_PSIQUICO: vida = nivelp*2 + 10; break;  // Psíquico: HP médio-alto
        case TIPO_NOTURNO: vida = nivelp*2 + 11; break;   // Noturno: HP alto
        default: vida = nivelp*2 + 10; break;
    }
    return vida;
}
int sauder(int nivelr, int tipo2){
    int vida;
    switch(tipo2) {
        case TIPO_FOGO: vida = nivelr*2 + 9; break;
        case TIPO_AGUA: vida = nivelr*2 + 12; break;
        case TIPO_PLANTA: vida = nivelr*2 + 10; break;
        case TIPO_ELETRICO: vida = nivelr*2 + 8; break;
        case TIPO_GELO: vida = nivelr*2 + 9; break;
        case TIPO_LUTADOR: vida = nivelr*2 + 11; break;
        case TIPO_VOADOR: vida = nivelr*2 + 9; break;
        case TIPO_PSIQUICO: vida = nivelr*2 + 10; break;
        case TIPO_NOTURNO: vida = nivelr*2 + 11; break;
        default: vida = nivelr*2 + 10; break;
    }
    return vida;
}
int velocidadep(int nivelp, int tipo1){
    int vel;
    switch(tipo1) {
        case TIPO_FOGO: vel = nivelp*2 + 6; break;             // Fogo: velocidade alta
        case TIPO_AGUA: vel = trunc(nivelp*1.5 + 6); break;    // Água: velocidade média-baixa
        case TIPO_PLANTA: vel = nivelp*2 + 4; break;           // Planta: velocidade média
        case TIPO_ELETRICO: vel = nivelp*2 + 9; break;         // Elétrico: velocidade altíssima
        case TIPO_GELO: vel = trunc(nivelp*1.6 + 5); break;    // Gelo: velocidade média-baixa
        case TIPO_LUTADOR: vel = nivelp*2 + 5; break;          // Lutador: velocidade média
        case TIPO_VOADOR: vel = nivelp*2 + 8; break;           // Voador: velocidade muito alta
        case TIPO_PSIQUICO: vel = nivelp*2 + 7; break;         // Psíquico: velocidade alta
        case TIPO_NOTURNO: vel = nivelp*2 + 6; break;          // Noturno: velocidade alta
        default: vel = nivelp*2 + 5; break;
    }
    return vel;
}
int velocidader(int nivelr, int tipo2){
    int vel;
    switch(tipo2) {
        case TIPO_FOGO: vel = nivelr*2 + 6; break;
        case TIPO_AGUA: vel = trunc(nivelr*1.5 + 6); break;
        case TIPO_PLANTA: vel = nivelr*2 + 4; break;
        case TIPO_ELETRICO: vel = nivelr*2 + 9; break;
        case TIPO_GELO: vel = trunc(nivelr*1.6 + 5); break;
        case TIPO_LUTADOR: vel = nivelr*2 + 5; break;
        case TIPO_VOADOR: vel = nivelr*2 + 8; break;
        case TIPO_PSIQUICO: vel = nivelr*2 + 7; break;
        case TIPO_NOTURNO: vel = nivelr*2 + 6; break;
        default: vel = nivelr*2 + 5; break;
    }
    return vel;
}
int fraquezap(int tipo1, int tipo2){
    // Retorna 1 se tipo1 é fraco contra tipo2
    if(tipo1 == TIPO_FOGO && (tipo2 == TIPO_AGUA || tipo2 == TIPO_GELO)) return 1;
    if(tipo1 == TIPO_AGUA && (tipo2 == TIPO_PLANTA || tipo2 == TIPO_ELETRICO)) return 1;
    if(tipo1 == TIPO_PLANTA && (tipo2 == TIPO_FOGO || tipo2 == TIPO_GELO || tipo2 == TIPO_VOADOR)) return 1;
    if(tipo1 == TIPO_ELETRICO && tipo2 == TIPO_PLANTA) return 1;
    if(tipo1 == TIPO_GELO && (tipo2 == TIPO_FOGO || tipo2 == TIPO_LUTADOR)) return 1;
    if(tipo1 == TIPO_LUTADOR && (tipo2 == TIPO_VOADOR || tipo2 == TIPO_PSIQUICO)) return 1;
    if(tipo1 == TIPO_VOADOR && (tipo2 == TIPO_ELETRICO || tipo2 == TIPO_GELO)) return 1;
    if(tipo1 == TIPO_PSIQUICO && tipo2 == TIPO_NOTURNO) return 1;
    if(tipo1 == TIPO_NOTURNO && (tipo2 == TIPO_LUTADOR || tipo2 == TIPO_PSIQUICO)) return 1;
    return 0;
}
int resistenciap(int tipo1, int tipo2){
    // Retorna 1 se tipo1 resiste a tipo2
    if(tipo1 == TIPO_FOGO && (tipo2 == TIPO_PLANTA || tipo2 == TIPO_GELO)) return 1;
    if(tipo1 == TIPO_AGUA && (tipo2 == TIPO_FOGO || tipo2 == TIPO_GELO)) return 1;
    if(tipo1 == TIPO_PLANTA && (tipo2 == TIPO_AGUA || tipo2 == TIPO_ELETRICO)) return 1;
    if(tipo1 == TIPO_ELETRICO && (tipo2 == TIPO_VOADOR || tipo2 == TIPO_ELETRICO)) return 1;
    if(tipo1 == TIPO_GELO && tipo2 == TIPO_GELO) return 1;
    if(tipo1 == TIPO_LUTADOR && tipo2 == TIPO_NOTURNO) return 1;
    if(tipo1 == TIPO_VOADOR && (tipo2 == TIPO_PLANTA || tipo2 == TIPO_LUTADOR)) return 1;
    if(tipo1 == TIPO_PSIQUICO && tipo2 == TIPO_LUTADOR) return 1;
    if(tipo1 == TIPO_NOTURNO && tipo2 == TIPO_PSIQUICO) return 1;
    return 0;
}
int fraquezar(int tipo2, int tipo1){
    // Retorna 1 se tipo2 é fraco contra tipo1
    if(tipo2 == TIPO_FOGO && (tipo1 == TIPO_AGUA || tipo1 == TIPO_GELO)) return 1;
    if(tipo2 == TIPO_AGUA && (tipo1 == TIPO_PLANTA || tipo1 == TIPO_ELETRICO)) return 1;
    if(tipo2 == TIPO_PLANTA && (tipo1 == TIPO_FOGO || tipo1 == TIPO_GELO || tipo1 == TIPO_VOADOR)) return 1;
    if(tipo2 == TIPO_ELETRICO && tipo1 == TIPO_PLANTA) return 1;
    if(tipo2 == TIPO_GELO && (tipo1 == TIPO_FOGO || tipo1 == TIPO_LUTADOR)) return 1;
    if(tipo2 == TIPO_LUTADOR && (tipo1 == TIPO_VOADOR || tipo1 == TIPO_PSIQUICO)) return 1;
    if(tipo2 == TIPO_VOADOR && (tipo1 == TIPO_ELETRICO || tipo1 == TIPO_GELO)) return 1;
    if(tipo2 == TIPO_PSIQUICO && tipo1 == TIPO_NOTURNO) return 1;
    if(tipo2 == TIPO_NOTURNO && (tipo1 == TIPO_LUTADOR || tipo1 == TIPO_PSIQUICO)) return 1;
    return 0;
}
int resistenciar(int tipo2, int tipo1){
    // Retorna 1 se tipo2 resiste a tipo1
    if(tipo2 == TIPO_FOGO && (tipo1 == TIPO_PLANTA || tipo1 == TIPO_GELO)) return 1;
    if(tipo2 == TIPO_AGUA && (tipo1 == TIPO_FOGO || tipo1 == TIPO_GELO)) return 1;
    if(tipo2 == TIPO_PLANTA && (tipo1 == TIPO_AGUA || tipo1 == TIPO_ELETRICO)) return 1;
    if(tipo2 == TIPO_ELETRICO && (tipo1 == TIPO_VOADOR || tipo1 == TIPO_ELETRICO)) return 1;
    if(tipo2 == TIPO_GELO && tipo1 == TIPO_GELO) return 1;
    if(tipo2 == TIPO_LUTADOR && tipo1 == TIPO_NOTURNO) return 1;
    if(tipo2 == TIPO_VOADOR && (tipo1 == TIPO_PLANTA || tipo1 == TIPO_LUTADOR)) return 1;
    if(tipo2 == TIPO_PSIQUICO && tipo1 == TIPO_LUTADOR) return 1;
    if(tipo2 == TIPO_NOTURNO && tipo1 == TIPO_PSIQUICO) return 1;
    return 0;
}
int experienciar(int nivelp, int nivelr){
    int exp;
    if (nivelp>nivelr){
        exp=nivelr*5;
    }
    else if(nivelp==nivelr){
        exp=nivelr*3;
    }
    else{
        exp=nivelr*2;
    }
    return exp;
}
int experienciap(int nivelr, int nivelp){
    int exp;
    if (nivelr>nivelp){
        exp=nivelp*5;
    }
    else if(nivelr==nivelp){
        exp=nivelp*3;
    }
    else{
        exp=nivelp*2;
    }
    return exp;
}
int main (){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char nome1[20];
    int nivelp;
    int tipo1;
    char nome2[20];
    int nivelr;
    int tipo2;
    int t=1;
    int saudetotalp, saudetotalr, sauderestantep, sauderestanter;
    
    limparTela();
    printf("\n");
    printf("%s===============================================================%s\n", AMARELO, RESET);
    printf("%s          BATALHA POKEMON - SISTEMA DE COMBATE                %s\n", AMARELO, RESET);
    printf("%s===============================================================%s\n\n", AMARELO, RESET);
    
    printf("%sQual o nome do seu parceiro?%s\n", VERDE, RESET);
    printf("   -> ");
    scanf("%s", nome1);
    
    printf("\n%sQual o nivel do seu parceiro?%s\n", VERDE, RESET);
    printf("   -> ");
    nivelp = lerInteiro("");
    while(nivelp < 1 || nivelp > 100) {
        printf("%sNivel deve ser entre 1 e 100: %s", VERMELHO, RESET);
        nivelp = lerInteiro("");
    }
    
    printf("\n%sEscolha o tipo do seu parceiro:%s\n", VERDE, RESET);
    printf("   %s1-Fogo%s      %s2-Agua%s       %s3-Planta%s\n", 
           VERMELHO, RESET, AZUL, RESET, VERDE, RESET);
    printf("   %s4-Eletrico%s  %s5-Gelo%s       %s6-Lutador%s\n", 
           AMARELO, RESET, CIANO, RESET, LARANJA, RESET);
    printf("   %s7-Voador%s    %s8-Psiquico%s   %s9-Noturno%s\n", 
           BRANCO, RESET, MAGENTA, RESET, CINZA, RESET);
    printf("   -> ");
    tipo1 = lerInteiro("");
    while(tipo1 < 1 || tipo1 > 9) {
        printf("%sTipo deve ser entre 1 e 9: %s", VERMELHO, RESET);
        tipo1 = lerInteiro("");
    }
    
    printf("\n%s===============================================================%s\n\n", CINZA, RESET);
    
    printf("%sQual o nome do seu rival?%s\n", VERMELHO, RESET);
    printf("   -> ");
    scanf("%s", nome2);
    
    printf("\n%sQual o nivel do seu rival?%s\n", VERMELHO, RESET);
    printf("   -> ");
    nivelr = lerInteiro("");
    while(nivelr < 1 || nivelr > 100) {
        printf("%sNivel deve ser entre 1 e 100: %s", VERMELHO, RESET);
        nivelr = lerInteiro("");
    }
    
    printf("\n%sEscolha o tipo do seu rival:%s\n", VERMELHO, RESET);
    printf("   %s1-Fogo%s      %s2-Agua%s       %s3-Planta%s\n", 
           VERMELHO, RESET, AZUL, RESET, VERDE, RESET);
    printf("   %s4-Eletrico%s  %s5-Gelo%s       %s6-Lutador%s\n", 
           AMARELO, RESET, CIANO, RESET, LARANJA, RESET);
    printf("   %s7-Voador%s    %s8-Psiquico%s   %s9-Noturno%s\n", 
           BRANCO, RESET, MAGENTA, RESET, CINZA, RESET);
    printf("   -> ");
    tipo2 = lerInteiro("");
    while(tipo2 < 1 || tipo2 > 9) {
        printf("%sTipo deve ser entre 1 e 9: %s", VERMELHO, RESET);
        tipo2 = lerInteiro("");
    }
    saudetotalp=saudep(nivelp, tipo1);
    saudetotalr=sauder(nivelr, tipo2);
    sauderestantep=saudetotalp;
    sauderestanter=saudetotalr;
    
    limparTela();
    printf("\n%s===============================================================%s\n", VERDE, RESET);
    printf("%s                  STATUS DOS POKEMON                           %s\n", VERDE, RESET);
    printf("%s===============================================================%s\n\n", VERDE, RESET);
    
    printf("%s+----------------------------------+%s\n", getCor(tipo1), RESET);
    printf("%s| %s%-15s%s [Tipo: %s%-10s%s] |%s\n", 
           getCor(tipo1), BRANCO, nome1, getCor(tipo1), 
           getCor(tipo1), getNomeTipo(tipo1), getCor(tipo1), RESET);
    printf("%s+----------------------------------+%s\n", getCor(tipo1), RESET);
    printf("%s|%s  HP:          %3d              %s|%s\n", 
           getCor(tipo1), RESET, saudep(nivelp, tipo1), getCor(tipo1), RESET);
    printf("%s|%s  Ataque:      %3d              %s|%s\n", 
           getCor(tipo1), RESET, ataquep(nivelp, tipo1), getCor(tipo1), RESET);
    printf("%s|%s  Defesa:      %3d              %s|%s\n", 
           getCor(tipo1), RESET, defesap(nivelp, tipo1), getCor(tipo1), RESET);
    printf("%s|%s  Velocidade:  %3d              %s|%s\n", 
           getCor(tipo1), RESET, velocidadep(nivelp, tipo1), getCor(tipo1), RESET);
    printf("%s+----------------------------------+%s\n\n", getCor(tipo1), RESET);
    
    printf("%s                    VS%s\n\n", AMARELO, RESET);
    
    printf("%s+----------------------------------+%s\n", getCor(tipo2), RESET);
    printf("%s| %s%-15s%s [Tipo: %s%-10s%s] |%s\n", 
           getCor(tipo2), BRANCO, nome2, getCor(tipo2), 
           getCor(tipo2), getNomeTipo(tipo2), getCor(tipo2), RESET);
    printf("%s+----------------------------------+%s\n", getCor(tipo2), RESET);
    printf("%s|%s  HP:          %3d              %s|%s\n", 
           getCor(tipo2), RESET, sauder(nivelr, tipo2), getCor(tipo2), RESET);
    printf("%s|%s  Ataque:      %3d              %s|%s\n", 
           getCor(tipo2), RESET, ataquer(nivelr, tipo2), getCor(tipo2), RESET);
    printf("%s|%s  Defesa:      %3d              %s|%s\n", 
           getCor(tipo2), RESET, defesar(nivelr, tipo2), getCor(tipo2), RESET);
    printf("%s|%s  Velocidade:  %3d              %s|%s\n", 
           getCor(tipo2), RESET, velocidader(nivelr, tipo2), getCor(tipo2), RESET);
    printf("%s+----------------------------------+%s\n\n", getCor(tipo2), RESET);
    
    printf("%s===============================================================%s\n", AMARELO, RESET);
    printf("%s            QUE COMECE A BATALHA! BOA SORTE!                  %s\n", AMARELO, RESET);
    printf("%s===============================================================%s\n\n", AMARELO, RESET);
    pausar();
    while(1){
        limparTela();
        printf("\n%s===============================================================%s\n", CIANO, RESET);
        printf("%s                        TURNO %2d                              %s\n", CIANO, t, RESET);
        printf("%s===============================================================%s\n\n", CIANO, RESET);
        t++;
        
        printf("%s%s%s (Nivel %d - Tipo %s)\n", getCor(tipo1), nome1, RESET, nivelp, getNomeTipo(tipo1));
        printf("   ");
        mostrarBarraHP(sauderestantep, saudetotalp);
        printf("\n\n%s                         VS%s\n\n", AMARELO, RESET);
        printf("%s%s%s (Nivel %d - Tipo %s)\n", getCor(tipo2), nome2, RESET, nivelr, getNomeTipo(tipo2));
        printf("   ");
        mostrarBarraHP(sauderestanter, saudetotalr);
        printf("\n\n%s---------------------------------------------------------------%s\n\n", CINZA, RESET);
        if(velocidadep(nivelp, tipo1)>velocidader(nivelr, tipo2)){
            int danop, danor;
            danop=ataquep(nivelp, tipo1)-defesar(nivelr, tipo2);
            if (danop<=0){
                danop=3;
            }
            if (fraquezar(tipo2, tipo1)==1){
                danop=danop*2;
                printf("%s>> SUPER EFETIVO! %s", VERDE, RESET);
            }
            else if(resistenciar(tipo2, tipo1)==1){
                danop=danop/2;
                printf("%s>> Nao muito efetivo... %s", CINZA, RESET);
            }
            int chance1= rand() % 20 +1;
            if(chance1==2){
                danop=danop*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s%s%s atacou e causou %s%d de dano%s em %s%s%s!\n", 
                   getCor(tipo1), nome1, RESET, VERMELHO, danop, RESET, getCor(tipo2), nome2, RESET);
            sauderestanter=sauderestanter-danop;
            if(sauderestanter<=0){
                sauderestanter=0;
                printf("\n%s===============================================================%s\n", AMARELO, RESET);
                printf("%s                   FIM DA BATALHA!                            %s\n", AMARELO, RESET);
                printf("%s===============================================================%s\n\n", AMARELO, RESET);
                printf("%s%s foi derrotado!%s\n", getCor(tipo2), nome2, RESET);
                printf("%s*** %s e o VENCEDOR! ***%s\n\n", VERDE, nome1, RESET);
                printf("%s ganhou %d de experiência!\n", nome1, experienciap(nivelp, nivelr));
                break;
            }
            printf("\n");
            danor=ataquer(nivelr, tipo2)-defesap(nivelp,tipo1);
            if (danor<=0){
                danor=3;
            }
            if(fraquezap(tipo1, tipo2)==1){
                danor=danor*2;
                printf("%s>> SUPER EFETIVO! %s", VERDE, RESET);
            }
            else if(resistenciap(tipo1, tipo2)==1){
                danor=danor/2;
                printf("%s>> Nao muito efetivo... %s", CINZA, RESET);
            }
            int chance2= rand() % 20 +1;
            if(chance2==2){
                danor=danor*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s%s%s atacou e causou %s%d de dano%s em %s%s%s!\n", 
                   getCor(tipo2), nome2, RESET, VERMELHO, danor, RESET, getCor(tipo1), nome1, RESET);
            sauderestantep=sauderestantep-danor;
            if (sauderestantep<=0){
                sauderestantep=0;
                printf("\n%s===============================================================%s\n", AMARELO, RESET);
                printf("%s                   FIM DA BATALHA!                            %s\n", AMARELO, RESET);
                printf("%s===============================================================%s\n\n", AMARELO, RESET);
                printf("%s%s foi derrotado!%s\n", getCor(tipo1), nome1, RESET);
                printf("%s*** %s e o VENCEDOR! ***%s\n\n", VERDE, nome2, RESET);
                printf("%s ganhou %d de experiência!\n", nome2, experienciar(nivelp, nivelr));
                break;
            }
            printf("\n%sPressione ENTER para continuar...%s", CINZA, RESET);
            getchar();
            getchar();
        }
        else{
            // Rival ataca primeiro (mais rápido)
            int danop, danor;
            danor=ataquer(nivelr, tipo2)-defesap(nivelp,tipo1);
            if (danor<=0){
                danor=3;
            }
            if(fraquezap(tipo1, tipo2)==1){
                danor=danor*2;
                printf("%s>> SUPER EFETIVO! %s", VERDE, RESET);
            }
            else if(resistenciap(tipo1, tipo2)==1){
                danor=danor/2;
                printf("%s>> Nao muito efetivo... %s", CINZA, RESET);
            }
            int chance3= rand() % 20 +1;
            if(chance3==2){
                danor=danor*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s%s%s atacou e causou %s%d de dano%s em %s%s%s!\n", 
                   getCor(tipo2), nome2, RESET, VERMELHO, danor, RESET, getCor(tipo1), nome1, RESET);
            sauderestantep=sauderestantep-danor;
            if(sauderestantep<=0){
                sauderestantep=0;
                printf("\n%s===============================================================%s\n", AMARELO, RESET);
                printf("%s                   FIM DA BATALHA!                            %s\n", AMARELO, RESET);
                printf("%s===============================================================%s\n\n", AMARELO, RESET);
                printf("%s%s foi derrotado!%s\n", getCor(tipo1), nome1, RESET);
                printf("%s*** %s e o VENCEDOR! ***%s\n\n", VERDE, nome2, RESET);
                printf("%s ganhou %d de experiência!\n", nome2, experienciar(nivelp, nivelr));
                break;
            }
            printf("\n");
            
            // Parceiro contra-ataca
            danop=ataquep(nivelp, tipo1)-defesar(nivelr, tipo2);
            if (danop<=0){
                danop=3;
            }
            if(fraquezar(tipo2, tipo1)==1){
                danop=danop*2;
                printf("%s>> SUPER EFETIVO! %s", VERDE, RESET);
            }
            else if(resistenciar(tipo2, tipo1)==1){
                danop=danop/2;
                printf("%s>> Nao muito efetivo... %s", CINZA, RESET);
            }
            int chance4= rand() % 20 +1;
            if(chance4==2){
                danop=danop*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s%s%s atacou e causou %s%d de dano%s em %s%s%s!\n", 
                   getCor(tipo1), nome1, RESET, VERMELHO, danop, RESET, getCor(tipo2), nome2, RESET);
            sauderestanter=sauderestanter-danop;
            if (sauderestanter<=0){
                sauderestanter=0;
                printf("\n%s===============================================================%s\n", AMARELO, RESET);
                printf("%s                   FIM DA BATALHA!                            %s\n", AMARELO, RESET);
                printf("%s===============================================================%s\n\n", AMARELO, RESET);
                printf("%s%s foi derrotado!%s\n", getCor(tipo2), nome2, RESET);
                printf("%s*** %s e o VENCEDOR! ***%s\n\n", VERDE, nome1, RESET);
                printf("%s ganhou %d de experiência!\n", nome1, experienciap(nivelp, nivelr));
                break;
            }
            printf("\n%sPressione ENTER para continuar...%s", CINZA, RESET);
            getchar();
            getchar();
        }
    }
}
