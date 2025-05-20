//Gemma-7B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    int i = 0, j = 0, n = 0, k = 0;

    // Reading data from a text file
    FILE *fp = fopen("data.txt", "r");
    if (fp)
    {
        // Allocating memory dynamically for each line in the text file
        while (getline(fp, arr[n], MAX) != NULL)
        {
            n++;
        }

        // Closing the file
        fclose(fp);
    }

    // Creating a 2D array to store the data
    arr = (char **)realloc(arr, n * sizeof(char *));

    // Processing the data
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            // Counting the occurrences of each character
            k = 0;
            for (int l = 0; arr[i][l] != '\0'; l++)
            {
                if (arr[i][l] == arr[i][j])
                {
                    k++;
                }
            }

            // Storing the character and its count in the 2D array
            arr[i][j] = k;
        }
    }

    // Printing the results
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            printf("%c: %d ", arr[i][j], arr[i][j]);
        }
        printf("\n");
    }

    // Freeing the memory
    free(arr);

    return 0;
}