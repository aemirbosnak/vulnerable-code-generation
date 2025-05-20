//Gemma-7B DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to read data from a file
void readData(char *filename, int **arr, int *size)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s", filename);
        exit(1);
    }

    // Get the size of the file
    fseek(fp, 0, SEEK_END);
    *size = ftell(fp) / sizeof(int);

    // Allocate memory for the array
    *arr = (int *)malloc((*size) * sizeof(int));

    // Read the data from the file
    rewind(fp);
    fread(*arr, sizeof(int), *size, fp);

    fclose(fp);
}

// Define a function to find the mean of a list of numbers
double findMean(int *arr, int size)
{
    int i;
    double sum = 0.0;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Define a function to find the standard deviation of a list of numbers
double findStdDev(int *arr, int size)
{
    double mean = findMean(arr, size);
    int i;
    double sum = 0.0;

    for (i = 0; i < size; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }

    return sqrt(sum / size);
}

int main()
{
    int *arr;
    int size;
    readData("data.txt", &arr, &size);
    double mean = findMean(arr, size);
    double stdDev = findStdDev(arr, size);
    printf("The mean of the data is: %.2f\n", mean);
    printf("The standard deviation of the data is: %.2f\n", stdDev);

    free(arr);
    return 0;
}