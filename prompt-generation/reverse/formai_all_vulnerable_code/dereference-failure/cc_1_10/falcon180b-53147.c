//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *value;
    int length;
} Token;

int token_count = 0;
Token tokens[MAX_TOKENS];

void add_token(char *value, int length) {
    if (token_count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }

    tokens[token_count].value = value;
    tokens[token_count].length = length;

    token_count++;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;

    while ((buffer = realloc(buffer, buffer_size + 1))!= NULL) {
        int c = fgetc(file);
        if (c == EOF) {
            buffer[buffer_size] = '\0';
            break;
        }

        if (c == '\n') {
            add_token(buffer, buffer_size);
            buffer_size = 0;
        } else {
            buffer[buffer_size++] = c;
        }
    }

    if (buffer_size > 0) {
        add_token(buffer, buffer_size);
    }

    fclose(file);

    int i;
    for (i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i].value);
    }

    return 0;
}