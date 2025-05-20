//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);

    int **table = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i < (m + 1); i++) {
        table[i] = (int *)malloc(sizeof(int) * (n + 1));
    }

    for (int i = 0; i <= m; i++) {
        table[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        table[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int cost;
            if (toupper(s[i - 1]) == toupper(t[j - 1])) {
                cost = 0;
            } else {
                cost = 1;
            }
            table[i][j] = min(table[i - 1][j] + 1, table[i][j - 1] + 1, table[i - 1][j - 1] + cost);
        }
    }

    int distance = table[m][n];

    for (int i = 0; i < (m + 1); i++) {
        free(table[i]);
    }
    free(table);

    return distance;
}

int main() {
    char s[100], t[100];
    printf("Enter first string: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter second string: ");
    fgets(t, sizeof(t), stdin);
    printf("Levenshtein Distance between the two strings is %d\n", levenshtein(s, t));
    return 0;
}