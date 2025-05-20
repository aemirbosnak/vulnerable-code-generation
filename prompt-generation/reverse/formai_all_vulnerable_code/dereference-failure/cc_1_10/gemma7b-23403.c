//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foobar(int argc, char **argv)
{
    int i, j, k, l;
    char **ptr = NULL;
    char *buf = NULL;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <num_rows> <num_cols>\n", argv[0]);
        exit(1);
    }

    i = atoi(argv[1]);
    j = atoi(argv[2]);

    buf = malloc(i * j * sizeof(char));
    if (buf == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }

    ptr = malloc((i + 1) * sizeof(char *));
    if (ptr == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }

    for (k = 0; k <= i; k++)
    {
        ptr[k] = malloc((j + 1) * sizeof(char));
        if (ptr[k] == NULL)
        {
            fprintf(stderr, "Error allocating memory.\n");
            exit(1);
        }
    }

    for (l = 0; l < i; l++)
    {
        for (k = 0; k < j; k++)
        {
            buf[l * j + k] = 'a' + l + k;
        }
    }

    for (k = 0; k <= i; k++)
    {
        for (l = 0; l < j; l++)
        {
            printf("%c ", ptr[k][l]);
        }
        printf("\n");
    }

    free(buf);
    free(ptr);
}

int main(int argc, char **argv)
{
    foobar(argc, argv);

    return 0;
}