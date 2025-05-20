//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate Levenshtein distance
int levenshteinDistance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (size_t i = 0; i <= len1; i++)
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    
    // Initialize distance array
    for (size_t i = 0; i <= len1; i++)
        distance[i][0] = i;
    
    for (size_t j = 0; j <= len2; j++)
        distance[0][j] = j;
    
    // Compute the distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,    // Deletion
                                 distance[i][j - 1] + 1,    // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int result = distance[len1][len2];
    
    // Free allocated memory
    for (size_t i = 0; i <= len1; i++)
        free(distance[i]);
    free(distance);
    
    return result;
}

// Function to read strings from user
void readInput(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character
}

// Function to display the result
void displayResult(const char *str1, const char *str2, int distance) {
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

int main() {
    char str1[100], str2[100];
    
    // Reading user input
    readInput(str1, str2);
    
    // Calculating the Levenshtein distance
    int distance = levenshteinDistance(str1, str2);
    
    // Displaying the result
    displayResult(str1, str2, distance);

    return 0;
}