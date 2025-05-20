//Gemma-7B DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to read data from a file
int readData(char *filename, int **arr, int *size)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    int fsize = ftell(fp);
    rewind(fp);

    // Allocate memory for the array
    *arr = (int *)malloc(fsize * sizeof(int));
    *size = fsize;

    // Read the data from the file
    int i = 0;
    while (fscanf(fp, "%d ", &(*arr)[i]) != EOF)
    {
        i++;
    }

    fclose(fp);
    return 0;
}

// Define a function to find the maximum value in an array
int findMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    // Read data from a file
    int *arr;
    int size;
    readData("data.txt", &arr, &size);

    // Find the maximum value in the array
    int max = findMax(arr, size);

    // Print the maximum value
    printf("The maximum value in the array is: %d\n", max);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}