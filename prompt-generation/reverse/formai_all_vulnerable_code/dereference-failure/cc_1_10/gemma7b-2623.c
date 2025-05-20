//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char* token;
    struct Token* next;
} Token;

Token* extract_metadata(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        return NULL;
    }

    char buffer[MAX_TOKENS];
    int i = 0;
    Token* head = NULL;
    Token* tail = NULL;

    while (fgets(buffer, MAX_TOKENS, file) != NULL) {
        char* token = strtok(buffer, ":");
        if (token) {
            token = strdup(token);
            Token* new_token = malloc(sizeof(Token));
            new_token->token = token;
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

    fclose(file);
    return head;
}

int main() {
    char* file_path = "my_file.txt";
    Token* tokens = extract_metadata(file_path);

    if (tokens) {
        for (Token* token = tokens; token; token = token->next) {
            printf("%s:\n", token->token);
        }
    } else {
        printf("Error extracting metadata.\n");
    }

    return 0;
}