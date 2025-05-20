//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void levenshtein_distance(char *str1, char *str2, int *dist) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) {
        *dist = len2;
        return;
    }

    if (len2 == 0) {
        *dist = len1;
        return;
    }

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;

            matrix[i][j] = min(
                matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1,
                matrix[i - 1][j - 1] + cost
            );
        }
    }

    *dist = matrix[len1][len2];
}

int main(int argc, char *argv[]) {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int dist;

    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    levenshtein_distance(str1, str2, &dist);

    printf("Levenshtein Distance: %d\n", dist);

    return 0;
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