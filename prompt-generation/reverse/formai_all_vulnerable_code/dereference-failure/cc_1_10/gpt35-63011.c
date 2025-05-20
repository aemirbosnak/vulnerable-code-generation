//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the minimum of 3 integers
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

// function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);

    // allocate memory for the dynamic programming matrix
    int **d = (int **) malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        d[i] = (int *) malloc(sizeof(int) * (m + 1));
    }

    // initialize first row and column
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    // calculate the Levenshtein distance
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int cost = (s[i-1] == t[j-1]) ? 0 : 1;
            d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + cost);
        }
    }

    // store the Levenshtein distance and free the memory
    int distance = d[n][m];
    for (int i = 0; i <= n; i++) {
        free(d[i]);
    }
    free(d);

    // return the Levenshtein distance
    return distance;
}

int main() {
    char *s1 = "Hello, world!";
    char *s2 = "Hola, mundo!";
    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);
    return 0;
}