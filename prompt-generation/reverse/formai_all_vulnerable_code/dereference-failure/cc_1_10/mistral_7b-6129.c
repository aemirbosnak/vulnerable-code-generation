//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void print_matrix(int dist[][MAX_LENGTH], int len1, int len2) {
    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            printf("%2d ", dist[i][j]);
        }
        printf("\n");
    }
}

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int dist[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= len1; ++i) {
        dist[i][0] = i;
    }

    for (int j = 0; j <= len2; ++j) {
        dist[0][j] = j;
    }

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            char c1 = str1[i - 1];
            char c2 = str2[j - 1];

            int cost = isalpha(c1) && isalpha(c2) ? abs(tolower(c1) - tolower(c2)) : 1;

            dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j - 1] + 1, dist[i - 1][j - 1] + cost);
        }
    }

    return dist[len1][len2];
}

int main(void) {
    char str1[MAX_LENGTH] = "Kitten";
    char str2[MAX_LENGTH] = "Sitting";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dist = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", dist);

    int dist_matrix[len1 + 1][len2 + 1];
    memcpy(dist_matrix, dist, sizeof(dist));

    print_matrix(dist_matrix, len1, len2);

    return EXIT_SUCCESS;
}