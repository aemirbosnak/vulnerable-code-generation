//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int minVal = a;
    if (b < minVal) {
        minVal = b;
    }
    if (c < minVal) {
        minVal = c;
    }
    return minVal;
}

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char* str1, const char* str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    
    // Create a 2D array to hold the distance values
    int** distance = (int**)malloc((lenStr1 + 1) * sizeof(int*));
    for (int i = 0; i <= lenStr1; i++) {
        distance[i] = (int*)malloc((lenStr2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= lenStr1; i++) {
        distance[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= lenStr2; j++) {
        distance[0][j] = j; // Insertion cost
    }

    // Calculate the distance
    for (int i = 1; i <= lenStr1; i++) {
        for (int j = 1; j <= lenStr2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1, // Deletion
                                 distance[i][j - 1] + 1, // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Save the final distance and free the allocated memory
    int finalDistance = distance[lenStr1][lenStr2];
    for (int i = 0; i <= lenStr1; i++) {
        free(distance[i]);
    }
    free(distance);

    return finalDistance;
}

// Main function to get user input and compute the distance
int main() {
    char str1[100];
    char str2[100];

    // Prompt user for the first string
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    // Prompt user for the second string
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    // Calculate and display the Levenshtein distance
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}