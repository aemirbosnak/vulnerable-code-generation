//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance between two strings
int levenshteinDistance(const char *str1, const char *str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);

    // Create a distance matrix
    int **dist = (int **)malloc((lenStr1 + 1) * sizeof(int *));
    for (int i = 0; i <= lenStr1; i++) {
        dist[i] = (int *)malloc((lenStr2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= lenStr1; i++) {
        dist[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= lenStr2; j++) {
        dist[0][j] = j; // Insertion cost
    }

    // Fill in the distance matrix
    for (int i = 1; i <= lenStr1; i++) {
        for (int j = 1; j <= lenStr2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,         // Deletion
                             dist[i][j - 1] + 1,         // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[lenStr1][lenStr2];

    // Free the allocated memory
    for (int i = 0; i <= lenStr1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to get user input safely
void getInput(char *buffer, int size) {
    printf("Enter a string (max %d characters): ", size - 1);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character
}

// Main function
int main() {
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    // Get first string from user
    getInput(str1, MAX_LENGTH);

    // Get second string from user
    getInput(str2, MAX_LENGTH);

    // Calculate the Levenshtein distance
    int distance = levenshteinDistance(str1, str2);

    // Output the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}