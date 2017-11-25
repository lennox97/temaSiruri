#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 10000 //numarul de caractere din fisierul de intrare

int main(int argc, char *argv[]){
    int c, i=0;//variabile 
    char *s0;//sirul de caractere citit din fisier
    char *s1;//sirul citit de la tastatura
    FILE *fin;//pointer catre fisierul de intrare

    if(argc==1) {//verific daca s-a introdus un fisier
        perror("Nu ati introdus fisierul de intrare in linia de comanda!\n");
        exit(1);
    }
    
    fin = fopen(argv[1], "r"); // deschid fisierul primit ca parametru in linia de comanda
    if(!fin){
        perror("Eroare la deschiderea fisierului de intrare!\n");
        exit(1);
    }

    //aloc dinamic cate caractere are sirul citit pentru al salva
    s0 = malloc(N * sizeof(char));
    
    //citesc caracter cu caracter din fisier si salvez in s0
    while((c=fgetc(fin)) != EOF)
       s0[i++] = c;

    fclose(fin); //inchid fisierul de intrare

    //citesc de la tastatura sirul s1 retinand doar caracterele neduplicate
    s1 = malloc(2*sizeof(char));
    s1[0] = fgetc(stdin);
    i = 1;
    while((c=fgetc(stdin)) != '\n')
        if(s1[i-1] != c) //daca c nu se afla la pozitia anterioara atunci il salvez
        {
            s1 = realloc(s1, strlen(s1) * sizeof(char));
            s1[i++] = c; 
        }

    s1[strlen(s1)-1] = '\0';
    
    puts(s1);
    free(s0);//eliberez zona de memorie
    return 0;
}
