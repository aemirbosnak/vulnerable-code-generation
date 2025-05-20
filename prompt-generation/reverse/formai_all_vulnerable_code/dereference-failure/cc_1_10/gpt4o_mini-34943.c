//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++)
        d[i] = malloc((len2 + 1) * sizeof(int));

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len1][len2];
    for (int i = 0; i <= len1; i++) free(d[i]);
    free(d);

    return distance;
}

void input_strings(char **s1, char **s2) {
    *s1 = malloc(256 * sizeof(char));
    *s2 = malloc(256 * sizeof(char));

    printf("Enter first string: ");
    fgets(*s1, 256, stdin);
    (*s1)[strcspn(*s1, "\n")] = 0; // Remove newline

    printf("Enter second string: ");
    fgets(*s2, 256, stdin);
    (*s2)[strcspn(*s2, "\n")] = 0; // Remove newline
}

int main() {
    char *str1, *str2;
    input_strings(&str1, &str2);
    int distance = levenshtein(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    free(str1);
    free(str2);
    return 0;
}