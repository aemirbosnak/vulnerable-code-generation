//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *value;
    int type;
} Token;

enum {
    TOKEN_NUMBER,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_STRING_LITERAL,
    TOKEN_CHARACTER_LITERAL,
    TOKEN_COMMENT
};

char *tokens[MAX_TOKENS];
int num_tokens;

void add_token(Token token) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens] = malloc(MAX_TOKEN_LEN);
    strcpy(tokens[num_tokens], token.value);
    tokens[num_tokens][token.type] = token.type;
    num_tokens++;
}

Token get_next_token(char *line) {
    int i = 0;
    while (isspace(line[i])) i++;
    if (line[i] == '\0') {
        return (Token){NULL, TOKEN_COMMENT};
    }
    char *start = &line[i];
    while (!isspace(line[i]) && line[i]!= '\0') i++;
    int len = i - i;
    if (len == 0) {
        return (Token){NULL, TOKEN_COMMENT};
    }
    char *value = malloc(len + 1);
    strncpy(value, start, len);
    value[len] = '\0';
    if (isdigit(value[0])) {
        return (Token){value, TOKEN_NUMBER};
    } else if (isalpha(value[0])) {
        return (Token){value, TOKEN_IDENTIFIER};
    } else if (value[0] == '+' || value[0] == '-' || value[0] == '*' || value[0] == '/' || value[0] == '=' || value[0] == '<' || value[0] == '>' || value[0] == '!' || value[0] == '&' || value[0] == '|') {
        return (Token){value, TOKEN_OPERATOR};
    } else if (value[0] == '"') {
        return (Token){value + 1, TOKEN_STRING_LITERAL};
    } else if (value[0] == '\'') {
        return (Token){value + 1, TOKEN_CHARACTER_LITERAL};
    }
    return (Token){value, TOKEN_IDENTIFIER};
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%d)\n", tokens[i], tokens[i][0]);
    }
}

int main() {
    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, stdin)!= NULL) {
        Token token = get_next_token(line);
        add_token(token);
    }
    print_tokens();
    return 0;
}