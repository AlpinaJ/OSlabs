#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle(int s)
{
    printf("\n:). Stop me with ctrl+Z\n");
}

int main()
{
    signal(SIGINT, handle);
    int i = 1;
    while (1)
    {
        sleep(1);
        printf("i == %d\n", i);
        fflush(stdin);
        i++;
    }
    return 0;
}