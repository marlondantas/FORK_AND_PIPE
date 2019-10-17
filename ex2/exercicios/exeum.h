#include <stdio.h> 
#include <unistd.h>
#include <sys/types.h> 

// FEITO_______________________________________________

void forxmain1() 
{ 
    if (fork() == 0) {
        printf("Eu sou o Filho! "); 
        printf("O MEU PID: %ld O PId do meu pai: %ld \n", (long)getpid(), (long)getppid());
    }
    else
    {
        printf("Eu sou o Pai! "); 
        printf("O meu PID: %ld \n", (long)getpid());
    }
} 
