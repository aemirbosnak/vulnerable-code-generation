//Gemma-7B DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to extract data from a text file
void extractData(char *filename, int **arr, int *size)
{
    FILE *fp;
    char line[1024];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    *size = 0;
    while (fgets(line, 1024, fp) != NULL)
    {
        char *token = strtok(line, ",");
        while (token)
        {
            arr[i++] = atoi(token);
            token = strtok(NULL, ",");
        }
        *size++;
    }

    fclose(fp);
}

int main()
{
    int *arr = NULL;
    int size = 0;
    extractData("data.txt", &arr, &size);

    printf("The extracted data is:");
    for (int i = 0; i < size; i++)
    {
        printf(", %d", arr[i]);
    }

    printf("\nThe number of extracted data items is: %d", size);

    free(arr);

    return 0;
}