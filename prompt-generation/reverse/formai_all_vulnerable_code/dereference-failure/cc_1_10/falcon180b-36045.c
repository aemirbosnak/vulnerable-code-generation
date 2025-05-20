//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *value;
    int length;
} token_t;

int main(int argc, char *argv[]) {
    FILE *input_file;
    char *filename = argv[1];
    char *buffer = malloc(MAX_TOKEN_LENGTH);
    int buffer_index = 0;
    int token_count = 0;
    token_t tokens[MAX_TOKENS];

    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(buffer, MAX_TOKEN_LENGTH, input_file)!= NULL) {
        int i = 0;
        while (buffer[i]!= '\0') {
            if (isalpha(buffer[i])) {
                if (token_count >= MAX_TOKENS) {
                    printf("Maximum number of tokens reached\n");
                    exit(1);
                }
                tokens[token_count].value = malloc(MAX_TOKEN_LENGTH);
                strncpy(tokens[token_count].value, &buffer[i], MAX_TOKEN_LENGTH);
                tokens[token_count].length = strlen(tokens[token_count].value);
                token_count++;
            }
            i++;
        }
    }

    fclose(input_file);

    printf("Number of tokens: %d\n", token_count);

    for (int i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i, tokens[i].value);
    }

    for (int i = 0; i < token_count; i++) {
        free(tokens[i].value);
    }

    free(buffer);

    return 0;
}