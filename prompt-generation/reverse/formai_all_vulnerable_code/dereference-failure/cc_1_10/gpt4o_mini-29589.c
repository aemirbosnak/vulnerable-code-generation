//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    // Allocate memory for distance matrix
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }
    
    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;  // deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;  // insertion cost
    }

    // Compute the distances
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // cost is 0 if the same character
            d[i][j] = min(d[i - 1][j] + 1,       // deletion
                           d[i][j - 1] + 1,       // insertion
                           d[i - 1][j - 1] + cost); // substitution
        }
    }
    
    // Capture the final Levenshtein distance
    int distance = d[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to display the result
void display_result(const char *s1, const char *s2, int distance) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

int main() {
    char str1[100], str2[100];

    // Welcome message
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("===============================================\n");
    
    // Input strings from the user
    printf("Please enter the first string (max 99 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Please enter the second string (max 99 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character

    // Calculate the distance
    int distance = levenshtein(str1, str2);
    
    // Display the result
    display_result(str1, str2, distance);

    // Exit message
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}