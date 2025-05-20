//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 1000 // Maximum string length for our futuristic strings.
#define INF 1000 // Representing infinity for our distance calculations.

typedef struct {
    char *original;
    char *transformed;
    int distance;
} LevenshteinData;

// Function prototypes
int min(int a, int b, int c);
int levenshteinDistance(const char *str1, const char *str2);
void initializeData(LevenshteinData *data);
void processStrings(LevenshteinData *data);
void displayResult(const LevenshteinData *data);

// Main futuristic function to calculate the Levenshtein distance
int main() {
    LevenshteinData data;
    initializeData(&data);
    
    printf("Welcome to the Cybernetic Levenshtein Distance Calculator!\n");
    printf("Enter the original string (max length %d): ", MAX_LEN);
    fgets(data.original, MAX_LEN, stdin);
    data.original[strcspn(data.original, "\n")] = 0; // Remove newline character

    printf("Now enter the transformed string (max length %d): ", MAX_LEN);
    fgets(data.transformed, MAX_LEN, stdin);
    data.transformed[strcspn(data.transformed, "\n")] = 0; // Remove newline character

    data.distance = levenshteinDistance(data.original, data.transformed);
    displayResult(&data);

    free(data.original);
    free(data.transformed);
    return 0;
}

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) return a < c ? a : c;
    else return b < c ? b : c;
}

// Function to compute the Levenshtein Distance
int levenshteinDistance(const char *str1, const char *str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    
    int matrix[MAX_LEN + 1][MAX_LEN + 1];

    for (int i = 0; i <= lenStr1; i++) {
        for (int j = 0; j <= lenStr2; j++) {
            if (i == 0) {
                matrix[i][j] = j; // Deleting all characters from str2
            } else if (j == 0) {
                matrix[i][j] = i; // Adding all characters to str1
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1]; // Characters match
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j],    // Deletion
                                       matrix[i][j - 1],    // Insertion
                                       matrix[i - 1][j - 1]); // Substitution
            }
        }
    }

    return matrix[lenStr1][lenStr2];
}

// Function to initialize the data structure
void initializeData(LevenshteinData *data) {
    data->original = (char *)malloc(MAX_LEN * sizeof(char));
    data->transformed = (char *)malloc(MAX_LEN * sizeof(char));
    data->distance = INF;
}

// Function to display the result of the calculation
void displayResult(const LevenshteinData *data) {
    printf("\n--- Levenshtein Distance Result ---\n");
    printf("Original String: %s\n", data->original);
    printf("Transformed String: %s\n", data->transformed);
    printf("Levenshtein Distance: %d\n", data->distance);
    printf("Thanks for using the Cybernetic Levenshtein Distance Calculator! Until we meet again!\n");
}

// End of futuristic Levenshtein Distance Calculator