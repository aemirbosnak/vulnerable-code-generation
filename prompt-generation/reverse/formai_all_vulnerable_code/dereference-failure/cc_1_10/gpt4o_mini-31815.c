//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) 
        return a;
    else if (b <= a && b <= c) 
        return b;
    else 
        return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a matrix (2D array)
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and first column
    for (int i = 0; i <= len1; i++) 
        d[i][0] = i;
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;

    // Fill in the matrix
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

// Function to read string input from the user
void read_input(char *str, int max_len) {
    printf("Enter a string (max %d characters): ", max_len - 1);
    fgets(str, max_len, stdin);
    
    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    const int MAX_LEN = 100; // Maximum length for input strings
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    // Read two strings from the user
    read_input(str1, MAX_LEN);
    read_input(str2, MAX_LEN);

    // Calculate Levenshtein Distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output the result
    printf("Levenshtein Distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}