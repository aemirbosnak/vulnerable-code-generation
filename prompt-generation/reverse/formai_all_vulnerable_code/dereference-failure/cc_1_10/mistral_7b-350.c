//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char str[MAX_LENGTH];
    int len;
} String;

void init_string(String* str) {
    str->len = 0;
}

void append_char(String* str, char c) {
    if (str->len >= MAX_LENGTH) {
        fprintf(stderr, "String is too long\n");
        exit(EXIT_FAILURE);
    }
    str->str[str->len++] = c;
    str->str[str->len] = '\0';
}

int levenshtein_distance(String str1, String str2) {
    int len1 = str1.len;
    int len2 = str2.len;

    if (len1 == 0)
        return len2;

    if (len2 == 0)
        return len1;

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                matrix[i][j] = j;

            if (j == 0)
                matrix[i][j] = i;

            if (str1.str[i - 1] == str2.str[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];

            else {
                matrix[i][j] = 1 + min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    String str1, str2;
    init_string(&str1);
    init_string(&str2);

    char input;

    printf("Enter first string: ");
    while ((input = getchar()) != '\n')
        append_char(&str1, input);

    printf("Enter second string: ");
    rewind(stdin);
    while ((input = getchar()) != '\n')
        append_char(&str2, input);

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);

    free(str1.str);
    free(str2.str);

    return EXIT_SUCCESS;
}