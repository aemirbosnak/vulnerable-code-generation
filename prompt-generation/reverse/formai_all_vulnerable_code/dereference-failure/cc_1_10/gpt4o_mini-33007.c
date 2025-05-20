//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

// Function to compute the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        dist[i] = malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_s1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len_s2; j++) {
        dist[0][j] = j;
    }

    // Populate the matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,      // Deletion
                             dist[i][j - 1] + 1,      // Insertion
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

// Function to prompt user for input strings
void prompt_user_for_strings(char *s1, char *s2) {
    printf("Welcome to the Enchanted Levenshtein Distance Calculator!\n");
    printf("Please enter the first magical string (max %d characters):\n", MAX_LEN - 1);
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove newline character

    printf("Now, conjure the second magical string (max %d characters):\n", MAX_LEN - 1);
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove newline character
}

// Main function
int main() {
    char s1[MAX_LEN];
    char s2[MAX_LEN];

    prompt_user_for_strings(s1, s2);

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", s1, s2, distance);

    return 0;
}