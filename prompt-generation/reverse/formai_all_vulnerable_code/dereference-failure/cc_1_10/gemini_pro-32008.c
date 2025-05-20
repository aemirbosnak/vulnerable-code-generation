//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
    int cost;
    int prev_row;
    int prev_col;
} cell;

int levenshtein_distance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    cell **d = (cell **) malloc((m + 1) * sizeof(cell *));
    for (int i = 0; i <= m; i++) {
        d[i] = (cell *) malloc((n + 1) * sizeof(cell));
    }
    for (int i = 0; i <= m; i++) {
        d[i][0].cost = i;
        d[i][0].prev_row = i - 1;
        d[i][0].prev_col = 0;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j].cost = j;
        d[0][j].prev_row = 0;
        d[0][j].prev_col = j - 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            int min_cost = MIN(d[i - 1][j].cost + 1, d[i][j - 1].cost + 1);
            min_cost = MIN(min_cost, d[i - 1][j - 1].cost + cost);
            d[i][j].cost = min_cost;
            if (min_cost == d[i - 1][j].cost + 1) {
                d[i][j].prev_row = i - 1;
                d[i][j].prev_col = j;
            } else if (min_cost == d[i][j - 1].cost + 1) {
                d[i][j].prev_row = i;
                d[i][j].prev_col = j - 1;
            } else {
                d[i][j].prev_row = i - 1;
                d[i][j].prev_col = j - 1;
            }
        }
    }
    int distance = d[m][n].cost;
    free(d[0]);
    free(d);
    return distance;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    const char *s1 = argv[1];
    const char *s2 = argv[2];
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);
    return 0;
}