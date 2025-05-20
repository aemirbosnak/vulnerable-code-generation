//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a 2D array for the distance matrix
int** createDistanceMatrix(int len1, int len2) {
    int** distMatrix = (int**)malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        distMatrix[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }
    return distMatrix;
}

// Function to free the distance matrix
void freeDistanceMatrix(int** distMatrix, int len1) {
    for (int i = 0; i <= len1; i++) {
        free(distMatrix[i]);
    }
    free(distMatrix);
}

// Function to compute the Levenshtein distance
int levenshteinDistance(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int** distMatrix = createDistanceMatrix(len1, len2);

    for (int i = 0; i <= len1; i++) {
        distMatrix[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len2; j++) {
        distMatrix[0][j] = j; // Insertion
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            int deletion = distMatrix[i - 1][j] + 1;
            int insertion = distMatrix[i][j - 1] + 1;
            int substitution = distMatrix[i - 1][j - 1] + cost;

            distMatrix[i][j] = deletion < insertion ? (deletion < substitution ? deletion : substitution) : (insertion < substitution ? insertion : substitution);
        }
    }

    int distance = distMatrix[len1][len2];
    freeDistanceMatrix(distMatrix, len1);
    return distance;
}

// Function to take input and calculate distances
void calculateLevenshtein() {
    char str1[100];
    char str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);
}

int main() {
    printf("Levenshtein Distance Calculator\n");
    printf("-------------------------------\n");
    calculateLevenshtein();
    return 0;
}