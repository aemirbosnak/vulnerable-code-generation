//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to find the minimum of three integers */
int min(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

/* Function to calculate the Levenshtein Distance */
int levenshtein_distance(const char *s, const char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int **d = malloc((n + 1) * sizeof(int *));
    
    for (int i = 0; i <= n; i++)
        d[i] = malloc((m + 1) * sizeof(int));
    
    // Initialize the distance matrix
    for (int i = 0; i <= n; i++)
        d[i][0] = i;
    for (int j = 0; j <= m; j++)
        d[0][j] = j;

    // Calculate distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[n][m];

    // Free allocated memory
    for (int i = 0; i <= n; i++)
        free(d[i]);
    free(d);

    return distance;
}

/* Main Function to show off the Levenshtein Dance! */
int main() {
    char str1[100], str2[100];

    // Surprise! Let's gather some strings in a funky way!
    printf("🎉 Welcome to the Levenshtein Distance Calculator! 🎉\n");
    printf("Please enter the first string (max 99 chars): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Now, for the second string (max 99 chars): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Surprise twist: Let's reveal the distance!
    int distance = levenshtein_distance(str1, str2);
    
    // Drum roll please! 🥁🥁
    printf("🤯 The Levenshtein Distance between \"%s\" and \"%s\" is: %d 🤯\n", str1, str2, distance);

    // A fun fact? Try it with different strings to uncover more magical distances!
    printf("✨ Keep calculating! Refresh your strings for more surprises! ✨\n");

    return 0;
}