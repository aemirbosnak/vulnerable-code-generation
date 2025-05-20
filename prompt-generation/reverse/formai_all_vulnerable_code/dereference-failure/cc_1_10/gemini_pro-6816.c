//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int type;
    char *value;
    struct Node *left;
    struct Node *right;
};

struct Token {
    int type;
    char *value;
};

enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OPERATOR,
    TOKEN_PUNCTUATOR,
    TOKEN_KEYWORD
};

enum NodeType {
    NODE_PROGRAM,
    NODE_STATEMENT,
    NODE_EXPRESSION,
    NODE_IDENTIFIER,
    NODE_NUMBER,
    NODE_STRING,
    NODE_OPERATOR,
    NODE_PUNCTUATOR,
    NODE_KEYWORD
};

struct Token *tokens;
int tokenIndex;

struct Node *parseProgram();
struct Node *parseStatement();
struct Node *parseExpression();
struct Node *parseIdentifier();
struct Node *parseNumber();
struct Node *parseString();
struct Node *parseOperator();
struct Node *parsePunctuator();
struct Node *parseKeyword();

struct Token *nextToken() {
    if (tokenIndex >= strlen(tokens)) {
        return NULL;
    }
    return &tokens[tokenIndex++];
}

struct Node *parseProgram() {
    struct Node *program = malloc(sizeof(struct Node));
    program->type = NODE_PROGRAM;
    program->left = parseStatement();
    program->right = NULL;
    return program;
}

struct Node *parseStatement() {
    struct Node *statement = malloc(sizeof(struct Node));
    statement->type = NODE_STATEMENT;
    statement->left = parseExpression();
    statement->right = NULL;
    return statement;
}

struct Node *parseExpression() {
    struct Node *expression = malloc(sizeof(struct Node));
    expression->type = NODE_EXPRESSION;
    expression->left = parseIdentifier();
    expression->right = NULL;
    return expression;
}

struct Node *parseIdentifier() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_IDENTIFIER) {
        return NULL;
    }
    struct Node *identifier = malloc(sizeof(struct Node));
    identifier->type = NODE_IDENTIFIER;
    identifier->value = token->value;
    identifier->left = NULL;
    identifier->right = NULL;
    return identifier;
}

struct Node *parseNumber() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_NUMBER) {
        return NULL;
    }
    struct Node *number = malloc(sizeof(struct Node));
    number->type = NODE_NUMBER;
    number->value = token->value;
    number->left = NULL;
    number->right = NULL;
    return number;
}

struct Node *parseString() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_STRING) {
        return NULL;
    }
    struct Node *string = malloc(sizeof(struct Node));
    string->type = NODE_STRING;
    string->value = token->value;
    string->left = NULL;
    string->right = NULL;
    return string;
}

struct Node *parseOperator() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_OPERATOR) {
        return NULL;
    }
    struct Node *operator = malloc(sizeof(struct Node));
    operator->type = NODE_OPERATOR;
    operator->value = token->value;
    operator->left = NULL;
    operator->right = NULL;
    return operator;
}

struct Node *parsePunctuator() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_PUNCTUATOR) {
        return NULL;
    }
    struct Node *punctuator = malloc(sizeof(struct Node));
    punctuator->type = NODE_PUNCTUATOR;
    punctuator->value = token->value;
    punctuator->left = NULL;
    punctuator->right = NULL;
    return punctuator;
}

struct Node *parseKeyword() {
    struct Token *token = nextToken();
    if (token->type != TOKEN_KEYWORD) {
        return NULL;
    }
    struct Node *keyword = malloc(sizeof(struct Node));
    keyword->type = NODE_KEYWORD;
    keyword->value = token->value;
    keyword->left = NULL;
    keyword->right = NULL;
    return keyword;
}

int main() {
    char *sourceCode = "x = 1 + 2;";
    tokens = malloc(strlen(sourceCode) * sizeof(struct Token));
    tokenIndex = 0;
    struct Node *program = parseProgram();
    printf("%s\n", program->left->left->value);
    return 0;
}