//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to compute the Levenshtein distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

// Function to display usage instructions
void displayUsage() {
    printf("Usage: ./levenshtein <string1> <string2>\n");
    printf("Calculate the Levenshtein distance between two strings.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        displayUsage();
        return 1;
    }

    const char *string1 = argv[1];
    const char *string2 = argv[2];

    int distance = levenshteinDistance(string1, string2);
    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    return 0;
}