//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for valid input
    if (argc != 3)
    {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the input strings
    char *str1 = argv[1];
    char *str2 = argv[2];

    // Get the lengths of the input strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a matrix to store the Levenshtein distances
    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column of the matrix to the lengths of the input strings
    for (int i = 0; i <= len1; i++)
    {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++)
    {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distances
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, min(matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost));
        }
    }

    // Print the Levenshtein distance
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, matrix[len1][len2]);

    return EXIT_SUCCESS;
}

int min(int a, int b, int c)
{
    if (a < b)
    {
        if (a < c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b < c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}