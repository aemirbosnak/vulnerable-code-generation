//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to compute the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = malloc((len_s1 + 1) * sizeof(int *));
    
    // Allocate memory for distance matrix
    for (int i = 0; i <= len_s1; i++) {
        d[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize distance matrix
    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j; // Insertion cost
    }

    // Populate the distance matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,   // Deletion
                          d[i][j - 1] + 1,   // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    // Free allocated memory
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to read a string from user input
void read_string(char *buffer, int size) {
    printf("Enter a string (max %d characters): ", size - 1);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int main() {
    const int MAX_LENGTH = 100;
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    // Input strings from user
    read_string(string1, MAX_LENGTH);
    read_string(string2, MAX_LENGTH);

    // Calculate the Levenshtein distance
    int distance = levenshtein(string1, string2);

    // Print the result
    printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    return 0;
}