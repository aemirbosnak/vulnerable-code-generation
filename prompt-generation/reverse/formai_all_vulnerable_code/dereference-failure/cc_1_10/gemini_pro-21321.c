//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

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

int levenshtein(const char *s1, const char *s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    matrix_t m = {
        .rows = s1len + 1,
        .cols = s2len + 1,
        .matrix = malloc(sizeof(int *) * (s1len + 1)),
    };
    for (int i = 0; i < s1len + 1; i++) {
        m.matrix[i] = malloc(sizeof(int) * (s2len + 1));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < s1len + 1; i++) {
        m.matrix[i][0] = i;
    }
    for (int j = 0; j < s2len + 1; j++) {
        m.matrix[0][j] = j;
    }

    // Compute the rest of the matrix.
    for (int i = 1; i < s1len + 1; i++) {
        for (int j = 1; j < s2len + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                m.matrix[i][j] = m.matrix[i - 1][j - 1];
            } else {
                m.matrix[i][j] = min(
                    m.matrix[i - 1][j],    // Insertion
                    m.matrix[i][j - 1],    // Deletion
                    m.matrix[i - 1][j - 1] // Substitution
                ) + 1;
            }
        }
    }

    return m.matrix[s1len][s2len];
}

int main() {
    char *s1 = "Hello";
    char *s2 = "World";
    int distance = levenshtein(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
    return 0;
}