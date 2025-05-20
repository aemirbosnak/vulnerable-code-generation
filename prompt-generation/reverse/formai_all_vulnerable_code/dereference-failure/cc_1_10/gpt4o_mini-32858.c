//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    int ab = (a < b) ? a : b;
    return (ab < c) ? ab : c;
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
        d[i][0] = i;  // Deletion cost
    }
    
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;  // Insertion cost
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = d[len1][len2];

    // Free the memory used for the array
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

// Function to prompt user input safely
void prompt_for_string(char *str, int max_len) {
    printf("Please enter a string (max %d characters): ", max_len - 1);
    fgets(str, max_len, stdin);
    
    // Remove newline character from the input
    str[strcspn(str, "\n")] = 0;
}

// Main function to run the program
int main() {
    // Set maximum string length
    const int MAX_LEN = 100;

    // Prepare storage for two strings
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    // Provide an introduction to the user
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("You will need to enter two strings to compare.\n");
    
    // Get the first string from user
    prompt_for_string(str1, MAX_LEN);
    
    // Get the second string from user
    prompt_for_string(str2, MAX_LEN);

    // Calculate the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result to the user
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    // Provide an encouraging message on completion
    printf("Thank you for using the Levenshtein Distance Calculator. Have a great day!\n");
    
    return 0;
}