//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int cost = 0;

    if (len1 == 0) {
        return len2;
    }

    if (len2 == 0) {
        return len1;
    }

    if (str1[len1-1] == str2[len2-1]) {
        cost = 0;
    }
    else {
        cost = 1;
    }

    return min(levenshtein_distance(str1, str2, len1-1, len2) + 1,
               levenshtein_distance(str1, str2, len1, len2-1) + 1,
               levenshtein_distance(str1, str2, len1-1, len2-1) + cost);
}

int main() {
    char str1[100], str2[100];
    int len1, len2, dist;

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    len1 = strlen(str1);
    if (str1[len1-1] == '\n') {
        str1[len1-1] = '\0';
        len1--;
    }

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    len2 = strlen(str2);
    if (str2[len2-1] == '\n') {
        str2[len2-1] = '\0';
        len2--;
    }

    dist = levenshtein_distance(str1, str2, len1, len2);

    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, dist);

    return 0;
}