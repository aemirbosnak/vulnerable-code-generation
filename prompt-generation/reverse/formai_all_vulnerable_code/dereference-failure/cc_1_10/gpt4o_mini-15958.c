//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // Create a distance matrix
    int **d = (int**)malloc((len_s + 1) * sizeof(int*));
    for (int i = 0; i <= len_s; i++) {
        d[i] = (int*)malloc((len_t + 1) * sizeof(int));
    }

    // Initialize the first row and column
    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j; // Insertion
    }

    // Compute Levenshtein distance
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost);// Substitution
        }
    }

    int distance = d[len_s][len_t];

    // Free allocated memory
    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to print the results
void print_results(const char *s, const char *t, int distance) {
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s, t, distance);
}

// Main function to drive the program
int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character if present

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character if present

    int distance = levenshtein_distance(str1, str2);
    print_results(str1, str2, distance);

    return 0;
}