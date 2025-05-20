//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute Levenshtein Distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++)
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    
    for (int i = 0; i <= len1; i++)
        d[i][0] = i;  // Deletion distance
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;  // Insertion distance

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1,   // Deletion
                                d[i][j - 1] + 1),  // Insertion
                                d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++)
        free(d[i]);
    free(d);

    return distance;
}

// Helper function to beautify the output
void printTitle() {
    printf("=========================================\n");
    printf("       Levenshtein Distance Calculator   \n");
    printf("=========================================\n");
}

// Read strings from user input
void readStrings(char **s1, char **s2) {
    *s1 = (char *)malloc(100 * sizeof(char));
    *s2 = (char *)malloc(100 * sizeof(char));

    printf("Enter the first string: ");
    fgets(*s1, 100, stdin);
    (*s1)[strcspn(*s1, "\n")] = 0;  // Remove newline character

    printf("Enter the second string: ");
    fgets(*s2, 100, stdin);
    (*s2)[strcspn(*s2, "\n")] = 0;  // Remove newline character
}

// Main function to execute the program
int main() {
    char *string1, *string2;

    printTitle();
    readStrings(&string1, &string2);

    int distance = levenshtein(string1, string2);
    printf("The Levenshtein Distance between:\n");
    printf("1. \"%s\"\n", string1);
    printf("2. \"%s\"\n", string2);
    printf("is: %d\n", distance);

    // Free allocated memory for strings
    free(string1);
    free(string2);

    return 0;
}