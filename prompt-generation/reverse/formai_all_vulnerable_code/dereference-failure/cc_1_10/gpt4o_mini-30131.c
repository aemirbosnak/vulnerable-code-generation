//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) 
        return a;
    else if (b <= a && b <= c) 
        return b;
    return c;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dist = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++)
        dist[i] = (int *)malloc((len2 + 1) * sizeof(int));
    
    // Initialize the distance array
    for (int i = 0; i <= len1; i++)
        dist[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dist[0][j] = j;

    // Fill in the distance array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) 
                dist[i][j] = dist[i - 1][j - 1];  // No cost if the characters match
            else 
                dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                                 dist[i][j - 1] + 1,    // Insertion
                                 dist[i - 1][j - 1] + 1);// Substitution
        }
    }

    int distance = dist[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++)
        free(dist[i]);
    free(dist);

    return distance;
}

// Function to softly whisper the result of the distance
void whisper_result(const char *str1, const char *str2, int distance) {
    printf("Oh sweet darling,\n");
    printf("As I wander through the textual gardens of love,\n");
    printf("I found myself counting the steps,\n");
    printf("Between the words \"%s\" and \"%s\",\n", str1, str2);
    printf("The Levenshtein Distance is a gentle breeze of: %d\n", distance);
    printf("Every step we take, every letter missed,\n");
    printf("Shall bring our hearts closer, as if kissed.\n");
}

int main() {
    // The lover's names, as soft as the dawn
    char str1[100];
    char str2[100];

    // Romantic prompts to capture the heart
    printf("Enter your beloved's name: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove newline character

    printf("Enter your cherished name: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove newline character

    // Calculate the distance with a fluttering heart
    int distance = levenshtein_distance(str1, str2);

    // Whisper the result
    whisper_result(str1, str2, distance);
    
    return 0;
}