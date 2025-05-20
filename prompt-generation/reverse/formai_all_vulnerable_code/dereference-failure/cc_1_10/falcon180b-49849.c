//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

int main() {
    char line[1000];
    char *token;
    char *saveptr;
    int i = 0;

    while (fgets(line, sizeof(line), stdin)!= NULL) {
        token = strtok_r(line, "\r\n", &saveptr);
        while (token!= NULL) {
            if (i >= MAX_TOKENS) {
                printf("Error: Too many lines\n");
                exit(1);
            }
            add_token(token, "");
            token = strtok_r(NULL, "\r\n", &saveptr);
            i++;
        }
    }

    for (i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    return 0;
}