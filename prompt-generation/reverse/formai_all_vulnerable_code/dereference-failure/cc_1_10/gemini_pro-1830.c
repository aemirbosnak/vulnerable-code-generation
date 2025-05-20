//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_KEYWORD,
    TOKEN_COMMENT,
    TOKEN_WHITESPACE,
    TOKEN_ERROR
} token_type;

typedef struct {
    token_type type;
    char *value;
} token;

typedef struct {
    char *line;
    int line_number;
    int position;
    token tokens[MAX_TOKENS];
    int num_tokens;
} lexer;

lexer *lexer_create(char *line) {
    lexer *l = malloc(sizeof(lexer));
    l->line = line;
    l->line_number = 1;
    l->position = 0;
    l->num_tokens = 0;
    return l;
}

void lexer_destroy(lexer *l) {
    free(l->line);
    free(l);
}

token lexer_get_next_token(lexer *l) {
    token t;
    t.type = TOKEN_EOF;
    t.value = NULL;
    
    while (l->position < strlen(l->line)) {
        char c = l->line[l->position];
        
        // Skip whitespace
        if (isspace(c)) {
            l->position++;
            continue;
        }
        
        // Handle comments
        if (c == '/' && l->line[l->position + 1] == '/') {
            while (l->line[l->position] != '\n') {
                l->position++;
            }
            l->position++;
            continue;
        }
        
        // Handle identifiers
        if (isalpha(c) || c == '_') {
            int start_position = l->position;
            while (isalnum(l->line[l->position]) || l->line[l->position] == '_') {
                l->position++;
            }
            int length = l->position - start_position;
            t.type = TOKEN_IDENTIFIER;
            t.value = malloc(length + 1);
            strncpy(t.value, l->line + start_position, length);
            t.value[length] = '\0';
            return t;
        }
        
        // Handle numbers
        if (isdigit(c)) {
            int start_position = l->position;
            while (isdigit(l->line[l->position])) {
                l->position++;
            }
            int length = l->position - start_position;
            t.type = TOKEN_NUMBER;
            t.value = malloc(length + 1);
            strncpy(t.value, l->line + start_position, length);
            t.value[length] = '\0';
            return t;
        }
        
        // Handle strings
        if (c == '"' || c == '\'') {
            char delimiter = c;
            int start_position = l->position + 1;
            while (l->line[l->position] != delimiter) {
                l->position++;
            }
            int length = l->position - start_position;
            t.type = TOKEN_STRING;
            t.value = malloc(length + 1);
            strncpy(t.value, l->line + start_position, length);
            t.value[length] = '\0';
            l->position++;
            return t;
        }
        
        // Handle operators
        if (strchr("+-*/%^&|<>=", c)) {
            t.type = TOKEN_OPERATOR;
            t.value = malloc(2);
            t.value[0] = c;
            t.value[1] = '\0';
            l->position++;
            return t;
        }
        
        // Handle punctuators
        if (strchr("(){}[],;:", c)) {
            t.type = TOKEN_PUNCTUATOR;
            t.value = malloc(2);
            t.value[0] = c;
            t.value[1] = '\0';
            l->position++;
            return t;
        }
        
        // Handle keywords
        if (strchr("ifelsewhileforreturnbreakcontinue", c)) {
            int start_position = l->position;
            while (isalnum(l->line[l->position]) || l->line[l->position] == '_') {
                l->position++;
            }
            int length = l->position - start_position;
            t.type = TOKEN_KEYWORD;
            t.value = malloc(length + 1);
            strncpy(t.value, l->line + start_position, length);
            t.value[length] = '\0';
            return t;
        }
        
        // Handle errors
        t.type = TOKEN_ERROR;
        t.value = malloc(2);
        t.value[0] = c;
        t.value[1] = '\0';
        l->position++;
        return t;
    }
    
    return t;
}

void lexer_print_tokens(lexer *l) {
    for (int i = 0; i < l->num_tokens; i++) {
        token t = l->tokens[i];
        printf("Token type: %d, Value: %s\n", t.type, t.value);
    }
}

int main() {
    char *line = "int main() { int a = 1; if (a == 1) { return 0; } else { break; } }";
    lexer *l = lexer_create(line);
    while (1) {
        token t = lexer_get_next_token(l);
        if (t.type == TOKEN_EOF) {
            break;
        }
        lexer_print_tokens(l);
    }
    lexer_destroy(l);
    return 0;
}