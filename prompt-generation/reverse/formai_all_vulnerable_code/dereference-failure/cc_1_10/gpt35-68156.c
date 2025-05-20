//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int **matrix = (int**) malloc((len1 + 1) * sizeof(int*)); // creating a two-dimensional array
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*) malloc((len2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1,
                               matrix[i - 1][j - 1] + cost);
        }
    }
    int result = matrix[len1][len2];
    for (int i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);
    return result;
}

int main() {
    char *s1, *s2;
    s1 = (char*) malloc(50 * sizeof(char));
    s2 = (char*) malloc(50 * sizeof(char));
    printf("Enter the first string:\n");
    fgets(s1, 50, stdin);
    printf("Enter the second string:\n");
    fgets(s2, 50, stdin);

    // removing the newline character
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    free(s1);
    free(s2);
    return 0;
}