//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *key;
    char *value;
} token_t;

int main(int argc, char **argv) {
    char *input = "key1=value1&key2=value2&key3=value3";
    int num_tokens = 0;
    token_t tokens[MAX_TOKENS];

    char *key = NULL;
    char *value = NULL;
    char *delimiter = "=";
    char *token = strtok(input, delimiter);

    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            return 1;
        }

        value = strtok(NULL, delimiter);
        if (value == NULL) {
            printf("Error: Invalid token.\n");
            return 1;
        }

        key = strdup(token);
        value = strdup(value);

        tokens[num_tokens].key = key;
        tokens[num_tokens].value = value;
        num_tokens++;

        token = strtok(NULL, delimiter);
    }

    printf("Number of tokens: %d\n", num_tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("Token %d:\n", i);
        printf("Key: %s\n", tokens[i].key);
        printf("Value: %s\n", tokens[i].value);
        printf("\n");
    }

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].key);
        free(tokens[i].value);
    }

    return 0;
}