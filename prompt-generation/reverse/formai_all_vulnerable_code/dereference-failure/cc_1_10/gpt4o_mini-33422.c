//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    a = (a < b) ? a : b;
    return (a < c) ? a : c;
}

// Function to calculate Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    // Allocate memory for the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // Deletion
    }

    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertion
    }

    // Calculate Levenshtein distance using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to create a report of the calculated distance
void generate_report(const char *str1, const char *str2, int distance) {
    printf("----- Levenshtein Distance Report -----\n");
    printf("String 1: '%s'\n", str1);
    printf("String 2: '%s'\n", str2);
    printf("Levenshtein Distance: %d\n", distance);
    printf("---------------------------------------\n");
}

int main() {
    char str1[100], str2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline character

    int distance = levenshtein_distance(str1, str2);
    generate_report(str1, str2, distance);

    return 0;
}