/*Faça um programa onde o processo pai escreva dados em um
arquivo e o processo filho faça a leitura e imprima na tela*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int exetres(void){
    int i;
    int c = 1234567890;
    pid_t pid;

    FILE *fp;
    fp = fopen("text.txt", "w+");

    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if (fork() != 0)
    {
      fprintf(fp, "This is testing for fprintf...\n");
    }
    else
    {
      fputs("This is testing for fputs...\n", fp);
      fclose(fp);
    }
    exit(0);
}