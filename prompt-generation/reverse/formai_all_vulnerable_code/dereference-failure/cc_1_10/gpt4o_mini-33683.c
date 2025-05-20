//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (size_t i = 0; i <= len_s1; i++) {
        d[i][0] = i; // delete all characters from s1
    }
    for (size_t j = 0; j <= len_s2; j++) {
        d[0][j] = j; // insert all characters to s2
    }

    for (size_t i = 1; i <= len_s1; i++) {
        for (size_t j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(
                d[i - 1][j] + 1,     // Deletion
                d[i][j - 1] + 1,     // Insertion
                d[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    int distance = d[len_s1][len_s2];

    for (size_t i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void print_instructions() {
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Enter two strings to calculate the distance between them.\n");
}

int main() {
    print_instructions();

    char s1[100], s2[100];
    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}