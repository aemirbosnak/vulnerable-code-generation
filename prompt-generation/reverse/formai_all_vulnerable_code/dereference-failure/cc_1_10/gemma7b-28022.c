//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char *value;
    struct Token *next;
} Token;

Token *extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    char buffer[MAX_TOKENS];
    Token *head = NULL;
    Token *current = NULL;

    // Read the file line by line
    while (fgets(buffer, MAX_TOKENS, fp) != NULL) {
        // Extract the token name and value
        char *name = strchr(buffer, ':') + 1;
        char *value = strchr(name, ';') - name;

        // Create a new token
        Token *token = malloc(sizeof(Token));
        token->name = strdup(name);
        token->value = strdup(value);
        token->next = NULL;

        // Insert the token into the list
        if (head == NULL) {
            head = token;
            current = token;
        } else {
            current->next = token;
            current = token;
        }
    }

    fclose(fp);
    return head;
}

int main() {
    char *filename = "my_file.txt";
    Token *head = extract_metadata(filename);

    // Print the tokens
    for (Token *token = head; token; token = token->next) {
        printf("%s: %s\n", token->name, token->value);
    }

    return 0;
}