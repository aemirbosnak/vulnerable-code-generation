//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three values
int min(int a, int b, int c) {
    int minimum = a;
    if (b < minimum) {
        minimum = b;
    }
    if (c < minimum) {
        minimum = c;
    }
    return minimum;
}

// Function to calculate Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);

    // Create a matrix to store distances
    int **distance = (int **)malloc((len_str1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_str1; i++) {
        distance[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    // Initialize the matrix
    for (int i = 0; i <= len_str1; i++) {
        distance[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_str2; j++) {
        distance[0][j] = j; // Insertion
    }

    // Compute Levenshtein distances
    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Get the Levenshtein distance from the matrix
    int levenshtein_dist = distance[len_str1][len_str2];

    // Free the allocated memory
    for (int i = 0; i <= len_str1; i++) {
        free(distance[i]);
    }
    free(distance);

    return levenshtein_dist;
}

int main() {
    // Welcome message
    printf("🎉 Welcome to the Levenshtein Distance Calculator! 🎉\n");
    
    // Input strings
    char str1[100], str2[100];
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate the distance
    int distance = levenshtein_distance(str1, str2);

    // Display the result
    printf("✨ The Levenshtein distance between \"%s\" and \"%s\" is: %d ✨\n", str1, str2, distance);

    // Show a fantastic outro
    printf("Thank you for using the Levenshtein Distance Calculator! 🚀\n");
    printf("Keep on coding, and remember: Every distance can be bridged! 💻💡\n");

    return 0;
}