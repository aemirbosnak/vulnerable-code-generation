//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 256

typedef struct Token {
    char *name;
    int value;
    struct Token *next;
} Token;

int main() {
    Token *tokens = NULL;
    char input[1024];
    char *ptr = input;
    char token[MAX_TOKENS][256];
    int tokenIndex = 0;

    printf("Enter a tale, brave knight:");
    scanf("%[^\n]%*c", input);

    // Parse the tale into tokens
    while (ptr < input + strlen(input)) {
        char *start = ptr;
        int length = 0;

        // Identify the token
        while (isalnum(*ptr) || *ptr == '_') {
            ptr++;
            length++;
        }

        // Create a new token
        tokens = malloc(sizeof(Token));
        tokens->name = malloc(length + 1);
        memcpy(tokens->name, start, length);
        tokens->name[length] = '\0';
        tokens->value = tokenIndex++;

        // Link the token to the list
        if (tokens->next) {
            tokens->next->next = tokens;
        } else {
            tokens->next = tokens;
        }
    }

    // Print the tokens
    for (tokens = tokens; tokens; tokens = tokens->next) {
        printf("Token: %s, Value: %d\n", tokens->name, tokens->value);
    }

    return 0;
}