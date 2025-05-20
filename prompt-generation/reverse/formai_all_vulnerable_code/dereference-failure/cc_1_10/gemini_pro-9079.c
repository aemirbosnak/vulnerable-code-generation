//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

// Linus Torvalds style
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// Levenshtein distance calculator
int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int matrix[len1 + 1][len2 + 1];

    // Initialize the first row and column
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = MIN(matrix[i - 1][j] + 1, // Deletion
                               MIN(matrix[i][j - 1] + 1, // Insertion
                                   matrix[i - 1][j - 1] + cost)); // Substitution
        }
    }

    return matrix[len1][len2];
}

int main(int argc, char **argv) {
    // Check if the user provided two strings
    if (argc < 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Calculate the Levenshtein distance
    int distance = levenshtein(argv[1], argv[2]);

    // Print the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", argv[1], argv[2], distance);

    return 0;
}