//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to compute the Levenshtein distance between two strings
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
        d[i][0] = i;   // Deletion
    }
    for (size_t j = 0; j <= len_s2; j++) {
        d[0][j] = j;   // Insertion
    }

    // Compute the distance
    for (size_t i = 1; i <= len_s1; i++) {
        for (size_t j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                           d[i][j - 1] + 1,      // Insertion
                           d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len_s1][len_s2];
    
    // Free the distance matrix
    for (size_t i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);
    
    return result;
}

// Main function
int main() {
    char str1[100], str2[100];

    // Prompt for first string
    printf("Enter the first string: ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    // Prompt for second string
    printf("Enter the second string: ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);
    
    return EXIT_SUCCESS;
}