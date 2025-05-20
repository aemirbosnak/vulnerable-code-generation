//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance between two strings
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **distanceMatrix = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distanceMatrix[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        distanceMatrix[0][j] = j; // Insertion
    }

    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distanceMatrix[i][j] = min(distanceMatrix[i - 1][j] + 1,    // Deletion
                                        distanceMatrix[i][j - 1] + 1,    // Insertion
                                        distanceMatrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = distanceMatrix[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distanceMatrix[i]);
    }
    free(distanceMatrix);

    return distance;
}

// Helper function to get the input strings from the user
void getInputStrings(char *str1, char *str2, int maxLength) {
    printf("Enter the first string (max %d characters): ", maxLength - 1);
    fgets(str1, maxLength, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the second string (max %d characters): ", maxLength - 1);
    fgets(str2, maxLength, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline
}

// Main function to run the program
int main() {
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    getInputStrings(str1, str2, MAX_LENGTH);
    int distance = levenshteinDistance(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}