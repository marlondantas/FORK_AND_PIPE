// /*Faça um programa que envie para um processo filho um valor
// e ele gere a seqüência de fibonacci até o número informado.
// Funções necessárias: fork, exit e wait.*/
#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h> 

int fib(int valor){
    int n=0;
    long long int fb=0,fb2=1;
    printf("0\n");
    while (n<valor)
    {
        fb= fb+fb2;
        fb2 = fb - fb2;
        printf("%lld\n", fb);
        n++;
    }
}

void pipeexemplo() 
{ 
	int fd[2];
  int VALOR;
  /* cria um pipe */

	if(pipe(fd)<0)
	{
		perror("pipe");
	}
	
  int pid = fork();


  if (pid == 0) {


    close(fd[1]);
	
		read(fd[0], &VALOR,sizeof(VALOR));
    
		printf("fibonacci");
		fib(VALOR);

		close(fd[0]);

    printf("Eu sou o Filho! "); 
    printf("O MEU PID: %ld O PID do meu pai: %ld \n", (long)getpid(), (long)getppid());
  }
  else
  {
    printf("Eu sou o Pai! "); 
    printf("O meu PID: %ld \n", (long)getpid());

    int qnt=0;

    printf("Insira um valor: ");
    scanf("%d", &qnt);

    close(fd[0]);
    
    write(fd[1],&qnt,sizeof(qnt));
    
    close(fd[1]);

    //
    wait(NULL); 

  }
} 
