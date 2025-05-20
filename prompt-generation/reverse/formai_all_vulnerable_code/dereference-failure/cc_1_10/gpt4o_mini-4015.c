//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
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

// Function to calculate the Levenshtein Distance between two strings
int levenshtein(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a matrix to hold distances
    int **distance = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deleting all characters from str1
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Inserting characters to str1 to get str2
    }

    // Compute distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,    // Deletion
                                 distance[i][j - 1] + 1,    // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    // Store the result
    int result = distance[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to interact with the user and demonstrate gratitude
void user_interaction() {
    char str1[256], str2[256];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("This program graciously calculates the distance between two strings.\n\n");

    // Accept first string with grateful prompt
    printf("Please enter the first string (max 255 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Removing trailing newline

    // Accept second string with a warm invitation
    printf("Now, kindly enter the second string (max 255 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Removing trailing newline

    // Calculate the distance
    int distance = levenshtein(str1, str2);

    // Display result with gratitude
    printf("\nThank you for using our tool!\n");
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("Your participation is highly appreciated!\n");
}

int main() {
    user_interaction();
    return 0;
}