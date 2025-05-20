//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a distance matrix
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion from str1
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion into str1
    }

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1]; // No change
            } else {
                dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                                 dist[i][j - 1] + 1,    // Insertion
                                 dist[i - 1][j - 1] + 1  // Substitution
                );
            }
        }
    }

    // Capture the final distance
    int distance = dist[len1][len2];

    // Free memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

int main() {
    // Peacefully welcome the user
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    
    // Dynamically allocate memory for first string
    char *str1 = (char *)malloc(256 * sizeof(char));
    fgets(str1, 256, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline

    printf("Please enter the second string: ");
    
    // Dynamically allocate memory for second string
    char *str2 = (char *)malloc(256 * sizeof(char));
    fgets(str2, 256, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline

    // Calculate the Levenshtein distance in a tranquil manner
    int distance = levenshtein_distance(str1, str2);
    
    // Confidently display the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    // Free dynamically allocated memory
    free(str1);
    free(str2);
    
    // Bid farewell
    printf("Thank you for using the Levenshtein Distance Calculator. Have a peaceful day!\n");
    
    return 0;
}