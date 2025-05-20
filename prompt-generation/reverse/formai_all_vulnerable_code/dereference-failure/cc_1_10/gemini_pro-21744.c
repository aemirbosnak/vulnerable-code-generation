//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Calculate the Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int *d = malloc(sizeof(int) * (m + 1) * (n + 1));

    // Initialize the first row and column of the distance matrix
    for (int i = 0; i <= m; i++) {
        d[i * (n + 1)] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[j] = j;
    }

    // Calculate the rest of the distance matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i * (n + 1) + j] = min(d[(i - 1) * (n + 1) + j] + 1,  // Deletion
                                       d[i * (n + 1) + (j - 1)] + 1,  // Insertion
                                       d[(i - 1) * (n + 1) + (j - 1)] + cost);  // Substitution
        }
    }

    // Return the distance between the two strings
    int distance = d[m * (n + 1) + n];
    free(d);
    return distance;
}

// Print the usage message
void usage() {
    printf("Usage: levenshtein <string1> <string2>\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return 1;
    }

    char *s1 = argv[1];
    char *s2 = argv[2];

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}