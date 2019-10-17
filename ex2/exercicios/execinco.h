// /*Faça um programa que crie uma seqüência de processos de tal
// forma que o 1o da série crie o 2o, o 2o crie o 3o e o 3o crie o
// 4o. Cada processo deve escrever o seu PID e o PID do
// processo-pai.*/

//FEITO_______________________________________________

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void cinco()
{
    int i;
    pid_t pid;


    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    for (i=0; i<4; i++)
    {
      if (pid == 0)
      {
          printf("pid do Filho: %d\n", getpid());
      }
      else
      {
          printf("pid do Pai: %d\n", getpid());
      }
    }

    exit(0);
}