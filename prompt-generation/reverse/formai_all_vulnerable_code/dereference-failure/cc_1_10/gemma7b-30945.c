//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

    char buffer[1024];
    Token *head = NULL;
    Token *tail = NULL;

    while (fgets(buffer, 1024, fp) != NULL) {
        char *key = strchr(buffer, ':');
        if (key) {
            char *value = strchr(key, ';');
            if (value) {
                value++;

                Token *new_token = malloc(sizeof(Token));
                new_token->name = strdup(key);
                new_token->value = strdup(value);
                new_token->next = NULL;

                if (head == NULL) {
                    head = new_token;
                    tail = new_token;
                } else {
                    tail->next = new_token;
                    tail = new_token;
                }
            }
        }
    }

    fclose(fp);

    return head;
}

int main() {
    char *filename = "my_file.txt";
    Token *tokens = extract_metadata(filename);

    if (tokens) {
        for (Token *token = tokens; token; token = token->next) {
            printf("%s: %s\n", token->name, token->value);
        }
    }

    return 0;
}