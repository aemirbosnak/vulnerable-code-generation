//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);

    // Creating a distance matrix
    int **d = (int **) malloc((len_s1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len_s1; ++i)
        d[i] = (int *) malloc((len_s2 + 1) * sizeof(int));

    // Initialize the distance matrix
    for (size_t i = 0; i <= len_s1; ++i)
        d[i][0] = i;
    for (size_t j = 0; j <= len_s2; ++j)
        d[0][j] = j;

    // Magical transformations in the distance matrix begin!
    for (size_t i = 1; i <= len_s1; ++i) {
        for (size_t j = 1; j <= len_s2; ++j) {
            // Check if the characters are the same
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1]; // No cost, they are twins
            } else {
                // Calculate the cost for all transformations
                d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                              d[i][j - 1] + 1,      // Insertion
                              d[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    // Capture our magical distance before it disappears
    int distance = d[len_s1][len_s2];

    // Free up our memory
    for (size_t i = 0; i <= len_s1; ++i)
        free(d[i]);
    free(d);

    return distance;
}

// A delightful helper function to display the intro to our performance
void welcome_message() {
    printf("Welcome to the Enchanted Land of Levenshtein Distances!\n");
    printf("Here, we transform strings with magical spells (edit operations)!\n");
    printf("Type in two poetic strings, and we'll reveal how different they truly are.\n");
}

int main() {
    welcome_message();

    char s1[100], s2[100];
    
    printf("\nEnter the first string (up to 99 characters): ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove trailing newline

    printf("Enter the second string (up to 99 characters): ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove trailing newline

    // Calculate the distance
    int distance = levenshtein_distance(s1, s2);

    // Result reveal
    printf("\n✨✨✨ The spell has been cast! ✨✨✨\n");
    printf("The Levenshtein distance between your enchanting strings is: %d\n", distance);
    printf("This means you need at least %d magical operations to align them!\n", distance);
    printf("Thank you for visiting the Land of Levenshtein! ✨✨\n");
    
    return 0;
}