//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

/**
 * This function calculates the Levenshtein distance between two strings.
 * The Levenshtein distance is defined as the minimum number of single-character
 * edits (insertions, deletions or substitutions) needed to change one string into the other.
 */
int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Use a dynamically allocated 2D array to store the distance values
    int **dist = (int**)malloc((len1+1)*sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int*)malloc((len2+1)*sizeof(int));
    }

    // Initialize the first row and first column of the array with increasing values
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the distance value for each remaining cell of the array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int substitutionCost = (s1[i-1] == s2[j-1]) ? 0 : 1; // substitution cost is 0 if the characters are the same, otherwise 1
            int deletionCost = dist[i-1][j] + 1;
            int insertionCost = dist[i][j-1] + 1;
            int substitutionOrMatchCost = dist[i-1][j-1] + substitutionCost;
            dist[i][j] = minimumOfFour(deletionCost, insertionCost, substitutionOrMatchCost);
        }
    }

    // The final value in the array is the Levenshtein distance
    int result = dist[len1][len2];

    // Free the dynamically allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return result;
}

// A helper function to calculate the minimum of four integers
int minimumOfFour(int a, int b, int c, int d) {
    int min1 = (a < b) ? a : b;
    int min2 = (c < d) ? c : d;
    return (min1 < min2) ? min1 : min2;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter the first string: ");
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = '\0'; // remove the newline character from the input string

    printf("Enter the second string: ");
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\n")] = '\0'; // remove the newline character from the input string

    int dist = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, dist);

    return 0;
}