//Gemma-7B DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int ret = 0;
    char *ptr = NULL;

    ret = malloc_s(10, ptr);
    if (ret != 0)
    {
        err_handle("malloc_s() failed!", errno);
    }

    ret = strcpy_s(ptr, "Hello, world!");
    if (ret != 0)
    {
        err_handle("strcpy_s() failed!", errno);
    }

    printf("%s\n", ptr);

    free_s(ptr);

    return 0;
}

int err_handle(const char *msg, int errnum)
{
    fprintf(stderr, "Error: %s, Errno: %d\n", msg, errnum);
    exit(1);
}

int malloc_s(size_t size, void **ptr)
{
    *ptr = malloc(size);
    if (*ptr == NULL)
    {
        return -1;
    }
    return 0;
}

int strcpy_s(void *dest, const void *src)
{
    int ret = strcpy(dest, src);
    if (ret != 0)
    {
        return -1;
    }
    return 0;
}

int free_s(void *ptr)
{
    free(ptr);
    return 0;
}