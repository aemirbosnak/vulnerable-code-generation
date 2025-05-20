//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// paranoid paranoia
#define PARANOIA_LEVEL 100

// paranoia macros
#define PARANOID(msg) { fprintf(stderr, "PARANOIA: %s\n", msg); exit(1); }
#define PARANOID_CHECK(cond) { if (!(cond)) { PARANOID("Condition failed"); } }
#define PARANOID_ASSERT(cond) { if (!(cond)) { PARANOID("Assertion failed"); } }

// paranoid string functions
char *paranoid_strcpy(char *dst, const char *src) {
    PARANOID_CHECK(dst != NULL);
    PARANOID_CHECK(src != NULL);
    char *ret = strcpy(dst, src);
    PARANOID_CHECK(ret != NULL);
    return ret;
}

int paranoid_strlen(const char *str) {
    PARANOID_CHECK(str != NULL);
    int len = strlen(str);
    PARANOID_CHECK(len >= 0);
    return len;
}

int paranoid_strcmp(const char *str1, const char *str2) {
    PARANOID_CHECK(str1 != NULL);
    PARANOID_CHECK(str2 != NULL);
    int cmp = strcmp(str1, str2);
    PARANOID_CHECK(cmp >= 0);
    return cmp;
}

// paranoid Levenshtein distance function
int paranoid_levenshtein_distance(const char *str1, const char *str2) {
    PARANOID_CHECK(str1 != NULL);
    PARANOID_CHECK(str2 != NULL);

    int len1 = paranoid_strlen(str1);
    int len2 = paranoid_strlen(str2);

    // create a matrix to store the Levenshtein distances
    int matrix[len1 + 1][len2 + 1];

    // initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // calculate the Levenshtein distances for the rest of the matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = paranoid_strcmp(str1 + i - 1, str2 + j - 1) == 0 ? 0 : 1;
            int min = INT_MAX;
            min = min < matrix[i - 1][j    ] ? min : matrix[i - 1][j    ];
            min = min < matrix[i    ][j - 1] ? min : matrix[i    ][j - 1];
            min = min < matrix[i - 1][j - 1] + cost ? min : matrix[i - 1][j - 1] + cost;
            matrix[i][j] = min;
        }
    }

    // return the Levenshtein distance
    return matrix[len1][len2];
}

// paranoid main function
int main(int argc, char **argv) {
    PARANOID_CHECK(argc == 3);
    PARANOID_CHECK(argv[1] != NULL);
    PARANOID_CHECK(argv[2] != NULL);

    char str1[PARANOIA_LEVEL];
    char str2[PARANOIA_LEVEL];
    paranoid_strcpy(str1, argv[1]);
    paranoid_strcpy(str2, argv[2]);

    int distance = paranoid_levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);

    return 0;
}