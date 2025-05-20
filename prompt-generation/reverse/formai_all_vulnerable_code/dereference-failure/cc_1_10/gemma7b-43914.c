//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    char *value;
    struct Token *next;
} Token;

Token *extract_metadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_TOKENS];
    Token *head = NULL;

    while (fgets(line, MAX_TOKENS, fp) != NULL) {
        char *key = strchr(line, ':');
        if (key) {
            char *value = strchr(key, ',');
            if (value) {
                value++;
                Token *new_token = malloc(sizeof(Token));
                new_token->name = strdup(key);
                new_token->value = strdup(value);
                new_token->next = head;
                head = new_token;
            }
        }
    }

    fclose(fp);
    return head;
}

int main() {
    char *filename = "example.txt";
    Token *tokens = extract_metadata(filename);

    if (tokens) {
        for (Token *token = tokens; token; token = token->next) {
            printf("%s: %s\n", token->name, token->value);
        }
    } else {
        printf("Error extracting metadata.\n");
    }

    return 0;
}