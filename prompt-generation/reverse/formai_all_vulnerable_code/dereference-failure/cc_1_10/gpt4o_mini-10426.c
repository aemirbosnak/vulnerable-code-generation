//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (size_t i = 0; i <= len_s1; i++) {
        d[i][0] = i; // deletion
    }
    for (size_t j = 0; j <= len_s2; j++) {
        d[0][j] = j; // insertion
    }

    // Compute the distances
    for (size_t i = 1; i <= len_s1; i++) {
        for (size_t j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // deletion
                          d[i][j - 1] + 1,      // insertion
                          d[i - 1][j - 1] + cost); // substitution
        }
    }

    // Retrieve the distance from the matrix
    int distance = d[len_s1][len_s2];

    // Free the allocated memory
    for (size_t i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to run the Levenshtein distance calculation in a loop
void run_levenshtein_calculator() {
    char s1[100], s2[100];
    while (1) {
        printf("Enter first string (or type 'exit' to quit): ");
        fgets(s1, 100, stdin);
        s1[strcspn(s1, "\n")] = '\0'; // remove newline character

        if (strcmp(s1, "exit") == 0) break;

        printf("Enter second string: ");
        fgets(s2, 100, stdin);
        s2[strcspn(s2, "\n")] = '\0'; // remove newline character

        int distance = levenshtein_distance(s1, s2);
        printf("Levenshtein Distance between '%s' and '%s' is: %d\n", s1, s2, distance);
    }
}

// The main function to start the program
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("This program calculates the distance between two strings.\n");
    printf("Type 'exit' at any prompt to quit.\n\n");
    run_levenshtein_calculator();
    return 0;
}