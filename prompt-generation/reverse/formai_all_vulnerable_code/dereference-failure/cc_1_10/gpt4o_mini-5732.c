//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;

    return c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    
    // Create a distance matrix
    int **dist = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        dist[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_str1; i++) {
        dist[i][0] = i;
    }
    
    for (int j = 0; j <= len_str2; j++) {
        dist[0][j] = j;
    }

    // Populate the distance matrix
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dist[i][j] = dist[i - 1][j - 1]; // No operation required
            } else {
                dist[i][j] = min(dist[i - 1][j] + 1,     // Deletion
                                 dist[i][j - 1] + 1,     // Insertion
                                 dist[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    int result = dist[len_str1][len_str2];

    // Free allocated memory
    for (int i = 0; i <= len_str1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// Function to get user input for strings
void get_user_input(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove newline character
}

// Main function to drive the program
int main() {
    char str1[100], str2[100];

    // Allow the user to input strings
    get_user_input(str1, str2);
    
    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output the result
    printf("Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return 0;
}