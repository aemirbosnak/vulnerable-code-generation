//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int minimum = a; 
    if (b < minimum) minimum = b;
    if (c < minimum) minimum = c;
    return minimum;
}

// Function to compute the Levenshtein Distance between two strings
int levenshteinDistance(const char *str1, const char *str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    
    // Creating a 2D array to store distances
    int **distanceMatrix = (int **)malloc((lenStr1 + 1) * sizeof(int *));
    for(int i = 0; i <= lenStr1; i++) {
        distanceMatrix[i] = (int *)malloc((lenStr2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for(int i = 0; i <= lenStr1; i++) {
        distanceMatrix[i][0] = i; // Deletion
    }
    
    for(int j = 0; j <= lenStr2; j++) {
        distanceMatrix[0][j] = j; // Insertion
    }

    // Fill the matrix
    for(int i = 1; i <= lenStr1; i++) {
        for(int j = 1; j <= lenStr2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distanceMatrix[i][j] = min(
                distanceMatrix[i - 1][j] + 1, // Deletion
                distanceMatrix[i][j - 1] + 1, // Insertion
                distanceMatrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }
    
    int result = distanceMatrix[lenStr1][lenStr2];

    // Free the allocated memory
    for(int i = 0; i <= lenStr1; i++) {
        free(distanceMatrix[i]);
    }
    free(distanceMatrix);

    return result;
}

// Function to get user input for two strings
void getInputStrings(char **str1, char **str2) {
    *str1 = (char *)malloc(100 * sizeof(char));
    *str2 = (char *)malloc(100 * sizeof(char));

    printf("Enter the first string: ");
    fgets(*str1, 100, stdin);
    (*str1)[strcspn(*str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(*str2, 100, stdin);
    (*str2)[strcspn(*str2, "\n")] = 0; // Remove newline character
}

int main() {
    char *string1, *string2;

    // Get user input for the two strings
    getInputStrings(&string1, &string2);

    // Calculate and display the Levenshtein Distance
    int distance = levenshteinDistance(string1, string2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    // Free the allocated memory for strings
    free(string1);
    free(string2);

    return 0;
}