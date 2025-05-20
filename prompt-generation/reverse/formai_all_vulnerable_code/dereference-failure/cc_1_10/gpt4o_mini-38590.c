//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

// Function to compute the Levenshtein distance
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    // Fill the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
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

// Function to read input strings
void read_input(char *s1, char *s2) {
    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character
}

// Display the result to the user
void display_result(const char *s1, const char *s2, int distance) {
    printf("Levenshtein distance between '%s' and '%s' is: %d\n", s1, s2, distance);
}

// Main function to orchestrate the program flow
int main() {
    char string1[100], string2[100];
    
    // Read input strings
    read_input(string1, string2);
    
    // Calculate Levenshtein distance
    int distance = levenshtein(string1, string2);
    
    // Display the result
    display_result(string1, string2, distance);
    
    return 0;
}