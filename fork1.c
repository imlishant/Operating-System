#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    
    /* fork a child process */
    pid = fork();
    if (pid < 0){   /*error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0){     /*child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else{       /*parent process */
        /*parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete");
    }
    
    return 0;
}

/* OUTPUT

s_fe04_eebb_e91d_15a9.c
s_fe04_eebb_e91d_15a9.c.out
Child Complete

*/
