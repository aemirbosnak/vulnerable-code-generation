//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize distance array
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion
    }

    // Calculate distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,       // Deletion
                             dist[i][j - 1] + 1,       // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Main function to drive the program
int main() {
    char str1[100], str2[100];

    // Welcome message
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Prepare to enter two strings... let's see how different they are!\n");

    // Input strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate the Levenshtein Distance
    int distance = levenshteinDistance(str1, str2);

    // Output the result
    printf("Surprisingly, the Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    // Reflect on the results
    if (distance == 0) {
        printf("Woah! They are identical!\n");
    } else if (distance <= 3) {
        printf("Not too far apart, interesting!\n");
    } else {
        printf("Yikes! Quite a difference, huh?\n");
    }

    // Farewell message
    printf("Thank you for using the Levenshtein Distance Calculator! Goodbye!\n");

    return 0;
}