//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
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

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **dist = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    // Check for memory allocation failure
    if (!dist) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i <= len_s1; i++) {
        dist[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
        
        // Check for memory allocation failure
        if (!dist[i]) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i <= len_s1; i++) {
        dist[i][0] = i; // Deletion cost
    }

    for (int j = 0; j <= len_s2; j++) {
        dist[0][j] = j; // Insertion cost
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Substitution cost
            dist[i][j] = min(dist[i - 1][j] + 1,        // Deletion
                             dist[i][j - 1] + 1,        // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to get string input from the user
char* getInputString(const char *prompt) {
    char *input = NULL;
    size_t size = 0;

    printf("%s", prompt);
    getline(&input, &size, stdin);
    
    // Remove the newline character from the input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    return input;
}

int main() {
    printf("Levenshtein Distance Calculator\n");
    
    // Get the first string from the user
    char *string1 = getInputString("Please enter the first string: ");
    
    // Get the second string from the user
    char *string2 = getInputString("Please enter the second string: ");
    
    // Calculate the Levenshtein Distance
    int distance = levenshteinDistance(string1, string2);
    
    // Display the result
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", string1, string2, distance);
    
    // Free the allocated input strings
    free(string1);
    free(string2);

    return 0;
}