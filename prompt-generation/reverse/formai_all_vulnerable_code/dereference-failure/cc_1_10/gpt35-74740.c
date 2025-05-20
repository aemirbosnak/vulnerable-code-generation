//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three integers
int min(int x, int y, int z) {
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Allocate a 2D array to store the distances
    int** dist = (int**) calloc(len1+1, sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int*) calloc(len2+1, sizeof(int));
    }

    // Initialize the distances for the empty strings
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the distances for all substrings
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
            }
        }
    }

    // Store the value of the final distance and free memory
    int result = dist[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

int main() {
    char* s1 = "Levenshtein";
    char* s2 = "Distance";

    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2, levenshtein(s1, s2));

    return 0;
}