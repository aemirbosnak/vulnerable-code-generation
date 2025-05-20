//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

// Function to compute the Levenshtein Distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a matrix to store results
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_s1; i++) d[i][0] = i;
    for (int j = 0; j <= len_s2; j++) d[0][j] = j;

    // Populate the matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len_s1][len_s2];

    // Free the allocated memory for the matrix
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to interact with the user and get input strings
void userInteraction() {
    char str1[256], str2[256];
    
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character
    
    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character

    int distance = levenshtein(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

// Main function to run the program
int main() {
    userInteraction();
    
    return 0;
}