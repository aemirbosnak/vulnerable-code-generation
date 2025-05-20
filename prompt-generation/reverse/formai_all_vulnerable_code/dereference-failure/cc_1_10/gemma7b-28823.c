//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOKENS 10

typedef struct Token {
    char *lexeme;
    int type;
    struct Token *next;
} Token;

void parse_c_syntax() {
    // Create a linked list of tokens
    Token *head = NULL;

    // Get the source code from the user
    char *source_code = malloc(100);
    printf("Enter C source code: ");
    fgets(source_code, 100, stdin);

    // Tokenize the source code
    char *token_stream = strtok(source_code, " ");
    int token_index = 0;

    // Create tokens for each word in the source code
    while (token_stream) {
        Token *new_token = malloc(sizeof(Token));
        new_token->lexeme = strdup(token_stream);
        new_token->type = token_index;
        new_token->next = head;
        head = new_token;
        token_index++;
        token_stream = strtok(NULL, " ");
    }

    // Print the tokens
    printf("Tokens:\n");
    for (Token *token = head; token; token = token->next) {
        printf("%s (type: %d)\n", token->lexeme, token->type);
    }

    // Free the memory allocated for the source code and tokens
    free(source_code);
    free(head);
}

int main() {
    parse_c_syntax();
    return 0;
}