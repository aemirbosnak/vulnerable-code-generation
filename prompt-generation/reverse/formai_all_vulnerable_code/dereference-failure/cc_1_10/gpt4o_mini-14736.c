//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to get the minimum of three numbers
int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++)
        dist[i] = (int *)malloc((len_s2 + 1) * sizeof(int));

    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++)
        dist[i][0] = i; 
    for (int j = 0; j <= len_s2; j++)
        dist[0][j] = j; 

    // Populate the distance matrix
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,      // Deletion
                             dist[i][j - 1] + 1,      // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = dist[len_s1][len_s2];

    // Free the distance matrix
    for (int i = 0; i <= len_s1; i++)
        free(dist[i]);
    free(dist);

    return distance;
}

// Function to greet the user
void greetUser() {
    printf("********************************************\n");
    printf("*        Welcome to Levenshtein Distance   *\n");
    printf("*          Calculator (Cheerfully!)        *\n");
    printf("********************************************\n");
}

// Function to get strings from the user
void getUserStrings(char *s1, char *s2) {
    printf("Please enter the first string: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character

    printf("Please enter the second string: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character
}

// Main function
int main() {
    greetUser();

    char s1[100];
    char s2[100];

    getUserStrings(s1, s2);

    printf("\nCalculating the Levenshtein distance...\n");

    int distance = levenshteinDistance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
    printf("Thank you for using the Levenshtein Distance Calculator! Have a fantastic day!\n");

    return 0;
}