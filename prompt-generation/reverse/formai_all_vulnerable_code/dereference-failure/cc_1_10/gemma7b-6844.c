//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct SyntaxNode {
    char *lexeme;
    struct SyntaxNode *next;
} SyntaxNode;

SyntaxNode *parse_c_syntax(char *source) {
    SyntaxNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *p = buffer;
    int i = 0;

    while (*source) {
        switch (*source) {
            case '(':
            case ')':
            case '{':
            case '}':
            case ';':
            case ',':
            case '.':
            case '"':
            case '\'':
            case ' ':
                *p++ = *source;
                break;
            default:
                p = buffer;
                *p++ = *source;
                break;
        }

        source++;
    }

    free(buffer);

    return head;
}

int main() {
    char *source = "int main() { printf(\"Hello, world!\"); }";
    SyntaxNode *head = parse_c_syntax(source);

    printf("Syntax tree:\n");
    for (SyntaxNode *node = head; node; node = node->next) {
        printf("%s ", node->lexeme);
    }

    return 0;
}