//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    }
    return (b < c) ? b : c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    // Create a matrix to store distances
    int **distance = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_str1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_str2; j++) {
        distance[0][j] = j; // Insertion
    }

    // Calculate the distance
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,         // Deletion
                                 distance[i][j - 1] + 1,         // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len_str1][len_str2];

    // Free allocated memory
    for (int i = 0; i <= len_str1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Main function
int main() {
    char str1[100], str2[100];
    char choice;

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    do {
        printf("\nEnter the first string: ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = 0; // Remove newline character

        printf("Enter the second string: ");
        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = 0; // Remove newline character

        int distance = levenshtein_distance(str1, str2);
        printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

        printf("Would you like to calculate again? (y/n): ");
        choice = getchar();
        while (getchar() != '\n'); // Clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Levenshtein Distance Calculator. Goodbye!\n");
    return 0;
}