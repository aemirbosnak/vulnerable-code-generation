//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

struct token {
    char *name;
    int type;
};

typedef struct token token_t;

void parse_program(char *program) {
    char *ptr = program;
    token_t *tokens = malloc(sizeof(token_t) * 10);
    int i = 0;

    while (*ptr != '\0') {
        if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            tokens[i].name = ptr;
            tokens[i].type = *ptr;
            i++;
        } else if (*ptr == '(' || *ptr == ')') {
            tokens[i].name = ptr;
            tokens[i].type = *ptr;
            i++;
        } else if (*ptr == ',' || *ptr == ';') {
            tokens[i].name = ptr;
            tokens[i].type = *ptr;
            i++;
        } else {
            tokens[i].name = ptr;
            tokens[i].type = ' ';
        }
        ptr++;
    }

    // Print the tokens
    for (int j = 0; j < i; j++) {
        printf("%d: %s (%c)\n", j, tokens[j].name, tokens[j].type);
    }

    free(tokens);
}

int main() {
    char program[] = "+++ 5 * (3 + 2) / 2 + 1;";
    parse_program(program);
    return 0;
}