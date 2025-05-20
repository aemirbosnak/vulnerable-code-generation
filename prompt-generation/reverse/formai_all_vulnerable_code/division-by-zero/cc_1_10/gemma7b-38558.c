//Gemma-7B DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1024

int main()
{
    // Define an array of strings
    char **arr = NULL;
    int size = 0;

    // Allocate memory for the array
    arr = malloc(MAX * sizeof(char *));

    // Get the number of strings from the user
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Allocate memory for each string
    for (int i = 0; i < n; i++)
    {
        arr[i] = malloc(MAX * sizeof(char));
    }

    // Get the strings from the user
    for (int i = 0; i < n; i++)
    {
        printf("Enter the string: ");
        scanf("%s", arr[i]);
    }

    // Calculate the average length of the strings
    int total_length = 0;
    for (int i = 0; i < n; i++)
    {
        total_length += strlen(arr[i]);
    }

    // Calculate the average length
    int average_length = total_length / n;

    // Print the average length
    printf("The average length of the strings is: %d", average_length);

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}