//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_SIZE 20

struct Token {
    int id;
    char value[MAX_TOKEN_SIZE];
};

int count_tokens(char *line) {
    int count = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

void parse_line(char *line, struct Token *tokens, int *token_count) {
    char *token = strtok(line, " ");
    int id = 0;
    while (token != NULL) {
        struct Token t = {id++, "\0"};
        strcpy(t.value, token);
        tokens[*token_count] = t;
        (*token_count)++;
        token = strtok(NULL, " ");
    }
}

void print_tokens(struct Token *tokens, int token_count) {
    printf("TOKENS: \n");
    for (int i = 0; i < token_count; i++) {
        printf("%d: %s\n", tokens[i].id, tokens[i].value);
    }
}

int main() {

    char *line = "int main() { return 0; }";
    int token_count = 0;
    struct Token tokens[MAX_TOKENS];

    printf("LINE: %s\n", line);

    token_count = count_tokens(line);
    parse_line(line, tokens, &token_count);
    print_tokens(tokens, token_count);

    return EXIT_SUCCESS;
}