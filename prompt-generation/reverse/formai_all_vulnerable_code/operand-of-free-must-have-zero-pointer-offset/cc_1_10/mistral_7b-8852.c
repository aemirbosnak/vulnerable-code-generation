//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    int len;
    unsigned char data[MAX_LENGTH];
} String;

void initString(String* str) {
    str->len = 0;
}

void appendString(String* str, unsigned char c) {
    str->data[str->len] = c;
    str->len++;
}

int happyLevenshteinDistance(String str1, String str2) {
    int matrix[MAX_LENGTH + 1][MAX_LENGTH + 1];
    int i, j, cost;

    for (i = 0; i <= str1.len; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= str2.len; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= str1.len; i++) {
        for (j = 1; j <= str2.len; j++) {
            if (tolower(str1.data[i - 1]) == tolower(str2.data[j - 1])) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = min(
                matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1,
                matrix[i - 1][j - 1] + cost
            );
        }
    }

    return matrix[str1.len][str2.len];
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }

    if (b <= a && b <= c) {
        return b;
    }

    return c;
}

int main(void) {
    String str1, str2;
    int distance;

    initString(&str1);
    initString(&str2);

    printf("Enter first string: ");
    while (getchar() != '\n') {
        appendString(&str1, getchar());
    }

    printf("Enter second string: ");
    while (getchar() != '\n') {
        appendString(&str2, getchar());
    }

    distance = happyLevenshteinDistance(str1, str2);

    printf("Levenshtein Distance: %d\n", distance);

    free(str1.data);
    free(str2.data);

    return EXIT_SUCCESS;
}