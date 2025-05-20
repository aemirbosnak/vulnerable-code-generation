//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    int line_number;
    struct Token *next;
} Token;

Token *parse_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    Token *head = NULL;
    char line[MAX_TOKENS];
    int line_number = 1;

    while (fgets(line, MAX_TOKENS, fp) != NULL) {
        char *token_name = strtok(line, ":");
        if (token_name) {
            Token *new_token = malloc(sizeof(Token));
            new_token->name = strdup(token_name);
            new_token->line_number = line_number;
            new_token->next = head;
            head = new_token;
        }
        line_number++;
    }

    fclose(fp);
    return head;
}

int main() {
    char *filename = "my_metadata.txt";
    Token *tokens = parse_metadata(filename);

    if (tokens) {
        for (Token *token = tokens; token; token = token->next) {
            printf("%s: %d\n", token->name, token->line_number);
        }
    } else {
        printf("Error parsing metadata.\n");
    }

    return 0;
}