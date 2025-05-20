//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    int value;
    struct Token *next;
} Token;

Token *parse_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_TOKENS];
    Token *head = NULL;
    Token *tail = NULL;

    while (fgets(line, MAX_TOKENS, fp) != NULL) {
        char *key = strchr(line, ':');
        char *value = strchr(line, ';');

        if (key && value) {
            Token *new_token = malloc(sizeof(Token));
            new_token->name = strdup(key);
            new_token->value = atoi(value);

            if (head == NULL) {
                head = new_token;
                tail = new_token;
            } else {
                tail->next = new_token;
                tail = new_token;
            }
        }
    }

    fclose(fp);
    return head;
}

int main() {
    char *filename = "metadata.txt";
    Token *tokens = parse_metadata(filename);

    if (tokens) {
        for (Token *token = tokens; token; token = token->next) {
            printf("%s: %d\n", token->name, token->value);
        }
    }

    return 0;
}