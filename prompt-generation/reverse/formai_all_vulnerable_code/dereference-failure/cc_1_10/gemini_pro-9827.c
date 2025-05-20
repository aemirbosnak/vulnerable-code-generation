//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int levenshtein_distance(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    int **matrix = malloc((s1_len + 1) * sizeof(int *));
    for (int i = 0; i <= s1_len; i++) {
        matrix[i] = malloc((s2_len + 1) * sizeof(int));
    }

    for (int i = 0; i <= s1_len; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= s2_len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            int a = matrix[i - 1][j] + 1;
            int b = matrix[i][j - 1] + 1;
            int c = matrix[i - 1][j - 1] + cost;
            matrix[i][j] = MIN(MIN(a, b), c);
        }
    }

    int result = matrix[s1_len][s2_len];

    for (int i = 0; i <= s1_len; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}