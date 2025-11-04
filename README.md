# ads-egsw-Vinicius-Ruza-Wellington-Mendes
Esse projeto irá simular uma batalha Pokémon em que o usuário escolhe o nível, tipo e nome dos Pokémon participantes
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int ataquep (int nivelp, int tipo1){
    int status1, status2, atq;
    if (tipo1==1){
        atq=nivelp*2+7; 
    }
    else if(tipo1==2){
        atq=nivelp*2+4;
    }
    else {
        atq=nivelp*2+2;
    }
    return atq;
}
int ataquer(int nivelr,int tipo2){
    int atq;
    if(tipo2==1){
        atq=nivelr*2+7; 
    }
    else if(tipo2==2){
        atq=nivelr*2+4;
    }
    else {
        atq=nivelr*2+2;
    }
    return atq;
}
int defesap(int nivelp, int tipo1){
    int def;
    if(tipo1==1){
        def=nivelp*1.5+5;
        def=trunc(def);
    }
    else if(tipo1==2){
        def=nivelp*2+5;
    }
    else{
        def=nivelp*2.5+5;
        def=trunc(def);
    }
    return def;
}
int defesar(int nivelr, int tipo2){
    int def;
    if(tipo2==1){
        def=nivelr*1.5+5;
        def=trunc(def);
    }
    else if(tipo2==2){
        def=nivelr*2+5;
    }
    else{
        def=nivelr*2.5+5;
        def=trunc(def);
    }
    return def;
}
int saudep(int nivelp, int tipo1){
    int vida;
    if(tipo1==1){
        vida=nivelp*2+9;
    }
    else if(tipo1==2){
        vida=nivelp*2+12;
    }
    else{
        vida=nivelp*2+10;
    }
    return vida;
}
int sauder(int nivelr, int tipo2){
    int vida;
    if(tipo2==1){
        vida=nivelr*2+9;
    }
    else if(tipo2==2){
        vida=nivelr*2+12;
    }
    else{
        vida=nivelr*2+10;
    }
    return vida;
}
int velocidadep(int nivelp, int tipo1){
    int vel;
    if (tipo1==1){
        vel=nivelp*2+6;
    }
    else if (tipo1==2){
        vel=nivelp*1.5+6;
        vel=trunc(vel);
    }
    else {
        vel=nivelp*2+4;
    }
    return vel;
}
int velocidader(int nivelr, int tipo2){
    int vel;
    if (tipo2==1){
        vel=nivelr*2+6;
    }
    else if (tipo2==2){
        vel=nivelr*1.5+6;
        vel=trunc(vel);
    }
    else {
        vel=nivelr*2+4;
    }
    return vel;
}
int fraquezap(int tipo1, int tipo2){
    int fraqueza;
    if(tipo1==1 && tipo2==2){
        fraqueza=1;
    }
    else if(tipo1==2 && tipo2==3){
        fraqueza=1;
    }
    else if(tipo1==3 && tipo2==1){
        fraqueza=1;
    }
    else{
        fraqueza=0;
    }
    return fraqueza;
}
int resistenciap(int tipo1, int tipo2){
    int resistencia;
    if(tipo1==1 && tipo2==3){
        resistencia=1;
    }
    else if(tipo1==2 && tipo2==1){
        resistencia=1;
    }
    else if (tipo1==3 && tipo2==2){
        resistencia=1;
    }
    else{
        resistencia=0;
    }
    return resistencia;
}
int fraquezar(int tipo2, int tipo1){
    int fraqueza;
    if (tipo2==1 && tipo1==2){
        fraqueza=1;
    }
    else if (tipo2==2 && tipo1==3){
        fraqueza=1;
    }
    else if (tipo2==3 && tipo1==1){
        fraqueza=1;
    }
    else{
        fraqueza=0;
    }
    return fraqueza;
}
int resistenciar(int tipo2, int tipo1){
    int resistencia;
    if(tipo2==1 && tipo1==3){
        resistencia=1;
    }
    else if(tipo2==2 && tipo1==1){
        resistencia=1;;
    }
    else if(tipo2==3 && tipo1==2){
        resistencia=1;
    }
    else{
        resistencia=0;
    }
    return resistencia;
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
    int velep, veler;
    int saudetotalp, saudetotalr, sauderestantep, sauderestanter;
    srand(time(NULL));
    printf("Qual o nome do seu parceiro?\n");
    scanf("%s", nome1);
    printf("Qual o nível do seu parceiro?\n");
    scanf("%d", &nivelp);
    printf("Seu parceiro é um pokemon do tipo:\n");
    printf("1-Fogo 2-Água 3-Planta\n");
    scanf("%d", &tipo1);
    printf("Qual o nome do seu rival?\n");
    scanf("%s", nome2);
    printf("Qual o nível do seu rival?\n");
    scanf("%d", &nivelr);
    printf("Seu rival é um pokemon do tipo:\n");
    printf("1-Fogo 2-Agua 3-Planta\n");
    scanf("%d", &tipo2);
    /* calcular velocidades APÓS ler nível e tipo */

    saudetotalp=saudep(nivelp, tipo1);
    saudetotalr=sauder(nivelr, tipo2);
    sauderestantep=saudetotalp;
    sauderestanter=saudetotalr;
    printf("Status do %s:\n", nome1);
    printf("Saúde: %d\n", saudep(nivelp, tipo1));
    printf("Ataque: %d\n", ataquep(nivelp, tipo1));
    printf("Defesa: %d\n", defesap(nivelp, tipo1));
    printf("Velocidade: %d\n", velocidadep(nivelp, tipo1));
    printf("\n");
    printf("Status do %s: \n", nome2);
    printf("Saúde: %d\n", sauder(nivelr, tipo2));
    printf("Ataque: %d\n", ataquer(nivelr, tipo2));
    printf("Defesa: %d\n", defesar(nivelr, tipo2));
    printf("Velocidade: %d\n", velocidader(nivelr, tipo2));
    printf("\n");
    printf("Que comece a batalha! Boa sorte para os competidores!\n");
    velep = velocidadep(nivelp, tipo1);
    veler = velocidader(nivelr, tipo2);
    while(1){
        printf("Turno %d\n", t);
        t++;
        printf("%s %d/%d vs %s %d/%d\n", nome1, sauderestantep, saudetotalp, nome2, sauderestanter, saudetotalr);
        if(velep>veler){
            int danop, danor;
            danop=ataquep(nivelp, tipo1)-defesar(nivelr, tipo2);
            if (danop<=0){
                danop=3;
            }
            if (fraquezar(tipo2, tipo1)==1){
                danop=danop*2;
                printf("Ataque super efetivo! ");
            }
            else if(resistenciar(tipo2, tipo1)==1){
                danop=danop/2;
                printf("Ataque não muito efetivo...");
            }
            else{
                danop=danop;
            }
            int chance1= rand() % 20 +1;
            if(chance1==2){
                danop=danop*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s causou %d de dano em %s\n", nome1, danop, nome2);
            sauderestanter=sauderestanter-danop;
            if(sauderestanter<=0){
                printf("%s foi derrotado! %s é o vencedor!\n", nome2, nome1);
                break;
            }
            danor=ataquer(nivelr, tipo2)-defesap(nivelp,tipo1);
            if (danor<=0){
                danor=3;
            }
            if(fraquezap(tipo1, tipo2)==1){
                danor=danor*2;
                printf("Ataque super efetivo! ");
            }
            if(resistenciap(tipo1, tipo2)==1){
                danor=danor/2;
                printf("Ataque não é muito efetivo...");
            }
            int chance2= rand() % 20 +1;
            if(chance2==2){
                danor=danor*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s causou %d de dano em %s\n", nome2, danor, nome1);
            sauderestantep=sauderestantep-danor;
            if (sauderestantep<=0){
                printf("%s foi derrotado! %s é o vencedor!\n", nome2, nome1);
                break;
            }
        }
        else if(velep<veler){            
            int danop, danor;
            danor=ataquep(nivelp, tipo1)-defesar(nivelr, tipo2);
            if (danor<=0){
                danor=3;
            }
            if (fraquezar(tipo1, tipo2)==1){
                danor=danor*2;
                printf("Ataque super efetivo! ");
            }
            else if(resistenciar(tipo1, tipo2)==1){
                danop=danop/2;
                printf("Ataque não muito efetivo...");
            }
            else{
                danor=danor;
            }
            int chance3= rand() % 20 +1;
            if(chance3==2){
                danor=danor*3;
                printf("NOSSA! Um golpe crítico! ");
            }
            printf("%s causou %d de dano em %s\n", nome2, danor, nome1);
            sauderestantep=sauderestantep-danor;
            if(sauderestantep<=0){
                printf("%s foi derrotado! %s é o vencedor!\n", nome1, nome2);
                break;
            }
            danop=ataquep(nivelp, tipo1)-defesar(nivelr,tipo2);
            if (danop<=0){
                danop=3;
            }
            if(fraquezar(tipo2, tipo1)==1){
                danop=danop*2;
                printf("Ataque super efetivo! ");
            }
            if(resistenciar(tipo2, tipo1)==1){
                danop=danop/2;
                printf("Ataque não é muito efetivo...");
            }
            int chance4= rand() % 20 +1;
            if(chance4==2){
                danop=danop*3;
                printf("NOSSA! Um golpe c´ritico! ");
            }
            printf("%s causou %d de dano em %s\n", nome2, danor, nome1);
            sauderestantep=sauderestantep-danor;
            if (sauderestanter<=0){
                printf("%s foi derrotado! %s é o vencedor!\n", nome2, nome1);
                break;
            }
        }
        else{
            int chanvev=rand() % 2+1;
            if(chanvev==2){
                veler+=1;;
                printf("Deacordo com o desempate, %s atacará primeiro!\n", nome2);
            }
            else{
                velep+=1;
                printf("Deacordo com o desempate, %s atacará primeiro!\n", nome1);
            }

        }
    }
}
