//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    // Create a matrix to store the distances
    int** dist = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dist[i] = (int*)malloc(sizeof(int) * (n + 1));
        for (int j = 0; j <= n; j++) {
            dist[i][j] = 0;
        }
    }

    // Calculate the distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Insertion
            dist[i][j] = dist[i - 1][j] + 1;

            // Deletion
            dist[i][j] = (dist[i - 1][j] < dist[i - 1][j - 1] + 1)? dist[i - 1][j] : dist[i - 1][j - 1] + 1;

            // Substitution
            dist[i][j] = (dist[i - 1][j - 1] < dist[i - 1][j] + 1)? dist[i - 1][j - 1] : dist[i - 1][j] + 1;
        }
    }

    // Return the minimum distance
    int minDist = m + n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            minDist = (dist[i][j] < minDist)? dist[i][j] : minDist;
        }
    }

    free(dist);
    return minDist;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);
    return 0;
}