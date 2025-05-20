//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int levenshtein_distance(const char *s, const char *t) {
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    
    for (size_t i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    for (size_t i = 0; i <= len_s; i++) {
        d[i][0] = i;
    }

    for (size_t j = 0; j <= len_t; j++) {
        d[0][j] = j;
    }

    for (size_t i = 1; i <= len_s; i++) {
        for (size_t j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s][len_t];

    for (size_t i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void greet_user() {
    printf("===================================\n");
    printf(" Welcome to the Levenshtein Distance\n");
    printf(" Calculator!\n");
    printf("===================================\n");
    printf("This calculator will help you find\n");
    printf("the minimum number of edits between\n");
    printf("two strings. Let's get started!\n");
    printf("===================================\n");
}

int main() {
    greet_user();

    char *string1 = (char *)malloc(256 * sizeof(char));
    char *string2 = (char *)malloc(256 * sizeof(char));

    printf("Please enter the first string: ");
    fgets(string1, 256, stdin);
    string1[strcspn(string1, "\n")] = 0; // Removing newline character

    printf("Please enter the second string: ");
    fgets(string2, 256, stdin);
    string2[strcspn(string2, "\n")] = 0; // Removing newline character

    int distance = levenshtein_distance(string1, string2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", string1, string2, distance);

    // Clean up memory
    free(string1);
    free(string2);
    
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
    return 0;
}