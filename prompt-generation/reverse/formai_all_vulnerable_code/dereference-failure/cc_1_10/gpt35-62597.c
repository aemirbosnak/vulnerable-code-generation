//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function calculates the Levenshtein distance between two strings.
 * It returns the minimum number of single-character edits (insertions, deletions, or
 * substitutions) required to change one string into the other.
 */
int levenshtein_distance(const char *s1, const char *s2)
{
    // Determine the length of each string
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to hold the distances between all possible substrings
    int **distances = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++)
    {
        distances[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    // Initialize the first row and first column of the array
    for (int i = 0; i <= len1; i++)
    {
        distances[i][0] = i;
    }
    for (int j = 0; j <= len2; j++)
    {
        distances[0][j] = j;
    }

    // Fill in the rest of the array
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                distances[i][j] = distances[i - 1][j - 1];
            }
            else
            {
                int substitution = distances[i - 1][j - 1] + 1;
                int insertion = distances[i][j - 1] + 1;
                int deletion = distances[i - 1][j] + 1;
                distances[i][j] = substitution < insertion ? (substitution < deletion ? substitution : deletion) : (insertion < deletion ? insertion : deletion);
            }
        }
    }

    // Store the final result and free the dynamically allocated 2D array
    int result = distances[len1][len2];
    for (int i = 0; i <= len1; i++)
    {
        free(distances[i]);
    }
    free(distances);

    return result;
}

int main()
{
    char str1[] = "Levenshtein";
    char str2[] = "Levenstein";

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, levenshtein_distance(str1, str2));

    return 0;
}