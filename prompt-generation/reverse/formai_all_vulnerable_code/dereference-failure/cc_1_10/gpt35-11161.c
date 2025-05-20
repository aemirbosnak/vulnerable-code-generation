//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void exitWithError(char *errorMessage) {
    printf("ERROR: %s\n", errorMessage);
    exit(1);
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int calculateLevenshteinDistance(char *stringA, char *stringB) {
    int lenA = strlen(stringA);
    int lenB = strlen(stringB);
    int matrix[MAX_LENGTH][MAX_LENGTH];

    // initialize the matrix
    for (int i = 0; i <= lenA; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= lenB; j++) {
        matrix[0][j] = j;
    }

    // populate the matrix
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            int substitutionCost = (stringA[i-1] == stringB[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1, 
                               matrix[i][j-1] + 1, 
                               matrix[i-1][j-1] + substitutionCost);
        }
    }

    // return the final value in the bottom right corner of the matrix
    return matrix[lenA][lenB];
}

int main(int argc, char **argv) {
    if (argc != 3) {
        exitWithError("Please enter two strings as arguments");
    }

    char *stringA = argv[1];
    char *stringB = argv[2];

    int distance = calculateLevenshteinDistance(stringA, stringB);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", stringA, stringB, distance);

    // no need to be paranoid anymore - program ran successfully!
    return 0;
}