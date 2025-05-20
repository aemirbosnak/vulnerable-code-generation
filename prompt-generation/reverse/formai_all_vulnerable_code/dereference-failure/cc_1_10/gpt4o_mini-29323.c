//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

int levenshtein_distance(const char* str1, const char* str2) {
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    
    // Create the distance matrix
    int** matrix = (int**)malloc(len1 * sizeof(int*));
    for (int i = 0; i < len1; i++) {
        matrix[i] = (int*)malloc(len2 * sizeof(int));
    }

    // Initialize the first row and column
    for (int i = 0; i < len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < len2; j++) {
        matrix[0][j] = j;
    }

    // Compute the distance
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1,  // Deletion
                               matrix[i][j-1] + 1,  // Insertion
                               matrix[i-1][j-1] + cost); // Substitution
        }
    }
    
    int distance = matrix[len1 - 1][len2 - 1];

    // Free the allocated memory
    for (int i = 0; i < len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

void get_input(char* buffer, size_t size) {
    printf("Enter a string: ");
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
    }
}

int main() {
    char str1[100];
    char str2[100];

    get_input(str1, sizeof(str1));
    get_input(str2, sizeof(str2));

    int distance = levenshtein_distance(str1, str2);
    
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}