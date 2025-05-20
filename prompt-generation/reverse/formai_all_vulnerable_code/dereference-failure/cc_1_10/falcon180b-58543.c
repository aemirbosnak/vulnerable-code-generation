//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LENGTH 100

bool is_vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **matrix = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));
    }

    int cost = 1;
    int j = 0;
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                if (is_vowel(s1[i - 1]) && is_vowel(s2[j - 1])) {
                    cost = 2;
                }
            }
        }
    }

    free(matrix[0]);
    free(matrix);

    return matrix[len1][len2];
}

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    int distance = levenshtein_distance(string1, string2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", string1, string2, distance);

    return 0;
}