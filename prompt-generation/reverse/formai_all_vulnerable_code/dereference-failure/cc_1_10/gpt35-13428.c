//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int i, j, cost;
    // Create a 2D array to store the distance values
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance array with the base cases
    for (i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    // Calculate the distance values
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            distance[i][j] = min(distance[i-1][j] + 1, distance[i][j-1] + 1, distance[i-1][j-1] + cost);
        }
    }

    // Store the final distance value and free the allocated memory
    int levDist = distance[len1][len2];
    for (i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return levDist;
}

int main() {
    // Take two input strings from the user
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein Distance between the two strings
    int levDistance = levenshteinDistance(str1, str2, strlen(str1), strlen(str2));
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, levDistance);

    return 0;
}