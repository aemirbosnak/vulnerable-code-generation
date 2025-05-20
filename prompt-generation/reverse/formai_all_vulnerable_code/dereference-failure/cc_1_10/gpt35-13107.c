//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int cost;
            if (s[i - 1] == t[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    return d[m][n];
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s s t\n", argv[0]);
        exit(1);
    }

    char* s = argv[1];
    char* t = argv[2];

    printf("Levenshtein distance between %s and %s is %d\n", s, t, levenshtein(s, t));
    return 0;
}