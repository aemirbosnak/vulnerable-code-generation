//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *string;
    int len;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int num_tokens;
} TokenList;

TokenList parse_line(char *line) {
    TokenList tokens;
    tokens.num_tokens = 0;

    char *token_start = line;
    char *token_end = line;

    while (*token_end != '\0') {
        while (*token_end != '\0' && isspace(*token_end)) {
            token_end++;
        }

        token_start = token_end;

        while (*token_end != '\0' && !isspace(*token_end)) {
            token_end++;
        }

        if (token_start != token_end) {
            tokens.tokens[tokens.num_tokens].string = malloc(token_end - token_start + 1);
            strncpy(tokens.tokens[tokens.num_tokens].string, token_start, token_end - token_start);
            tokens.tokens[tokens.num_tokens].len = token_end - token_start;
            tokens.num_tokens++;
        }
    }

    return tokens;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, fp) != NULL) {
        TokenList tokens = parse_line(line);

        for (int i = 0; i < tokens.num_tokens; i++) {
            printf("%s ", tokens.tokens[i].string);
        }

        printf("\n");
    }

    fclose(fp);

    return 0;
}