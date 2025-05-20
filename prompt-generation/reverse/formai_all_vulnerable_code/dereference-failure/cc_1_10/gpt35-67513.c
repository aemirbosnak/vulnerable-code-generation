//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate minimum value of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function to calculate Levenshtein Distance between two strings
int levenshteinDistance(char s[], char t[]) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // Create a matrix of size (len_s + 1) x (len_t + 1) to store the minimum edit distances
    int** matrix = (int**) malloc(sizeof(int*) * (len_s + 1));
    for (int i=0; i <= len_s; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * (len_t + 1));
    }
    
    // Initialize the matrix with initial values
    for (int i=0; i <= len_s; i++) {
        for (int j=0; j <= len_t; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            }
            else if (j == 0) {
                matrix[i][j] = i;
            }
            else if (s[i-1] == t[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }
    
    // Store the distance value at (len_s, len_t) in a variable and free the memory
    int distance = matrix[len_s][len_t];
    for (int i=0; i <= len_s; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return distance;
}

int main() {
    char input_string[MAX_LEN];
    char target_string[MAX_LEN];
    
    // Prompt user for input and target strings
    printf("Enter input string: ");
    fgets(input_string, MAX_LEN, stdin);
    printf("Enter target string: ");
    fgets(target_string, MAX_LEN, stdin);
    
    // Remove newline character from input and target strings
    input_string[strcspn(input_string, "\n")] = 0;
    target_string[strcspn(target_string, "\n")] = 0;
    
    // Calculate the Levenshtein Distance between the strings and print the result
    int distance = levenshteinDistance(input_string, target_string);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n", input_string, target_string, distance);
    
    return 0;
}