//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Helper function to calculate the cost of a single edit
int edit_cost(char c1, char c2) {
    if (c1 == c2) {
        return 0;
    }
    else if (isupper(c1)) {
        return 1;
    }
    else if (islower(c1)) {
        return 1;
    }
    else if (isdigit(c1)) {
        return 1;
    }
    else {
        return 2;
    }
}

// Main function to calculate Levenshtein distance
int levenshtein_distance(const char* s1, const char* s2) {
    // Allocate memory for the matrices
    int* matrix1 = (int*)malloc(sizeof(int) * (strlen(s1) + 1));
    int* matrix2 = (int*)malloc(sizeof(int) * (strlen(s2) + 1));

    // Initialize the first row and column of both matrices to 0
    for (int i = 0; i <= strlen(s1); i++) {
        matrix1[i] = i;
        matrix2[i] = i;
    }

    // Fill the rest of the matrix by iterating over the characters in s1 and s2
    for (int i = 1; i <= strlen(s1); i++) {
        for (int j = 1; j <= strlen(s2); j++) {
            // If the characters match, the cost is 0
            if (s1[i-1] == s2[j-1]) {
                matrix1[i] = matrix1[i-1];
                matrix2[j] = matrix2[j-1];
            }
            else {
                // Calculate the cost of inserting, deleting, or replacing a character
                matrix1[i] = matrix1[i-1] + edit_cost(s1[i-1], s2[j-1]);
                matrix2[j] = matrix2[j-1] + edit_cost(s1[i-1], s2[j-1]);
            }
        }
    }

    // The last row and column of both matrices contain the final distances
    int distance = matrix1[strlen(s1)] + 1;
    free(matrix1);
    free(matrix2);

    return distance;
}

int main() {
    const char* s1 = "kitten";
    const char* s2 = "sitting";

    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}