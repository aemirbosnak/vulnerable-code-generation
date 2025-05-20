//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    return min_val;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    // Create a distance matrix
    int **distance_matrix = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance_matrix[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_str1; i++) 
        distance_matrix[i][0] = i;
    for (int j = 0; j <= len_str2; j++) 
        distance_matrix[0][j] = j;

    // Fill in the distance matrix
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(
                distance_matrix[i - 1][j] + 1,    // Deletion
                distance_matrix[i][j - 1] + 1,    // Insertion
                distance_matrix[i - 1][j - 1] + cost  // Substitution
            );
        }
    }

    int distance = distance_matrix[len_str1][len_str2];

    // Free the allocated memory for the matrix
    for (int i = 0; i <= len_str1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);

    return distance;
}

// Function to read input from the user
void read_input(char *str1, char *str2) {
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove trailing newline
}

// Function to display the result
void display_result(const char *str1, const char *str2, int distance) {
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
}

// Main function
int main() {
    char str1[100];
    char str2[100];

    // Read input from the user
    read_input(str1, str2);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    display_result(str1, str2, distance);

    return 0;
}