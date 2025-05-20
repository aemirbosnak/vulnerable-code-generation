//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct LevenshteinDistance {
    int distance;
    int *predecessors;
} LevenshteinDistance;

LevenshteinDistance levenshteinDistance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int **d = malloc(sizeof(int *) * (m + 1));

    for (int i = 0; i <= m; i++) {
        d[i] = malloc(sizeof(int) * (n + 1));
        d[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[m][n];
    int *predecessors = malloc(sizeof(int) * (distance + 1));
    int i = m;
    int j = n;
    int k = distance - 1;

    while (i > 0 && j > 0) {
        int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
        if (d[i][j] == d[i - 1][j] + 1) {
            predecessors[k--] = 0;
            i--;
        } else if (d[i][j] == d[i][j - 1] + 1) {
            predecessors[k--] = 1;
            j--;
        } else {
            predecessors[k--] = 2;
            i--;
            j--;
        }
    }

    while (i > 0) {
        predecessors[k--] = 0;
        i--;
    }

    while (j > 0) {
        predecessors[k--] = 1;
        j--;
    }

    free(d);
    return (LevenshteinDistance) { .distance = distance, .predecessors = predecessors };
}

void printLevenshteinDistance(LevenshteinDistance result, const char *s1, const char *s2) {
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, result.distance);

    if (result.distance > 0) {
        printf("Predecessors:\n");
        for (int i = 0; i < result.distance; i++) {
            switch (result.predecessors[i]) {
                case 0:
                    printf("  Delete character from \"%s\"\n", s1);
                    break;
                case 1:
                    printf("  Insert character into \"%s\"\n", s2);
                    break;
                case 2:
                    printf("  Replace character in \"%s\" with character in \"%s\"\n", s1, s2);
                    break;
            }
        }
    }

    free(result.predecessors);
}

int main() {
    LevenshteinDistance result = levenshteinDistance("kitten", "sitting");
    printLevenshteinDistance(result, "kitten", "sitting");

    return 0;
}