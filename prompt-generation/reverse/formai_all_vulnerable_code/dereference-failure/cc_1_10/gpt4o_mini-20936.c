//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a; // Is 'a' the least?
    else if (b <= a && b <= c) return b; // Or could 'b' be the smallest?
    else return c; // Then it must be 'c'! 
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int lenStr1 = strlen(str1); // How long is the first string?
    int lenStr2 = strlen(str2); // And the second string?

    // Allocating memory for the distance array
    int **dist = (int **)malloc((lenStr1 + 1) * sizeof(int *));
    for (int i = 0; i <= lenStr1; i++) {
        dist[i] = (int *)malloc((lenStr2 + 1) * sizeof(int));
    }

    // Initialize the distance for transformations from/to an empty string
    for (int i = 0; i <= lenStr1; i++) {
        dist[i][0] = i; // If str2 is empty, cost of deleting each char from str1
    }
    for (int j = 0; j <= lenStr2; j++) {
        dist[0][j] = j; // If str1 is empty, cost of adding each char to str2
    }

    // Now we fill the distance matrix
    for (int i = 1; i <= lenStr1; i++) {
        for (int j = 1; j <= lenStr2; j++) {
            // Do the characters match?
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1]; // No cost
            } else {
                // Explore costs: replace, delete, or insert
                dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                                 dist[i][j - 1] + 1,    // Insertion
                                 dist[i - 1][j - 1] + 1);// Replacement
            }
        }
    }

    // The bottom-right cell contains the Levenshtein distance
    int distance = dist[lenStr1][lenStr2];

    // Clean up dynamically allocated memory
    for (int i = 0; i <= lenStr1; i++) {
        free(dist[i]);
    }
    free(dist);
    
    return distance; // What a journey! How far apart are our strings?
}

int main() {
    char str1[100]; // Buffer for the first string
    char str2[100]; // Buffer for the second string

    // Inquiring user for input
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline

    // Calculating the distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0; // Retiring gracefully
}