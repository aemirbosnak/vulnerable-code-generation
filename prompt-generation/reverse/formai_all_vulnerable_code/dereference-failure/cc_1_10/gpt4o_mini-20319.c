//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(const char *program_name) {
    printf("Usage: %s <string1> <string2>\n", program_name);
    printf("Calculate the Levenshtein distance between two strings.\n");
}

int min(int a, int b, int c) {
    int minimum = a < b ? a : b;
    return minimum < c ? minimum : c;
}

int levenshtein_distance(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int **d = malloc((len_s + 1) * sizeof(int *));
    for (int i = 0; i <= len_s; i++) {
        d[i] = malloc((len_t + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j; // Insertion cost
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s][len_t];

    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);
    return distance;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *string1 = argv[1];
    const char *string2 = argv[2];

    int distance = levenshtein_distance(string1, string2);

    printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    return EXIT_SUCCESS;
}