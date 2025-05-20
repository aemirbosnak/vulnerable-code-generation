//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int lineNumber;
    int columnNumber;
    struct Token *next;
} Token;

Token *parse_metadata(char *source) {
    Token *head = NULL;
    char *line = NULL;
    char *p, *q;
    int linenumber = 0;

    p = source;
    while (p) {
        line = strchr(p, '\n');
        if (line) {
            ++linenumber;
            p = line + 1;
        } else {
            p = NULL;
        }

        q = strchr(p, ':');
        if (q) {
            Token *newToken = malloc(sizeof(Token));
            newToken->lexeme = strdup(strtok(q + 1, ":"));
            newToken->lineNumber = linenumber;
            newToken->columnNumber = strcspn(p, ":") + 1;
            newToken->next = head;
            head = newToken;
        }
    }

    return head;
}

int main() {
    char *source = "source code with metadata\n"
                        "key: value\n"
                        "another key: another value\n"
                        "foo: bar\n";

    Token *tokens = parse_metadata(source);

    for (Token *token = tokens; token; token = token->next) {
        printf("L%d C%d: %s\n", token->lineNumber, token->columnNumber, token->lexeme);
    }

    return 0;
}