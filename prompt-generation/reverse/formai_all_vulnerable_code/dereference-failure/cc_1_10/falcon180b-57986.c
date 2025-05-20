//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

int levenshtein_distance(char* str1, char* str2, int len1, int len2) {
    int i, j, k, cost, **matrix;

    // Allocate memory for the matrix
    matrix = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (len2 + 1));
    }

    // Initialize the first row and column of the matrix
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                cost = 1;
                for (k = 0; k < i; k++) {
                    if (str1[k] == str2[j-1]) {
                        cost = 0;
                        break;
                    }
                }
                for (k = 0; k < j; k++) {
                    if (str1[i-1] == str2[k]) {
                        cost = 0;
                        break;
                    }
                }
                matrix[i][j] = matrix[i-1][j] + cost;
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[] = "apocalyptic";
    char str2[] = "post-apocalyptic";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}