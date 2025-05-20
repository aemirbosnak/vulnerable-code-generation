//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct {
    char str[MAX_LENGTH];
    int length;
} String;

String create_string(const char *input) {
    String str;
    str.length = strlen(input);
    strncpy(str.str, input, MAX_LENGTH);
    if (str.length >= MAX_LENGTH) {
        perror("Input string too long");
        exit(EXIT_FAILURE);
    }
    return str;
}

int reverse_string(String *str) {
    int i, j, len;
    char temp;

    if (str == NULL) {
        perror("Invalid string pointer");
        exit(EXIT_FAILURE);
    }

    len = str->length;
    for (i = 0, j = len - 1; i < len / 2; ++i, --j) {
        if (i >= j) break;
        temp = str->str[i];
        str->str[i] = str->str[j];
        str->str[j] = temp;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    String input, reversed;
    int result;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input = create_string(argv[1]);
    printf("Original string: %s\n", input.str);

    result = reverse_string(&input);
    if (result != EXIT_SUCCESS) {
        perror("Error reversing string");
        exit(EXIT_FAILURE);
    }

    printf("Reversed string: %s\n", input.str);

    free(input.str);
    return EXIT_SUCCESS;
}