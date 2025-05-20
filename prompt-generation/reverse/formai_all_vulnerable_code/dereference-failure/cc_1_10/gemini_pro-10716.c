//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: creative
// The Grand C Syntax Symphony

#include <stdio.h>
#include <stdlib.h>

// Our Maestro
typedef struct SyntaxNode {
    char *type;
    struct SyntaxNode **children;
    int childCount;
} SyntaxNode;

// The Tokens, Our Instruments
#define TOKEN_TYPE(name) int name = -1
TOKEN_TYPE(SEMI);
TOKEN_TYPE(LPAREN);
TOKEN_TYPE(RPAREN);
TOKEN_TYPE(LBRACE);
TOKEN_TYPE(RBRACE);
TOKEN_TYPE(IF);
TOKEN_TYPE(ELSE);
TOKEN_TYPE(FOR);
TOKEN_TYPE(WHILE);
TOKEN_TYPE(INT);
TOKEN_TYPE(ID);
TOKEN_TYPE(NUM);

// Our Tokens in Harmony
char *tokenNames[] = {
    "SEMI", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
    "IF", "ELSE", "FOR", "WHILE", "INT", "ID", "NUM"
};

// Lexical Analysis, Uncovering the Notes
int getTokenType(char *token) {
    for (int i = 0; i < 12; i++)
        if (!strcmp(token, tokenNames[i]))
            return i;
    return -1;
}

// Parsing, Creating Our Composition
SyntaxNode *parse(char **tokens, int tokenCount) {
    int currentToken = 0;

    SyntaxNode *node = malloc(sizeof(SyntaxNode));
    node->type = strtok(tokens[currentToken++], ":");
    node->childCount = 0;
    node->children = NULL;

    if (!strcmp(node->type, "PROGRAM")) {
        node->children = malloc(sizeof(SyntaxNode *) * 2);
        node->children[0] = parse(tokens, tokenCount);
        if (!strcmp(tokens[currentToken], "EOF"))
            return node;
        node->children[1] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "STMT_LIST")) {
        node->children = malloc(sizeof(SyntaxNode *) * tokenCount + 1);
        int i = 0;
        while (currentToken < tokenCount && strcmp(tokens[currentToken], "EOF"))
            node->children[i++] = parse(tokens, tokenCount);
        node->childCount = i;
    } else if (!strcmp(node->type, "STMT")) {
        node->children = malloc(sizeof(SyntaxNode *));
        node->children[0] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "ASSIGN_STMT")) {
        node->children = malloc(sizeof(SyntaxNode *) * 3);
        node->children[0] = parse(tokens, tokenCount);
        node->children[1] = parse(tokens, tokenCount);
        node->children[2] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "EXPR")) {
        node->children = malloc(sizeof(SyntaxNode *) * 3);
        node->children[0] = parse(tokens, tokenCount);
        node->children[1] = parse(tokens, tokenCount);
        node->children[2] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "TERM")) {
        node->children = malloc(sizeof(SyntaxNode *) * 3);
        node->children[0] = parse(tokens, tokenCount);
        node->children[1] = parse(tokens, tokenCount);
        node->children[2] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "FACTOR")) {
        node->children = malloc(sizeof(SyntaxNode *));
        node->children[0] = parse(tokens, tokenCount);
    } else if (!strcmp(node->type, "ID")) {
        node->type = tokens[currentToken];
        currentToken++;
    } else if (!strcmp(node->type, "NUM")) {
        node->type = tokens[currentToken];
        currentToken++;
    } else {
        free(node);
        return NULL;
    }

    return node;
}

// Printing the Symphony
void printNode(SyntaxNode *node, int level) {
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s\n", node->type);
    for (int i = 0; i < node->childCount; i++)
        printNode(node->children[i], level + 1);
}

// Our Grand Finale
int main() {
    char *tokens[] = {
        "PROGRAM:PROG", "STMT_LIST:STMT1", "STMT:ASSIGN_STMT",
        "ID:x", "ASSIGN_OP:=", "EXPR:TERM", "TERM:FACTOR",
        "NUM:10", "EOF"
    };
    int tokenCount = sizeof(tokens) / sizeof(tokens[0]);

    SyntaxNode *root = parse(tokens, tokenCount);
    printNode(root, 0);
    free(root);

    return 0;
}