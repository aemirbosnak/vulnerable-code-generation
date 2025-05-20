//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    int value;
} token;

int num_tokens = 0;
token tokens[MAX_TOKENS];

char *get_token(char *line) {
    char *token_start = line;
    while (*line && isspace(*line)) {
        line++;
    }
    if (*line == '\0') {
        return NULL;
    }
    char *token_end = line;
    while (*line &&!isspace(*line)) {
        line++;
    }
    int token_len = line - token_end;
    if (token_len >= MAX_TOKEN_LEN) {
        printf("Error: token too long\n");
        exit(1);
    }
    char *token = malloc(token_len + 1);
    strncpy(token, token_end, token_len);
    token[token_len] = '\0';
    return token;
}

void add_token(char *name, int value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = value;
    num_tokens++;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *token = get_token(line);
        if (token == NULL) {
            continue;
        }
        add_token(token, 0);
    }
    fclose(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        exit(1);
    }
    for (int i = 0; i < num_tokens; i++) {
        fprintf(output_file, "%s = %d;\n", tokens[i].name, tokens[i].value);
    }
    fclose(output_file);

    return 0;
}