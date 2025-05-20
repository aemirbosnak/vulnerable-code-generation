//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings
#define MAX_LENGTH 100

// Define the cost of insertion, deletion, and substitution
#define COST_INSERT 1
#define COST_DELETE 1
#define COST_SUBSTITUTE 1

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    // Create a matrix to store the distances
    int matrix[MAX_LENGTH][MAX_LENGTH];

    // Initialize the first row and column of the matrix
    for (int i = 0; i < strlen(s1) + 1; i++) {
        matrix[i][0] = i * COST_INSERT;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        matrix[0][j] = j * COST_DELETE;
    }

    // Calculate the distances for the rest of the matrix
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + COST_INSERT, matrix[i][j - 1] + COST_DELETE), matrix[i - 1][j - 1] + COST_SUBSTITUTE);
            }
        }
    }

    // Return the distance
    return matrix[strlen(s1)][strlen(s2)];
}

// Get the minimum of three integers
int fmin(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Print the usage information
void usage(char *program_name) {
    printf("Usage: %s <string1> <string2>\n", program_name);
    printf("Calculates the Levenshtein distance between two strings.\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    // Get the two strings
    char *s1 = argv[1];
    char *s2 = argv[2];

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}