//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x,y,z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))

int levenshtein_distance(char *s1, char *s2, int m, int n)
{
    int i, j, l1, l2;
    int **matrix = (int**) malloc(sizeof(int*) * (m+1));
    if (matrix == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <= m; ++i) {
        matrix[i] = (int*) malloc(sizeof(int) * (n+1));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Out of memory!\n");
            exit(EXIT_FAILURE);
        }
    }
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (i = 0; i <= l1; ++i)
        matrix[i][0] = i;
    for (i = 0; i <= l2; ++i)
        matrix[0][i] = i;
    for (i = 1; i <= l1; ++i) {
        for (j = 1; j <= l2; ++j) {
            if (s1[i-1] == s2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = MIN(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + 1);
        }
    }
    int result = matrix[l1][l2];
    for (i = 0; i <= m; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main(void)
{
    char word1[100], word2[100];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int max_len = len1 > len2 ? len1 : len2;
    printf("\nLevenshtein Distance between %s and %s is %d\n", word1, word2, levenshtein_distance(word1, word2, max_len, max_len));
    return 0;
}