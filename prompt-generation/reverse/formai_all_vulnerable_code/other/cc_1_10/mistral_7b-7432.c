//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to calculate the Levenshtein Distance
int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];
    int i, j, cost;

    // Initialize matrix with distances
    for (i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= length1; i++) {
        for (j = 1; j <= length2; j++) {
            cost = (tolower(str1[i - 1]) == tolower(str2[j - 1])) ? 0 : 1;
            matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[length1][length2];
}

int main(int argc, char *argv[]) {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1, length2;

    // Input two strings
    printf("String 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("String 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Calculate the Levenshtein Distance
    length1 = strlen(str1);
    length2 = strlen(str2);
    int distance = levenshtein_distance(str1, str2, length1, length2);

    // Print the result
    printf("Levenshtein Distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}

// Helper function to find the minimum of three integers
int min(int x, int y, int z) {
    return ((x <= y) && (x <= z)) ? x : ((y <= x && y <= z) ? y : z);
}