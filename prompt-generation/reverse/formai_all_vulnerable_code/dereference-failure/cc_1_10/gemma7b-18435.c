//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

void compress(char **buf, int *size)
{
    int i, j, k, count = 0, prev = -1, run_length = 0;
    char **new_buf = NULL;

    *size = 0;

    for (i = 0; i < MAX_SIZE && buf[i] != '\0'; i++)
    {
        if (prev == buf[i])
        {
            run_length++;
        }
        else
        {
            if (run_length > 0)
            {
                new_buf = realloc(new_buf, (*size) * sizeof(char *) + sizeof(int));
                new_buf[*size] = (char *)malloc(run_length * sizeof(char));
                memcpy(new_buf[*size], buf, run_length * sizeof(char));
                (*size)++;
            }
            prev = buf[i];
            run_length = 1;
        }
    }

    if (run_length > 0)
    {
        new_buf = realloc(new_buf, (*size) * sizeof(char *) + sizeof(int));
        new_buf[*size] = (char *)malloc(run_length * sizeof(char));
        memcpy(new_buf[*size], buf, run_length * sizeof(char));
        (*size)++;
    }

    free(buf);
    buf = new_buf;
}

int main()
{
    char *buf = "This is a string to be compressed.";
    int size = 0;

    compress(&buf, &size);

    printf("Compressed size: %d\n", size);

    printf("Compressed string: %s\n", buf);

    free(buf);

    return 0;
}