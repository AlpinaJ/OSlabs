#include <stdio.h>
#include <unistd.h>
#include <string.h>

int data[2];
int size[2];

int main()
{

    pipe(size);
    pipe(data);

    char word[] = "Some text";
    int word_size = strlen(word) + 1;

    write(size[1], &word_size, sizeof(int));
    write(data[1], word, word_size);

    char buffer[255];
    unsigned int data_size = 0;

    read(size[0], &data_size, sizeof(unsigned int));
    printf("received data_size = %d\n", data_size);

    read(data[0], &buffer[0], data_size);
    printf("word = '%s'\n", buffer);

    return 0;
}