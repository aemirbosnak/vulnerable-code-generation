//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // Create a 2D array to store distances
    int **distance = malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        distance[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance array
    for (size_t i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (size_t j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion
    }
    
    // Calculate the distances
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,       // Deletion
                                 distance[i][j - 1] + 1,       // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the final distance
    int result = distance[len1][len2];

    // Free the allocated memory
    for (size_t i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to read user input
void read_input(char *buffer, size_t size) {
    printf("Enter a string: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

// Main function
int main() {
    const size_t max_length = 100;
    char str1[max_length];
    char str2[max_length];

    // Input first string
    read_input(str1, max_length);
    
    // Input second string
    read_input(str2, max_length);
    
    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Output the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}