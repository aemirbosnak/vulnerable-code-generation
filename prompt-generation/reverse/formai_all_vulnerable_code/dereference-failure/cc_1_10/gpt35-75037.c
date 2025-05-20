//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate minimum of three given numbers
int getMinimum(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    else
        return z;
}

// Function to calculate Levenshtein distance between two strings
int calculateLevenshteinDistance(char* str1, char* str2) {

    int size1 = strlen(str1);
    int size2 = strlen(str2);

    // Dynamically allocating matrix to store distances
    int** distanceMatrix = (int**)malloc(sizeof(int*) * (size1 + 1));
    for (int i = 0; i <= size1; i++)
        distanceMatrix[i] = (int*)malloc(sizeof(int) * (size2 + 1));

    // Initializing first row and column of matrix
    for (int i = 0; i <= size1; i++)
        distanceMatrix[i][0] = i;
    for (int j = 0; j <= size2; j++)
        distanceMatrix[0][j] = j;

    // Filling up the rest of the matrix
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (str1[i - 1] == str2[j - 1])
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
            else
                distanceMatrix[i][j] = 1 + getMinimum(distanceMatrix[i - 1][j - 1], distanceMatrix[i - 1][j], distanceMatrix[i][j - 1]);
        }
    }

    int result = distanceMatrix[size1][size2];

    // Freeing the memory allocated to matrix
    for (int i = 0; i <= size1; i++)
        free(distanceMatrix[i]);
    free(distanceMatrix);

    return result;
}

// Main function
int main() {

    char* string1 = "kitten";
    char* string2 = "sitting";

    int result = calculateLevenshteinDistance(string1, string2);

    printf("The Levenshtein distance between '%s' and '%s' is %d\n", string1, string2, result);

    return 0;
}