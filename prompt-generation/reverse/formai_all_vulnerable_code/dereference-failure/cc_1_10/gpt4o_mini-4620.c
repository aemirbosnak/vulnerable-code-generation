//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: relaxed
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
    int **dist = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len_s1; i++) {
        dist[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (size_t i = 0; i <= len_s1; i++) {
        dist[i][0] = i;  // Distance from s1 to empty s2
    }
    for (size_t j = 0; j <= len_s2; j++) {
        dist[0][j] = j;  // Distance from empty s1 to s2
    }

    // Compute the distance
    for (size_t i = 1; i <= len_s1; i++) {
        for (size_t j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,      // Deletion
                             dist[i][j - 1] + 1,      // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the result
    int result = dist[len_s1][len_s2];

    // Free allocated memory
    for (size_t i = 0; i <= len_s1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// Main function to drive the program
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    
    char s1[100], s2[100];

    printf("Please enter the first string (up to 99 characters): ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove newline character from the string

    printf("Now, please enter the second string (up to 99 characters): ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove newline character from the string

    int distance = levenshtein_distance(s1, s2);
    
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
    
    printf("Thanks for using the Levenshtein Distance Calculator!\n");
    printf("Have a great day!\n");

    return 0;
}