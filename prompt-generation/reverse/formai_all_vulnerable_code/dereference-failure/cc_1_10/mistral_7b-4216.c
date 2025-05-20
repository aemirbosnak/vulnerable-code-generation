//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int min_del_ins(int cost, int prev_cost, int n, int m) {
    return MAX(MAX(cost, prev_cost), n + m - 2 * (n > m ? n : m));
}

int levenshtein_distance(const char *str1, const char *str2, int len1, int len2) {
    int dp_matrix[len1 + 1][len2 + 1];
    bool first_row_initialized = false;
    bool first_column_initialized = false;

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (first_row_initialized && first_column_initialized) {
                dp_matrix[i][j] = min_del_ins(i > 0 && str1[i - 1] == str2[j - 1] ? 0 : 1,
                                            i > 0 ? dp_matrix[i - 1][j] : len1,
                                            len1, len2);
            }

            if (i == 0) {
                dp_matrix[i][j] = j;
                first_column_initialized = true;
            }

            if (j == 0) {
                dp_matrix[i][j] = i;
                first_row_initialized = true;
            }
        }
    }

    return dp_matrix[len1][len2];
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    const char *str1 = argv[1];
    const char *str2 = argv[2];

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}