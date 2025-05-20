//Gemma-7B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char **arr = NULL;
    int i = 0, j = 0, k = 0, n = 0, max_size = 10;

    // Allocate memory for the array
    arr = (char **)malloc(max_size * sizeof(char *));
    for (i = 0; i < max_size; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
    }

    // Get the number of lines in the text file
    FILE *fp = fopen("text.txt", "r");
    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        n++;
    }

    // Resize the array if necessary
    if (n > max_size)
    {
        max_size *= 2;
        arr = (char **)realloc(arr, max_size * sizeof(char *));
        for (i = max_size - 1; i < n; i++)
        {
            arr[i] = (char *)malloc(10 * sizeof(char));
        }
    }

    // Read the text file again and store it in the array
    fp = fopen("text.txt", "r");
    line[0] = '\0';
    while (fgets(line, 1024, fp) != NULL)
    {
        strcpy(arr[k], line);
        k++;
    }

    // Analyze the data
    for (i = 0; i < n; i++)
    {
        // Count the number of words in each line
        int num_words = 0;
        char *word = strtok(arr[i], " ");
        while (word)
        {
            num_words++;
            word = strtok(NULL, " ");
        }

        // Print the number of words in each line
        printf("Line %d: %d words\n", i + 1, num_words);
    }

    // Free the memory
    for (i = 0; i < max_size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}