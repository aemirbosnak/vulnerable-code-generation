//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

typedef struct {
    int len;
    char str[MAX_LENGTH];
} String;

void levenshtein_distance(String str1, String str2, int *distance) {
    int m = str1.len;
    int n = str2.len;

    if (m == 0) {
        *distance = n;
        return;
    }

    if (n == 0) {
        *distance = m;
        return;
    }

    int matrix[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1.str[i - 1] == str2.str[j - 1]) ? 0 : 1;

            matrix[i][j] = min(
                matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1,
                matrix[i - 1][j - 1] + cost
            );
        }
    }

    *distance = matrix[m][n];
}

int main() {
    String str1 = {"Hello", 5};
    String str2 = {"World", 5};

    int distance;

    levenshtein_distance(str1, str2, &distance);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        }
        return c;
    }
    if (b < c) {
        return b;
    }
    return c;
}