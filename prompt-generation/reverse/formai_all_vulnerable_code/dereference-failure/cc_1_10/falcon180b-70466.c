//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *data;
    struct node *next;
} Node;

typedef struct token {
    char *data;
    int type;
    struct token *next;
} Token;

typedef enum {
    NUMBER,
    STRING,
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    PUNCTUATION
} Type;

char *get_token(FILE *file);
void add_token(Token **tokens, Type type, char *data);
void print_tokens(Token *tokens);
void free_tokens(Token *tokens);

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Token *tokens = NULL;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        char *token = get_token(file);
        add_token(&tokens, IDENTIFIER, token);
        free(token);
    }

    print_tokens(tokens);
    free_tokens(tokens);

    return 0;
}

char *get_token(FILE *file) {
    char ch;
    char *token = malloc(1);
    int len = 0;

    do {
        ch = fgetc(file);
        if (ch == '\n') {
            ungetc(ch, file);
            break;
        }
        token = realloc(token, len + 2);
        token[len] = ch;
        len++;
    } while (isspace(ch));

    token[len] = '\0';
    return token;
}

void add_token(Token **tokens, Type type, char *data) {
    Token *token = malloc(sizeof(Token));
    token->data = data;
    token->type = type;
    token->next = NULL;

    if (*tokens == NULL) {
        *tokens = token;
    } else {
        Token *last = *tokens;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = token;
    }
}

void print_tokens(Token *tokens) {
    Token *current = tokens;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_tokens(Token *tokens) {
    Token *current = tokens;
    while (current!= NULL) {
        free(current->data);
        current = current->next;
    }
    free(tokens);
}