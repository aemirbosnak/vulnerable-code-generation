//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to compute Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a matrix to store distances
    int **matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i; // Deletion
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j; // Insertion
    }

    // Compute distance
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            matrix[i][j] = min(matrix[i - 1][j] + 1,    // Deletion
                               matrix[i][j - 1] + 1,    // Insertion
                               matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = matrix[len1][len2];

    // Free the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

// Function to get user input and calculate distance
void calculate_distance() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove the newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove the newline

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

// Main function to run the program
int main() {
    int choice;

    do {
        calculate_distance();

        printf("Do you want to calculate another distance? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

    } while (choice != 0);

    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}