//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **distance = (int **) malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        distance[i] = (int *) malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_s2; j++) {
        distance[0][j] = j; // Insertion
    }

    // Calculate the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,  // Deletion
                                 distance[i][j - 1] + 1,  // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to print the results
void printResult(const char *s1, const char *s2, int distance) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

// Main function to run the program
int main() {
    char *str1 = NULL;
    char *str2 = NULL;
    
    // Allocate buffers for input strings
    str1 = (char *) malloc(256 * sizeof(char));
    str2 = (char *) malloc(256 * sizeof(char));

    // Get user input
    printf("Enter the first string: ");
    fgets(str1, 256, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    printf("Enter the second string: ");
    fgets(str2, 256, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character

    // Calculate the distance
    int distance = levenshteinDistance(str1, str2);

    // Print the result
    printResult(str1, str2, distance);

    // Free allocated memory for input strings
    free(str1);
    free(str2);

    return 0;
}