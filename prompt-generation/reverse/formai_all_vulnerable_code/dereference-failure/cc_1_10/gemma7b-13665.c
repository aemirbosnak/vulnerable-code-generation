//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int type;
    struct Token *next;
} Token;

typedef struct Parser {
    Token **tokens;
    int tokenCount;
    FILE *fp;
} Parser;

Parser *parser_init(FILE *fp) {
    Parser *p = malloc(sizeof(Parser));
    p->tokens = NULL;
    p->tokenCount = 0;
    p->fp = fp;
    return p;
}

void parser_add_token(Parser *p, char *lexeme, int type) {
    Token *newToken = malloc(sizeof(Token));
    newToken->lexeme = strdup(lexeme);
    newToken->type = type;
    newToken->next = p->tokens;
    p->tokens = newToken;
    p->tokenCount++;
}

void parser_parse(Parser *p) {
    char buf[MAX_TOKENS];
    int i = 0;
    while (fgets(buf, MAX_TOKENS, p->fp) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        parser_add_token(p, buf, i++ % 2);
    }
}

int main() {
    FILE *fp = fopen("example.xml", "r");
    Parser *p = parser_init(fp);
    parser_parse(p);
    fclose(fp);

    for (Token *token = p->tokens; token; token = token->next) {
        printf("Lexeme: %s, Type: %d\n", token->lexeme, token->type);
    }

    return 0;
}