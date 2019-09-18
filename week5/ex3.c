#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;

void *producer_thread()
{
    printf("Producer thread started\n");

    while (1)
    {

        if (count == 10)
        {
            printf("Producer fall asleep\n");
            sleep(3);
            printf("Producer awake\n");
        }
        else
        {
            count++;
        }
    }

    pthread_exit(0);
}

void *consumer_thread()
{
    printf("Consumer thread started\n");

    while (1)
    {
        if (count == 0)
        {
            printf("Consumer fall asleep\n");
            sleep(3);
            printf("Consumer awake\n");
        }
        else
        {
            count--;
        }
    }
    pthread_exit(0);
}



int main()
{
    pthread_t thread_prod, thread_cons;
    int ret_prod = pthread_create(&thread_prod, NULL, producer_thread, 0);
    int ret_cons = pthread_create(&thread_cons, NULL, consumer_thread, 1);

    pthread_join(thread_cons, NULL);
    pthread_join(thread_prod, NULL);

    return 0;
}