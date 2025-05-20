//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshteinDistance(char *s1, int len1, char *s2, int len2)
{
    int **matrix;
    int i, j, dist;
    matrix = (int**) malloc((len1+1) * sizeof(int *));
    for (i = 0; i <= len1; i++) matrix[i] = (int*) malloc((len2+1) * sizeof(int));
    for (i = 0; i <= len1; i++) matrix[i][0] = i;
    for (j = 0; j <= len2; j++) matrix[0][j] = j;

    for (j = 1; j <= len2; j++)
    {
        for (i = 1; i <= len1; i++)
        {
            if (s1[i-1] == s2[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = minimum(matrix[i-1][j]+1,
                                        matrix[i][j-1]+1,
                                        matrix[i-1][j-1]+1);
            }
        }
    }

    dist = matrix[len1][len2];
    for (i = 0; i <= len1; i++) free(matrix[i]);
    free(matrix);
    return dist;
}

int main()
{
    char *s1 = "kitten";
    char *s2 = "sitting";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist = levenshteinDistance(s1, len1, s2, len2);
    printf("The Levenshtein Distance between %s and %s is: %d\n", s1, s2, dist);
    return 0;
}