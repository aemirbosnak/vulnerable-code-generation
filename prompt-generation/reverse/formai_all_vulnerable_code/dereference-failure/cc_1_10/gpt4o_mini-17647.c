//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100 // Maximum length for the input strings

int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    } else {
        return b < c ? b : c;
    }
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j; // Insertion cost
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,   // Deletion
                          d[i][j - 1] + 1,   // Insertion
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

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter first string (max %d characters): ", MAX_LEN - 1);
    fgets(s1, MAX_LEN, stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline
    printf("Enter second string (max %d characters): ", MAX_LEN - 1);
    fgets(s2, MAX_LEN, stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline

    int distance = levenshtein_distance(s1, s2);
    printf("Levenshtein distance between '%s' and '%s' is: %d\n", s1, s2, distance);

    return 0;
}