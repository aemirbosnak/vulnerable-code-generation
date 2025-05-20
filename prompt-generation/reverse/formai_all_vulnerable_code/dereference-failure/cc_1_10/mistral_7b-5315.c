//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char str[MAX_STRING_LENGTH];
    int len;
} StringStruct;

StringStruct createString(char* input) {
    StringStruct newString;
    strncpy(newString.str, input, MAX_STRING_LENGTH);
    newString.len = strlen(input);
    return newString;
}

void destroyString(StringStruct* string) {
    // Nothing to destroy here, just a funny name for a function
}

int calculateLevenshteinDistance(StringStruct string1, StringStruct string2) {
    int matrix[string1.len + 1][string2.len + 1];

    for (int i = 0; i <= string1.len; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= string2.len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= string1.len; i++) {
        for (int j = 1; j <= string2.len; j++) {
            int cost = (string1.str[i - 1] == string2.str[j - 1]) ? 0 : 1;

            matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[string1.len][string2.len];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    StringStruct string1 = createString(argv[1]);
    StringStruct string2 = createString(argv[2]);

    int distance = calculateLevenshteinDistance(string1, string2);

    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", string1.str, string2.str, distance);

    destroyString(&string1);
    destroyString(&string2);

    return 0;
}