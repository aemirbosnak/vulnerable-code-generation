//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    int cost[MAX_LENGTH][MAX_LENGTH];
} matrix;

void levenshtein_distance(char str1[MAX_LENGTH], char str2[MAX_LENGTH], matrix *matrix) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len1; i++)
        matrix->cost[i][0] = i;

    for (int j = 0; j <= len2; j++)
        matrix->cost[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                matrix->cost[i][j] = matrix->cost[i - 1][j - 1];
            else
                matrix->cost[i][j] = 1 + min(
                    matrix->cost[i - 1][j],
                    matrix->cost[i][j - 1],
                    matrix->cost[i - 1][j - 1]
                );
        }
    }
}

int min(int x, int y, int z) {
    if (x < y) {
        if (x < z)
            return x;
        else
            return z;
    } else {
        if (y < z)
            return y;
        else
            return z;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char str1[MAX_LENGTH] = {0};
    char str2[MAX_LENGTH] = {0};
    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    matrix matrix;
    levenshtein_distance(str1, str2, &matrix);

    printf("Levenshtein Distance: %d\n", matrix.cost[strlen(str1)][strlen(str2)]);

    return 0;
}