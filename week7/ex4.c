#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, int size)
{
    void *nptr = malloc(size);
    if (nptr == NULL)
    {
        malloc(size);
        return nptr;
    }
    else if (size == 0)
    {
        free(ptr);
        return nptr;
    }
    memcpy(nptr, ptr, size);

    free(ptr);
    return nptr;
}

void main()
{
}