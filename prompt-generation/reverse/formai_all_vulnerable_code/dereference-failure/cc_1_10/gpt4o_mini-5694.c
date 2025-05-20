//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **distance_matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    
    // Allocate memory for distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize distance matrix
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i][0] = i; // Source prefix
    }
    for (int j = 0; j <= len_str2; j++) {
        distance_matrix[0][j] = j; // Target prefix
    }

    // Compute the distance
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(distance_matrix[i - 1][j] + 1, // Deletion
                                         distance_matrix[i][j - 1] + 1, // Insertion
                                         distance_matrix[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Retrieve the distance from the matrix
    int result = distance_matrix[len_str1][len_str2];

    // Free allocated memory for distance matrix
    for (int i = 0; i <= len_str1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return result;
}

// Function to read string input from the user
void read_input(char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove new line character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int main() {
    const size_t max_length = 256;
    char string1[max_length];
    char string2[max_length];

    // Prompt user for input
    read_input("Enter the first string: ", string1, sizeof(string1));
    read_input("Enter the second string: ", string2, sizeof(string2));

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(string1, string2);

    // Display the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    return 0;
}