//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char *s1, char *s2, int len1, int len2) {
    int i, j, cost;
    int **matrix;
    int *prev;

    matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));
        for (j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }

    prev = (int *) malloc(sizeof(int) * (len2 + 1));
    for (i = 0; i <= len2; i++) {
        prev[i] = i;
    }

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 1; j <= len2; j++) {
        cost = 1;
        for (i = 0; i <= len1; i++) {
            if (s1[i] == s2[j - 1]) {
                matrix[i + 1][j] = matrix[i][j - 1];
            } else {
                matrix[i + 1][j] = matrix[i][j - 1] + cost;
            }
            cost++;
        }
    }

    return matrix[len1][len2];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    int len1, len2;

    printf("Enter string 1: ");
    scanf("%s", s1);
    len1 = strlen(s1);

    printf("Enter string 2: ");
    scanf("%s", s2);
    len2 = strlen(s2);

    int distance = levenshtein_distance(s1, s2, len1, len2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}