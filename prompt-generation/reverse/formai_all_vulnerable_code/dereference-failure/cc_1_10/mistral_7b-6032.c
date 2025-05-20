//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

typedef struct {
    int len;
    char *s;
} str;

int levenshtein_distance(char *s1, char *s2, int n, int m) {
    int matrix[n + 1][m + 1];
    int i, j, cost;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = (s1[i - 1] == s2[j]) ? 1 : 2;
                matrix[i][j] = MIN(MIN(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + cost;
            }
        }
    }

    return matrix[n][m];
}

str read_str(char *prompt) {
    char *line = NULL;
    size_t len = 0;
    str s;

    printf("%s", prompt);
    getline(&line, &len, stdin);

    s.len = strlen(line);
    s.s = (char *)malloc(s.len * sizeof(char));
    strcpy(s.s, line);

    free(line);

    return s;
}

int main(void) {
    char *str1, *str2;
    int distance;
    str s1, s2;

    s1 = read_str("Enter first string: ");
    s2 = read_str("Enter second string: ");

    distance = levenshtein_distance(s1.s, s2.s, s1.len, s2.len);

    printf("Levenshtein Distance: %d\n", distance);

    free(s1.s);
    free(s2.s);

    return 0;
}