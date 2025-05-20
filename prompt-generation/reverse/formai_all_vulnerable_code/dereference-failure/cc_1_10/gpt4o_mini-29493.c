//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to calculate Levenshtein distance
int levenshtein_distance(const char* str1, const char* str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a matrix to hold the distances
    int **distance = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }
    
    // Initialize the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_str2; j++) {
        distance[0][j] = j; // Insertion
    }
    
    // Calculate distances
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,         // Deletion
                                 distance[i][j - 1] + 1,         // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int result = distance[len_str1][len_str2];

    // Free allocated memory
    for (int i = 0; i <= len_str1; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

// Function to get user input
void get_input(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    // Remove newline character if present
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    // Remove newline character if present
    str2[strcspn(str2, "\n")] = 0;
}

// Main function
int main() {
    char str1[100];
    char str2[100];

    // Get user input
    get_input(str1, str2);
    
    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output the result
    printf("Levenshtein Distance: %d\n", distance);
    
    return 0;
}