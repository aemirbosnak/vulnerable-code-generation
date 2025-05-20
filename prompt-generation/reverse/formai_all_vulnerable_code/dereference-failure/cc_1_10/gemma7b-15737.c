//Gemma-7B DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **data = NULL;
    int i, j, k, l, size = 0;

    // Allocate memory for the data matrix
    data = (char **)malloc(MAX * sizeof(char *));
    for (i = 0; i < MAX; i++)
    {
        data[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Read the data from the file
    FILE *fp = fopen("data.txt", "r");
    if (fp)
    {
        // Get the number of lines in the file
        k = 0;
        while (!feof(fp))
        {
            getline(data[k], MAX, fp);
            k++;
        }

        // Calculate the size of the data matrix
        size = k;

        // Close the file
        fclose(fp);
    }

    // Print the data
    for (i = 0; i < size; i++)
    {
        for (j = 0; data[i][j] != '\0'; j++)
        {
            printf("%c ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}