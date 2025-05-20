//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    int min_value = a;
    if (b < min_value) min_value = b;
    if (c < min_value) min_value = c;
    return min_value;
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein(const char* s1, const char* s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    // Create a distance matrix
    int** distance = (int**)malloc((len_s1 + 1) * sizeof(int*));
    for (int i = 0; i <= len_s1; i++) {
        distance[i] = (int*)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len_s1; i++) {
        distance[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        distance[0][j] = j; // Insertion cost
    }

    // Populate the distance matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Substitution cost
            distance[i][j] = min(distance[i - 1][j] + 1,        // Deletion
                                 distance[i][j - 1] + 1,        // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len_s1][len_s2]; // Distance is in the bottom-right cell

    // Clean up memory
    for (int i = 0; i <= len_s1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result; // Return the final distance
}

// Function to read strings from the user
void read_strings(char** str1, char** str2) {
    char buffer1[100], buffer2[100];
    printf("Enter the first string (up to 99 characters): ");
    fgets(buffer1, sizeof(buffer1), stdin);
    buffer1[strcspn(buffer1, "\n")] = 0; // Remove newline character

    printf("Enter the second string (up to 99 characters): ");
    fgets(buffer2, sizeof(buffer2), stdin);
    buffer2[strcspn(buffer2, "\n")] = 0; // Remove newline character

    // Allocate memory for strings
    *str1 = (char*)malloc(strlen(buffer1) + 1);
    *str2 = (char*)malloc(strlen(buffer2) + 1);

    // Copy the input strings
    strcpy(*str1, buffer1);
    strcpy(*str2, buffer2);
}

// Main function to execute the program
int main() {
    char* str1 = NULL;
    char* str2 = NULL;

    read_strings(&str1, &str2); // Read the strings from user

    // Calculate Levenshtein Distance
    int distance = levenshtein(str1, str2);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    // Free allocated memory for strings
    free(str1);
    free(str2);

    return 0; // End of program
}