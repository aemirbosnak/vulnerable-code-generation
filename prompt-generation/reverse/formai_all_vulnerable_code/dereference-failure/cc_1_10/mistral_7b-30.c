//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    int length1 = strlen(argv[1]);
    int length2 = strlen(argv[2]);

    if (length1 > MAX_LENGTH || length2 > MAX_LENGTH) {
        printf("Strings too long.\n");
        return 1;
    }

    int distance = levenshtein_distance(argv[1], argv[2], length1, length2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", argv[1], argv[2], distance);

    return 0;
}

int levenshtein_distance(const char *string1, const char *string2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];

    for (int i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            int cost = (string1[i - 1] == string2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,
                              matrix[i][j - 1] + 1,
                              matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[length1][length2];
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}