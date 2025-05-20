//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char *value;
    struct Token *next;
} Token;

Token *parse_metadata(char *filename) {
    FILE *fp;
    char line[256];
    Token *head = NULL;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }
    while (fgets(line, 256, fp) != NULL) {
        char *key, *value, *p;
        key = strchr(line, ':');
        if (key) {
            *key = '\0';
            value = key + 1;
            p = malloc(strlen(value) + 1);
            strcpy(p, value);
            Token *new_token = malloc(sizeof(Token));
            new_token->name = p;
            new_token->value = malloc(strlen(value) + 1);
            strcpy(new_token->value, value);
            new_token->next = head;
            head = new_token;
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
            printf("%s: %s\n", token->name, token->value);
        }
    }
    return 0;
}