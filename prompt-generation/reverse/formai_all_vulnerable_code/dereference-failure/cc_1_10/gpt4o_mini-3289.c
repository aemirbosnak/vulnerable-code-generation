//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    }
    if (b < c) {
        return b;
    }
    return c;
}

// Function to calculate Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a matrix to hold distances
    int **distance_matrix = (int **) malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i] = (int *) malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_str2; j++) {
        distance_matrix[0][j] = j; // Insertion
    }

    // Populate the distance matrix
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(distance_matrix[i - 1][j] + 1,      // Deletion
                                          distance_matrix[i][j - 1] + 1,      // Insertion
                                          distance_matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = distance_matrix[len_str1][len_str2];

    // Free the allocated memory
    for (int i = 0; i <= len_str1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);
    
    return distance;
}

// Main function
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Thanks for taking the time to learn about string distances.\n\n");

    char str1[100], str2[100];
    
    // Taking user input
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    // Calculating the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Displaying the result
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    printf("We appreciate your presence in the world of programming.\n");

    return 0;
}