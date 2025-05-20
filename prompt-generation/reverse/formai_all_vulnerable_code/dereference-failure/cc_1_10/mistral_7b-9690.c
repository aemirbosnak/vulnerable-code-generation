//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128
#define WIDTH 32
#define HEIGHT 32

char str1[MAX_CHAR], str2[MAX_CHAR];
int matrix[WIDTH][HEIGHT];

void initMatrix() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            matrix[j][i] = i;
        }
    }

    matrix[0][0] = 0;
}

void levenshteinDistance(int len1, int len2) {
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        matrix[0][i] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[j][0] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = 1 + min(
                matrix[i - 1][j],
                matrix[i][j - 1],
                matrix[i - 1][j - 1] + cost
            );
        }
    }
}

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

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    initMatrix();
    levenshteinDistance(strlen(str1), strlen(str2));

    printf("Levenshtein Distance: %d\n", matrix[strlen(str1)][strlen(str2)]);

    return 0;
}