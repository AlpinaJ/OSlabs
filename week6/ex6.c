
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int pipe_arr[2];
int state = -1;
void main()
{
    pipe(pipe_arr);

    int pid1 = fork();
    int pid2;
    if (pid1 != 0)
        pid2 = fork();

    if (pid1 != 0 && pid2 != 0){
        write(pipe_arr[1], &pid2, sizeof(int));
        waitpid(pid1,&state,0);
        printf("Everything is done.\n");
    }

    if(pid2==0){
        while(1){
            sleep(1);
            printf("Child2 is alive\n");
        }
    }

    if (pid1==0)
    {
        sleep(2);
        read(pipe_arr[0], &pid2, sizeof(int));
        sleep(2);
        kill(pid2,SIGSTOP);
        printf("Child2 stopped by Child1\n");
        sleep(2);
        kill(pid2,SIGCONT);
        printf("Child2 is contuniued by Child1\n");
        sleep(2);
        kill(pid2,SIGKILL);
        printf("Child1 killed Child2\n");
        exit(0);
    }    
}