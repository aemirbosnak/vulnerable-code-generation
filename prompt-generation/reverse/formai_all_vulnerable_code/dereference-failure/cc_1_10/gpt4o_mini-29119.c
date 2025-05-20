//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The fateful day when we first met
#define MAX_STRING_LENGTH 100

// A poetic function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a 2D array to store the distances
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++)
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    
    // Initializing the first row and first column
    for (int i = 0; i <= len1; i++)
        d[i][0] = i;  // Cost of deletions
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;  // Cost of insertions

    // Calculate the distances
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;

            d[i][j] = fmin(fmin(d[i - 1][j] + 1,     // Deletion
                               d[i][j - 1] + 1),    // Insertion
                               d[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = d[len1][len2];
    
    // Clean up the memory
    for (int i = 0; i <= len1; i++)
        free(d[i]);
    free(d);
    
    return distance;
}

// The method that brings lovers together and calculates distances
void romance_distance_calculator() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];

    // Opening lines for our heart's journey
    printf("Welcome to the Realm of Love's Distance!\n\n");
    printf("Please pour your sweet nothings into the first string:\n");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("And now, whisper your dreams into the second string:\n");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Reveal the heartfelt distance that separates them
    int distance = levenshtein_distance(str1, str2);
    printf("\nThe distance between your hearts is: %d\n", distance);
}

// The world where love conquers all, and distance is learned
int main() {
    printf("In the enchanting garden of our love, let us explore...\n");
    romance_distance_calculator();
    
    printf("Thank you for wandering through the realms of affection!\n");
    return 0;
}