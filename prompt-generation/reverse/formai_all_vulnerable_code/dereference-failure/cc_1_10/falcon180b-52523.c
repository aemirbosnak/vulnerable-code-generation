//Falcon-180B DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void my_error(char *message)
{
    perror(message);
    exit(1);
}

int main(int argc, char *argv[])
{
    FILE *file;
    char filename[100];
    int i, j, n;

    if (argc!= 3)
    {
        my_error("Incorrect number of arguments");
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL)
    {
        my_error("Could not open file");
    }

    fseek(file, 0L, SEEK_END);
    n = ftell(file);
    rewind(file);

    int *array = (int *) malloc(n * sizeof(int));

    if (array == NULL)
    {
        my_error("Could not allocate memory");
    }

    for (i = 0; i < n; i++)
    {
        if (fscanf(file, "%d", &array[i])!= 1)
        {
            my_error("Invalid input");
        }
    }

    fclose(file);

    int sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                my_error("Duplicate values");
            }
        }
        sum += array[i];
    }

    printf("Sum: %d\n", sum);

    free(array);

    return 0;
}