
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
    const unsigned int size = 10 *1024*1024;
    for (int i = 0; i < 10; i++)
    {
        char *s = malloc(sizeof(char) * size);
        memset(s, 0, sizeof(char) * size);
        sleep(1);
    }
}