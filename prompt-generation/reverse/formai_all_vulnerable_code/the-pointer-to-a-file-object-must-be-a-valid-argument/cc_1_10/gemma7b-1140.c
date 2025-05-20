//Gemma-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char **arr = NULL;
    int i, j, n, m;
    FILE *fp;

    // Open the file
    fp = fopen("love.txt", "r");

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));

    // Read the file and store the data in the array
    n = 0;
    while (!feof(fp))
    {
        arr[n] = (char *)malloc(MAX * sizeof(char));
        fgets(arr[n], MAX, fp);
        n++;
    }

    // Close the file
    fclose(fp);

    // Analyze the array
    for (i = 0; i < n; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            // Count the number of vowels in the word
            int vowels = 0;
            char *word = arr[i][j];
            char ch;

            for (m = 0; word[m] != '\0'; m++)
            {
                ch = word[m];
                if (ch >= 'a' && ch <= 'z')
                {
                    vowels++;
                }
            }

            // Print the word and the number of vowels
            printf("%s has %d vowels.\n", word, vowels);
        }
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}