//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token {
    int type;
    char *value;
};

struct token_list {
    struct token *tokens;
    int size;
    int capacity;
};

enum token_type {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_KEYWORD,
};

struct token_list *token_list_create() {
    struct token_list *list = malloc(sizeof(*list));
    list->tokens = NULL;
    list->size = 0;
    list->capacity = 0;
    return list;
}

void token_list_destroy(struct token_list *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->tokens[i].value);
    }
    free(list->tokens);
    free(list);
}

void token_list_add(struct token_list *list, struct token token) {
    if (list->size >= list->capacity) {
        list->capacity = list->capacity == 0 ? 4 : list->capacity * 2;
        list->tokens = realloc(list->tokens, list->capacity * sizeof(*list->tokens));
    }
    list->tokens[list->size++] = token;
}

struct token token_create(int type, char *value) {
    struct token token;
    token.type = type;
    token.value = strdup(value);
    return token;
}

struct token_list *lex(char *input) {
    struct token_list *list = token_list_create();
    int i = 0;
    while (input[i] != '\0') {
        char c = input[i++];
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                continue;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            case '&':
            case '|':
            case '~':
            case '!':
            case '=':
            case '<':
            case '>':
                token_list_add(list, token_create(TOKEN_OPERATOR, &c));
                continue;
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
            case ';':
            case ',':
            case '.':
                token_list_add(list, token_create(TOKEN_PUNCTUATOR, &c));
                continue;
            case '\'':
                i++;
                while (input[i] != '\'') {
                    i++;
                }
                token_list_add(list, token_create(TOKEN_STRING, &input[i - 1]));
                continue;
            case '"':
                i++;
                while (input[i] != '"') {
                    i++;
                }
                token_list_add(list, token_create(TOKEN_STRING, &input[i - 1]));
                continue;
            default:
                if (isalpha(c) || c == '_') {
                    i--;
                    while (isalnum(input[i]) || input[i] == '_') {
                        i++;
                    }
                    token_list_add(list, token_create(TOKEN_IDENTIFIER, &input[i - 1]));
                    continue;
                } else if (isdigit(c)) {
                    i--;
                    while (isdigit(input[i])) {
                        i++;
                    }
                    token_list_add(list, token_create(TOKEN_NUMBER, &input[i - 1]));
                    continue;
                } else {
                    fprintf(stderr, "Invalid character: %c\n", c);
                    exit(1);
                }
        }
    }
    token_list_add(list, token_create(TOKEN_EOF, NULL));
    return list;
}

int main() {
    char *input = "int main() { int a = 1; return a + 1; }";
    struct token_list *list = lex(input);
    for (int i = 0; i < list->size; i++) {
        printf("%d: %d, %s\n", i, list->tokens[i].type, list->tokens[i].value);
    }
    token_list_destroy(list);
    return 0;
}