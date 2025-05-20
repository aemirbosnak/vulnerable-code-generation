//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototype
int min(int a, int b, int c);
int levenshtein_distance(const char *str1, const char *str2);

int main() {
    char str1[100], str2[100];

    // Artistic welcome message
    printf("*************************************\n");
    printf("*    Welcome to the Levenshtein     *\n");
    printf("*        Distance Calculator         *\n");
    printf("*************************************\n\n");

    // User Input Section
    printf("Enter the first string (up to 99 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter the second string (up to 99 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    // Calculate Levenshtein Distance
    int distance = levenshtein_distance(str1, str2);

    // Artistic output of the result
    printf("\n*************************************\n");
    printf("*  The Levenshtein Distance is: %d  *\n", distance);
    printf("*************************************\n");

    return 0;
}

// Function to determine minimum of three numbers
int min(int a, int b, int c) {
    int minimum = a;
    if (b < minimum) minimum = b;
    if (c < minimum) minimum = c;
    return minimum;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize matrix
    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    // Populate the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, // Deletion
                          d[i][j - 1] + 1, // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}