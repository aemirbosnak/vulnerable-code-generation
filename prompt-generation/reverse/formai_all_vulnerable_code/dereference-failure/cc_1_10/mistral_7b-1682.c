//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char *str1;
    char *str2;
    int len1;
    int len2;
} string_pair;

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

void calculate_levenshtein_distance(string_pair sp) {
    int i, j, cost;
    int *prev_row = malloc((sp.len1 + 1) * sizeof(int));
    int *current_row = malloc((sp.len1 + 1) * sizeof(int));

    for (i = 0; i <= sp.len1; i++) {
        prev_row[i] = i;
    }

    for (j = 0; j <= sp.len2; j++) {
        current_row[0] = j;

        for (i = 1; i <= sp.len1; i++) {
            cost = (tolower(sp.str1[i - 1]) == tolower(sp.str2[j - 1])) ? 0 : 1;
            current_row[i] = min(prev_row[i - 1] + 1, current_row[i - 1] + 1, prev_row[i] + cost);
        }

        int temp = *prev_row;
        *prev_row = *current_row;
        *current_row = temp;
    }

    printf("Levenshtein Distance between %s and %s: %d\n", sp.str1, sp.str2, *prev_row);

    free(prev_row);
    free(current_row);
}

int main() {
    char *str1 = "programming";
    char *str2 = "computer science";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    string_pair sp = {str1, str2, len1, len2};
    calculate_levenshtein_distance(sp);

    free(str1);
    free(str2);

    return 0;
}