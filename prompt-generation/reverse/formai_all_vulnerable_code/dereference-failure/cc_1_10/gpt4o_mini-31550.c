//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
int min(int a, int b, int c);
int levenshtein_distance(const char *s, const char *t);

int main() {
    char str1[100], str2[100];

    // Welcome message
    printf("🎉 Welcome to the Levenshtein Distance Calculator! 🎉\n");
    printf("✨ This magical program will help you find the distance between two strings! ✨\n\n");

    // User input
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character

    printf("Now, enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate distance
    int distance = levenshtein_distance(str1, str2);
    printf("\n🔥 The Levenshtein distance between \"%s\" and \"%s\" is: %d 🔥\n", str1, str2, distance);
    
    printf("\n🤖 Thanks for using the Levenshtein Distance Calculator! Until next time! 🤖\n");
    return 0;
}

// Function to find the minimum of three values
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // Create a distance matrix
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    for (int i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s; i++) d[i][0] = i;
    for (int j = 0; j <= len_t; j++) d[0][j] = j;

    // Fill the matrix
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,   // Deletion
                          d[i][j - 1] + 1,   // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = d[len_s][len_t];

    // Free the memory used for the matrix
    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}