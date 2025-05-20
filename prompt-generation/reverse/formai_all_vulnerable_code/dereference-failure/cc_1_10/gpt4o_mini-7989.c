//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    // Lengths of the two strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create a distance matrix
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion cost
    }

    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Get the distance from the last cell
    int result = distance[len1][len2];

    // Free the distance matrix
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Main function to drive the wonderful world of Levenshtein distance
int main() {
    char str1[100], str2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("In this whimsical adventure, we will measure the difference between two strings.\n");
    
    // Getting input strings from the user
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove trailing newline character

    printf("Now, enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove trailing newline character

    printf("Calculating the mystical Levenshtein distance...\n");

    // Calculate and display the distance
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    printf("Thank you for joining me on this adventure! Until next time, happy coding!\n");
    
    return 0;
}