//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min_value = a;
    if (b < min_value) min_value = b;
    if (c < min_value) min_value = c;
    return min_value;
}

int levenshteinDistance(const char *str1, const char *str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    
    // Create a 2D array to store distances
    int **dist = (int **)malloc((lenStr1 + 1) * sizeof(int *));
    for (int i = 0; i <= lenStr1; ++i) {
        dist[i] = (int *)malloc((lenStr2 + 1) * sizeof(int));
    }

    // Initialize the distance array
    for (int i = 0; i <= lenStr1; ++i) {
        dist[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= lenStr2; ++j) {
        dist[0][j] = j; // Insertion cost
    }

    // Compute the distance
    for (int i = 1; i <= lenStr1; ++i) {
        for (int j = 1; j <= lenStr2; ++j) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,       // Deletion
                             dist[i][j - 1] + 1,       // Insertion
                             dist[i - 1][j - 1] + cost);// Substitution
        }
    }

    int distance = dist[lenStr1][lenStr2];

    // Free allocated memory
    for (int i = 0; i <= lenStr1; ++i) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

void getInput(char *buffer, size_t length, const char *prompt) {
    printf("%s: ", prompt);
    if (fgets(buffer, length, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
    }
}

int main() {
    const size_t bufferSize = 1024;
    char str1[bufferSize];
    char str2[bufferSize];

    getInput(str1, bufferSize, "Enter the first string");
    getInput(str2, bufferSize, "Enter the second string");

    int distance = levenshteinDistance(str1, str2);

    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    return 0;
}