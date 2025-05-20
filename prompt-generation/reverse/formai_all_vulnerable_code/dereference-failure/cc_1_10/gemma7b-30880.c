//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10

typedef struct Token {
    char *name;
    int lineNumber;
    struct Token *next;
} Token;

Token *parseResume(char *resumeText) {
    char **tokens = NULL;
    char *token = strtok(resumeText, " ");
    Token *head = NULL;
    int i = 0;

    while (token) {
        tokens = realloc(tokens, (i + 1) * MAX_TOKENS);
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < i; i++) {
        head = malloc(sizeof(Token));
        head->name = strdup(tokens[i]);
        head->lineNumber = i + 1;
        head->next = NULL;

        if (head->next == NULL) {
            head->next = head;
        } else {
            head->next = head;
        }
    }

    free(tokens);
    return head;
}

int main() {
    char *resumeText = "John Doe\n123 Main St.\nNew York, NY 10001\n(123) 456-7890\njohn.doe@example.com";
    Token *head = parseResume(resumeText);

    while (head) {
        printf("%s (line %d)\n", head->name, head->lineNumber);
        head = head->next;
    }

    return 0;
}