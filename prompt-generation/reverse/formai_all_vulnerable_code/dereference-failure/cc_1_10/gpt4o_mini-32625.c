//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a matrix to hold distances
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    for(int i = 0; i <= len1; i++) {
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first column and first row
    for(int i = 0; i <= len1; i++) {
        dist[i][0] = i; // deletion
    }
    for(int j = 0; j <= len2; j++) {
        dist[0][j] = j; // insertion
    }

    // Fill the matrix
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(
                dist[i - 1][j] + 1,        // Deletion
                dist[i][j - 1] + 1,        // Insertion
                dist[i - 1][j - 1] + cost  // Substitution
            );
        }
    }

    // Get the distance from the last cell
    int result = dist[len1][len2];

    // Free the allocated memory
    for(int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// Function to prompt user input
void prompt_user_input(char *buf, size_t size, const char *message) {
    printf("%s", message);
    fgets(buf, size, stdin);
    buf[strcspn(buf, "\n")] = 0; // Removing the trailing newline character
}

int main() {
    char str1[100], str2[100];

    // Prompt user for first string
    prompt_user_input(str1, sizeof(str1), "Enter the first string: ");
    
    // Prompt user for second string
    prompt_user_input(str2, sizeof(str2), "Enter the second string: ");

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Output the result
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    
    return 0;
}