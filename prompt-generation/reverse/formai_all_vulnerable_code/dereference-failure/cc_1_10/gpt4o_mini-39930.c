//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **distance = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        distance[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }
    
    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        distance[i][0] = i; // To convert from s1 to "" requires i deletions
    }
    for (int j = 0; j <= len_s2; j++) {
        distance[0][j] = j; // To convert from "" to s2 requires j insertions
    }
    
    // Compute distances
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1]; // Characters are the same
            } else {
                distance[i][j] = 1 + min(distance[i - 1][j],    // Deletion
                                         distance[i][j - 1],    // Insertion
                                         distance[i - 1][j - 1]); // Substitution
            }
        }
    }
    
    // Retrieve the distance from the bottom-right corner of the matrix
    int result = distance[len_s1][len_s2];
    
    // Free the allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return result;
}

// Helper function to get user input
void get_input(char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the trailing newline
    }
}

int main() {
    char str1[100], str2[100];
    
    // Get user input for the two strings
    get_input("Enter the first string: ", str1, sizeof(str1));
    get_input("Enter the second string: ", str2, sizeof(str2));
    
    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Print the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    return 0;
}