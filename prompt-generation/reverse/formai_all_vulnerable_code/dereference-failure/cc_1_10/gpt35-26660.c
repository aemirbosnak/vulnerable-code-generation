//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int levenshteinDistance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int *prev = calloc(len2 + 1, sizeof(int));
    int *curr = calloc(len2 + 1, sizeof(int));
    int i, j;
    for (j = 1; j <= len2; j++) {
        prev[j] = j;
    }
    for (i = 1; i <= len1; i++) {
        curr[0] = i;
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = prev[j - 1];
            } else {
                curr[j] = min(prev[j - 1], prev[j], curr[j - 1]) + 1;
            }
        }
        memcpy(prev, curr, sizeof(int) * (len2 + 1));
    }
    int distance = curr[len2];
    free(prev);
    free(curr);
    return distance;
}

int main() {
    char s1[100];
    char s2[100];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshteinDistance(s1, s2);

    printf("The Levenshtein distance between %s and %s is %d", s1, s2, distance);
    return 0;
}