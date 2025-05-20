//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 1000
#define MAX_DIFF 1000

/* Function to calculate the Levenshtein distance between two strings */
int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **mat = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        mat[i] = (int *) malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i <= len1; i++) {
        mat[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        mat[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                mat[i][j] = mat[i-1][j-1];
            } else {
                mat[i][j] = (mat[i][j-1] > mat[i-1][j])? mat[i][j-1] : mat[i-1][j];
                mat[i][j] += 1;
            }
        }
    }

    return mat[len1][len2];
}

int main(int argc, char *argv[]) {
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Enter two strings: ");
    scanf("%s%s", s1, s2);

    int dist = levenshtein(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, dist);

    return 0;
}