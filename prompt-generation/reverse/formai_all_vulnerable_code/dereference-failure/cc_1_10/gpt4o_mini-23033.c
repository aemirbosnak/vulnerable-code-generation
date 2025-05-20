//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100
#define MAX_NUM_TOKENS 100

typedef enum {
    TOKEN_INT,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_UNKNOWN,
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_SIZE];
} Token;

typedef struct {
    Token tokens[MAX_NUM_TOKENS];
    int count;
} TokenList;

const char *keywords[] = {
    "if", "else", "while", "for", "return", "int", "float", "void", "include", "define"
};

int is_keyword(const char *word) {
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == ';' ||
           ch == '(' || ch == ')' || ch == '{' || ch == '}';
}

TokenType get_token_type(const char *token) {
    if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "void") == 0) {
        return TOKEN_KEYWORD;
    } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        return strchr(token, '.') ? TOKEN_FLOAT : TOKEN_INT;
    } else if (token[0] == '"' && token[strlen(token) - 1] == '"') {
        return TOKEN_STRING;
    } else if (is_keyword(token)) {
        return TOKEN_KEYWORD;
    } else if (is_operator(token[0]) && token[1] == '\0') {
        return TOKEN_OPERATOR;
    } else {
        return TOKEN_IDENTIFIER;
    }
}

void tokenize(const char *code, TokenList *token_list) {
    const char *token = strtok(code, " \n\t");
    while (token != NULL) {
        token_list->tokens[token_list->count].type = get_token_type(token);
        strncpy(token_list->tokens[token_list->count].value, token, MAX_TOKEN_SIZE);
        token_list->count++;

        if (token_list->count >= MAX_NUM_TOKENS) {
            break; // Prevent overflow
        }

        token = strtok(NULL, " \n\t");
    }
}

void print_tokens(const TokenList *token_list) {
    for (int i = 0; i < token_list->count; i++) {
        printf("Token[%d]: Value = '%s', Type = %d\n", i, token_list->tokens[i].value, token_list->tokens[i].type);
    }
}

void parse_code(const char *code) {
    TokenList token_list;
    token_list.count = 0;

    tokenize(code, &token_list);
    print_tokens(&token_list);
}

int main() {
    const char *code = 
        "#include <stdio.h>\n"
        "int main() {\n"
        "    int x = 10;\n"
        "    float y = 20.5;\n"
        "    if (x > y) {\n"
        "        printf(\"x is greater than y\\n\");\n"
        "    } else {\n"
        "        printf(\"y is greater than or equal to x\\n\");\n"
        "    }\n"
        "    return 0;\n"
        "}\n";

    printf("Parsing the following C code:\n%s\n", code);
    parse_code(code);

    return 0;
}