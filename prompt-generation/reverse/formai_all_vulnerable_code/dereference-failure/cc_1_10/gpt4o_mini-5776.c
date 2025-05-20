//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This noble function gladly takes two strings from its master,
// to find the distance between them as if they were rival knights.
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// This structure, the realm's table of distances, holds all necessary values
void lev_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // A table of integers, to keep track of costs
    int **dist = malloc((len1 + 1) * sizeof(int *));
    for(int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Populate the first row and first column of the table
    for(int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Cost of deletions
    }
    for(int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Cost of insertions
    }

    // The main act of computing the distance takes place here
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            dist[i][j] = min(dist[i-1][j] + 1,    // Deletion
                             dist[i][j-1] + 1,    // Insertion
                             dist[i-1][j-1] + cost); // Substitution
        }
    }

    // The distance stands proudly in the last cell of the table
    printf("The noble Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, dist[len1][len2]);

    // Releasing the memory of the table, for the favor of future knights
    for(int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);
}

// The grand feasting hall where our tale begins
int main() {
    char str1[100];
    char str2[100];

    printf("Enter the first noble string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Fret not, we remove the newline

    printf("Enter the second noble string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Fret not, we remove the newline

    lev_distance(str1, str2);

    return 0; // The end of our quest for distance
}