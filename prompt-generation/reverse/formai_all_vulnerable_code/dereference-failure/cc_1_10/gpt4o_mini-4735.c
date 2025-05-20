//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // deletion
    }
    
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // insertion
    }

    // Compute the distance using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,       // deletion
                          d[i][j - 1] + 1,       // insertion
                          d[i - 1][j - 1] + cost // substitution
                          );
        }
    }

    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to get user input strings
void getInput(char *s1, char *s2) {
    printf("Enter the first string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0;  // Remove trailing newline

    printf("Enter the second string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0;  // Remove trailing newline
}

// Function to display the result
void displayResult(int distance) {
    printf("The Levenshtein Distance is: %d\n", distance);
}

int main() {
    char str1[100], str2[100];
    
    // Get input strings from the user
    getInput(str1, str2);

    // Compute the Levenshtein distance
    int distance = levenshtein(str1, str2);

    // Display the result
    displayResult(distance);

    return 0;
}