//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *string;
    int length;
} string_t;

int count_char(string_t *string, char c) {
    int count = 0;
    for (int i = 0; i < string->length; i++) {
        if (string->string[i] == c) {
            count++;
        }
    }
    return count;
}

void compress(string_t *string) {
    int i = 0;
    int j = 0;
    while (i < string->length) {
        int count = 1;
        while (i + count < string->length && string->string[i] == string->string[i + count]) {
            count++;
        }
        if (count > 1) {
            string->string[j++] = string->string[i];
            i += count;
        } else {
            i++;
        }
    }
    string->length = j;
}

int main() {
    string_t input;
    input.string = (char*)malloc(MAX_LENGTH * sizeof(char));
    input.length = 0;

    printf("Enter a string: ");
    fgets(input.string, MAX_LENGTH, stdin);
    input.length = strlen(input.string);

    compress(&input);

    printf("Compressed string: ");
    for (int i = 0; i < input.length; i++) {
        printf("%c", input.string[i]);
    }
    printf("\n");

    free(input.string);
    return 0;
}