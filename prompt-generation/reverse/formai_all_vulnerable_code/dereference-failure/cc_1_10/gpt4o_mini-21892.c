//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void getInputStrings(char *str1, char *str2);
int min(int a, int b, int c);
int levenshteinDistance(const char *s1, const char *s2);
void displayResult(const char *s1, const char *s2, int distance);

// Main function
int main() {
    char str1[100], str2[100];
    
    getInputStrings(str1, str2);
    
    int distance = levenshteinDistance(str1, str2);
    
    displayResult(str1, str2, distance);
    
    return 0;
}

// Function to get input strings from the user
void getInputStrings(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove the newline character

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove the newline character
}

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a distance matrix
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i; // Cost of deletions
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Cost of insertions
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // If chars are equal, no cost
            d[i][j] = min(d[i - 1][j] + 1,    // Deletion
                          d[i][j - 1] + 1,    // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = d[len1][len2];
    
    // Free the distance matrix
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

// Function to display the result
void displayResult(const char *s1, const char *s2, int distance) {
    printf("Levenshtein Distance between '%s' and '%s' is: %d\n", s1, s2, distance);
}