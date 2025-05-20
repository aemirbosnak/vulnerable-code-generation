//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens!\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("Name: %s\nValue: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata.txt>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    char line[MAX_TOKEN_LEN];
    char *token = NULL;
    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        char *name = strtok_r(line, ":", &token);
        if (name == NULL) {
            continue;
        }
        char *value = strtok_r(NULL, ":", &token);
        if (value == NULL) {
            continue;
        }
        add_token(name, value);
    }

    fclose(fp);
    print_tokens();

    return 0;
}