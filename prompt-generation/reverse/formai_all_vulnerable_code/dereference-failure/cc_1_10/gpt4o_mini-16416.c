//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **dist = malloc((len_s1 + 1) * sizeof(int *));
    
    for(int i = 0; i <= len_s1; i++) {
        dist[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for(int i = 0; i <= len_s1; i++) {
        dist[i][0] = i; // Deletion from s1
    }
    for(int j = 0; j <= len_s2; j++) {
        dist[0][j] = j; // Insertion to s1
    }

    // Populate the distance matrix
    for(int i = 1; i <= len_s1; i++) {
        for(int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = fmin(fmin(dist[i - 1][j] + 1,    // Deletion
                                    dist[i][j - 1] + 1),   // Insertion
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

// Function to get user input safely
void get_input(char *buffer, size_t size) {
    printf("Please enter the string (max length %zu): ", size - 1);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
}

int main() {
    const size_t max_length = 100; // max length for input strings
    char str1[max_length], str2[max_length];
    
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    
    // Obtain first string input
    get_input(str1, max_length);
    
    // Obtain second string input
    get_input(str2, max_length);

    // Calculate Levenshtein Distance
    int distance = levenshtein_distance(str1, str2);
    
    // Display the result
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);
    
    return 0;
}