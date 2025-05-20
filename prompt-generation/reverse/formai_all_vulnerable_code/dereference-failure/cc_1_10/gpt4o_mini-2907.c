//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

int levenshtein(const char *s1, const char *s2) {
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
            int substitution_cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + substitution_cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void print_usage(const char *program_name) {
    printf("Usage: %s <string1> <string2>\n", program_name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    const char *s1 = argv[1];
    const char *s2 = argv[2];

    printf("Calculating Levenshtein distance between:\n\"%s\"\n\"%s\"\n", s1, s2);
    
    int distance = levenshtein(s1, s2);
    printf("Levenshtein Distance: %d\n", distance);
    
    return 0;
}