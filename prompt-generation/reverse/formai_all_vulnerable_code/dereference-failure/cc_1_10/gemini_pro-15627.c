//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    int **d = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
        d[i] = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= m; i++)
        d[i][0] = i;

    for (int j = 0; j <= n; j++)
        d[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    int result = d[m][n];

    for (int i = 0; i <= m; i++)
        free(d[i]);

    free(d);

    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return -1;
    }

    char *str1 = argv[1];
    char *str2 = argv[2];

    int distance = levenshtein(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}