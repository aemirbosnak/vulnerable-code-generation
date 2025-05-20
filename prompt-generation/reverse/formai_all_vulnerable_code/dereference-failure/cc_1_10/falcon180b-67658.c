//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    int id;
    char *name;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }
    int id = num_tokens++;
    tokens[id].id = id;
    tokens[id].name = strdup(name);
}

int get_token_id(char *name) {
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].name, name) == 0) {
            return i;
        }
    }
    add_token(name);
    return num_tokens - 1;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %s\n", tokens[i].id, tokens[i].name);
    }
}

int main() {
    char line[MAX_TOKEN_LEN];
    char *token;
    int curr_token_id = -1;

    printf("Enter tokens:\n");
    while (fgets(line, MAX_TOKEN_LEN, stdin)) {
        token = strtok(line, " ");
        while (token!= NULL) {
            curr_token_id = get_token_id(token);
            printf("Token %d: %s\n", curr_token_id, token);
            token = strtok(NULL, " ");
        }
    }

    return 0;
}