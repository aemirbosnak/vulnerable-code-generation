//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_IDENTIFIER,
    TOKEN_KEYWORD,
    TOKEN_PUNCTUATOR,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH + 1];
} Token;

Token token;

void next_token(FILE *fp) {
    char ch = fgetc(fp);
    if (ch == EOF) {
        token.type = TOKEN_END;
        return;
    }

    if (isdigit(ch)) {
        token.type = TOKEN_NUMBER;
        int i = 0;
        while (isdigit(ch) && i < MAX_TOKEN_LENGTH) {
            token.value[i++] = ch;
            ch = fgetc(fp);
        }
        ungetc(ch, fp);
        token.value[i] = '\0';
    } else if (isalpha(ch) || ch == '_') {
        token.type = TOKEN_IDENTIFIER;
        int i = 0;
        while ((isalnum(ch) || ch == '_') && i < MAX_TOKEN_LENGTH) {
            token.value[i++] = ch;
            ch = fgetc(fp);
        }
        ungetc(ch, fp);
        token.value[i] = '\0';
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        token.type = TOKEN_OPERATOR;
        token.value[0] = ch;
        token.value[1] = '\0';
    } else if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';' || ch == ',') {
        token.type = TOKEN_PUNCTUATOR;
        token.value[0] = ch;
        token.value[1] = '\0';
    } else {
        next_token(fp);
    }
}

int parse_primary_expression(FILE *fp) {
    if (token.type == TOKEN_NUMBER) {
        int value = atoi(token.value);
        next_token(fp);
        return value;
    } else if (token.type == TOKEN_IDENTIFIER) {
        next_token(fp);
        // TODO: handle function calls and variable references
        return 0;
    } else {
        printf("Error: expected number or identifier\n");
        exit(1);
    }
}

int parse_multiplicative_expression(FILE *fp) {
    int value = parse_primary_expression(fp);
    while (token.type == TOKEN_OPERATOR && (strcmp(token.value, "*") == 0 || strcmp(token.value, "/") == 0)) {
        char op = token.value[0];
        next_token(fp);
        int rhs = parse_primary_expression(fp);
        if (op == '*') {
            value *= rhs;
        } else {
            value /= rhs;
        }
    }
    return value;
}

int parse_additive_expression(FILE *fp) {
    int value = parse_multiplicative_expression(fp);
    while (token.type == TOKEN_OPERATOR && (strcmp(token.value, "+") == 0 || strcmp(token.value, "-") == 0)) {
        char op = token.value[0];
        next_token(fp);
        int rhs = parse_multiplicative_expression(fp);
        if (op == '+') {
            value += rhs;
        } else {
            value -= rhs;
        }
    }
    return value;
}

int parse_expression(FILE *fp) {
    return parse_additive_expression(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fmemopen(argv[1], strlen(argv[1]), "r");
    if (!fp) {
        printf("Error: failed to open input string as file stream\n");
        exit(1);
    }

    next_token(fp);
    int result = parse_expression(fp);

    if (token.type != TOKEN_END) {
        printf("Error: unexpected token at end of expression\n");
        exit(1);
    }

    printf("%d\n", result);

    fclose(fp);

    return 0;
}