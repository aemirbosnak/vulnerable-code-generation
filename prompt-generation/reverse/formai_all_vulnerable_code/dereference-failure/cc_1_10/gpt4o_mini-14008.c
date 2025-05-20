//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three values
int min(int a, int b, int c) {
    // Surprised by the choices! Let's find the minimum among them.
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Surprised how simple it is to allocate a 2D array!
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Base case initialization
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deleting all characters
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Inserting all characters
    }

    // Surprised at how every cell is filled based on previous calculations
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,      // Deletion
                                 distance[i][j - 1] + 1,      // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len1][len2]; // The final distance
    // Freeing allocated memory, oh what a surprise!
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Main function to demonstrate the Levenshtein distance
int main() {
    char str1[100], str2[100];

    // Encouraging the user to input strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    // Calculating and displaying the Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    printf("Wow! The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

    // A surprise indeed! Let's add more strings
    printf("Would you like to calculate another distance? (yes/no): ");
    char response[4];
    fgets(response, sizeof(response), stdin);
    response[strcspn(response, "\n")] = '\0'; // Remove trailing newline

    // Keep surprising the user with new calculations
    while (strcmp(response, "yes") == 0) {
        printf("Enter the first string: ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

        printf("Enter the second string: ");
        fgets(str2, sizeof(str2), stdin);
        str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

        distance = levenshtein_distance(str1, str2);
        printf("Amazing! The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);

        printf("Would you like to calculate another distance? (yes/no): ");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\n")] = '\0'; // Remove trailing newline
    }

    printf("Thank you for calculating with us! Goodbye!\n");
    return 0;
}