
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

void main()
{
    const unsigned int size = 10 * 1024 * 1024;
    struct rusage *usage=malloc(sizeof(struct rusage));
    for (int i = 0; i < 10; i++)
    {
        char *s = malloc(sizeof(char) * size);
        memset(s, 0, sizeof(char) * size);
        getrusage(RUSAGE_SELF, usage);
        printf("Memory usage: %ld\n", usage->ru_maxrss);
        fflush(stdin);
        sleep(1);
    }
}