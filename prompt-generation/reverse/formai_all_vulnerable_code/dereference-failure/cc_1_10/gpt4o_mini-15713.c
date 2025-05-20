//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    }
    return (b < c) ? b : c;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize distance
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost // Substitution
                         );
        }
    }

    int distance = d[len1][len2];

    // Clean up
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter first string (max %d characters): ", MAX_LEN - 1);
    if (fgets(str1, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading first string.\n");
        return 1;
    }
    str1[strcspn(str1, "\n")] = 0; // Remove newline

    printf("Enter second string (max %d characters): ", MAX_LEN - 1);
    if (fgets(str2, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "Error reading second string.\n");
        return 1;
    }
    str2[strcspn(str2, "\n")] = 0; // Remove newline

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}