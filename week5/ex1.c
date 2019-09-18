#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *PrintHello(int i)
{
    printf("Hello from thread %d - I was created in iteration %d !\n", (int)pthread_self(), i);
    pthread_exit(0);
}

int main()
{
    int n, rc;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        pthread_t thread;
        int id = i;
        rc = pthread_create(&thread, NULL, PrintHello, i);
        if (rc)
        {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }

        pthread_join(thread, NULL);
        printf("I am thread %d. Created new thread (%d) in iteration %d ...\n",
               (int)pthread_self(), &thread, i);
        printf("Thread %d finished.\n\n",(int)pthread_self() );
    }
    return 0;
}