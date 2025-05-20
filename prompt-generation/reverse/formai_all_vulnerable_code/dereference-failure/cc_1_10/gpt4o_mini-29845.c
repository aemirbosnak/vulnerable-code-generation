//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    }
    return (b < c) ? b : c;
}

// Function to compute Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // deletion
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // insertion
    }

    // Calculate distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dist[i][j] = min(
                dist[i - 1][j] + 1, // deletion
                dist[i][j - 1] + 1, // insertion
                dist[i - 1][j - 1] + cost // substitution
            );
        }
    }

    // Fetch the final distance
    int result = dist[len1][len2];

    // Free the distance matrix
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// Function to interact with user, get input and display distance
void user_interaction() {
    char s1[256], s2[256];

    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // remove newline

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // remove newline

    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

// Main function
int main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    while (1) {
        user_interaction();
        
        char choice;
        printf("Do you want to calculate another distance? (y/n): ");
        choice = getchar();
        getchar(); // consume newline
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}