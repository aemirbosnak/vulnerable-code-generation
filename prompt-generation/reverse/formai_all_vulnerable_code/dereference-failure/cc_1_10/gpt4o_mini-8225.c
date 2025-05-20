//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        dist[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        dist[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_s2; j++) {
        dist[0][j] = j; // Insertion
    }

    // Compute the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,     // Deletion
                             dist[i][j - 1] + 1,     // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len_s1][len_s2];

    // Free the allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// Function to read a string from the user
void read_string(char *str, int max_len) {
    printf("Enter a string (max %d characters): ", max_len - 1);
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character
}

// Main function to execute the program
int main() {
    const int max_length = 100;
    char str1[max_length];
    char str2[max_length];

    printf("Levenshtein Distance Calculator\n");
    read_string(str1, max_length);
    read_string(str2, max_length);

    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    return 0;
}