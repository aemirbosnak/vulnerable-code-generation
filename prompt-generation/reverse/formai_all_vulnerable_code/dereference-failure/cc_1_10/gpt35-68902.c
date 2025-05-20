//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c);

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else {
                int substitution_cost = (str1[i-1] != str2[j-1]);
                matrix[i][j] = min(matrix[i-1][j] + 1,   // deletion
                                   matrix[i][j-1] + 1,   // insertion
                                   matrix[i-1][j-1] + substitution_cost);  // substitution
            }
        }
    }
    return matrix[len1][len2];
}

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please provide two strings to compare.\n");
        return 1;
    }

    char *str1 = argv[1];
    char *str2 = argv[2];
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);

    return 0;
}