//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) 
        return (a < c) ? a : c;
    return (b < c) ? b : c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **dist = malloc((len1 + 1) * sizeof(int*));
    
    for (int i = 0; i <= len1; i++)
        dist[i] = malloc((len2 + 1) * sizeof(int));

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++)
        dist[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dist[0][j] = j;

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                             dist[i][j - 1] + 1,    // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Display the distance matrix
    printf("\nLevenshtein Distance Matrix:\n");
    printf("    ");
    for (int j = 0; j <= len2; j++)
        printf("%3d ", j);
    printf("\n");

    for (int i = 0; i <= len1; i++) {
        if (i > 0) {
            printf("%c ", s1[i - 1]);
        } else {
            printf("  ");
        }
        for (int j = 0; j <= len2; j++) {
            printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    int distance = dist[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++)
        free(dist[i]);
    free(dist);

    return distance;
}

// Main function to take user inputs and display the result
int main() {
    char s1[100], s2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove newline

    printf("Please enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove newline

    int distance = levenshtein(s1, s2);
    
    printf("\nThe Levenshtein Distance between '%s' and '%s' is: %d\n", s1, s2, distance);
    return 0;
}