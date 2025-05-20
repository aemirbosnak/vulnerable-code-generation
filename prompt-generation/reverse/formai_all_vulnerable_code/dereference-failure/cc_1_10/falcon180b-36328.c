//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int* d = (int*)malloc(sizeof(int) * (len1 + 1) * (len2 + 1));
    int i, j;

    for (i = 0; i <= len1; i++) {
        d[i] = (i * len2);
    }

    for (j = 0; j <= len2; j++) {
        d[0] = (j * len1);
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i * len2 + j] = d[(i - 1) * len2 + (j - 1)] + 1;
            } else {
                d[i * len2 + j] = d[(i - 1) * len2 + j] + 1;
            }
        }
    }

    int result = d[(len1 * len2) - 1];
    free(d);
    return result;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    char* s1 = argv[1];
    char* s2 = argv[2];

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}