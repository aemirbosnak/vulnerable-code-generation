//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens.\n");
        exit(1);
    }
    tokens[num_tokens].token = malloc(len+1);
    memcpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].token_len = len;
    num_tokens++;
}

void print_tokens() {
    for (int i=0; i<num_tokens; i++) {
        printf("%s (%d)\n", tokens[i].token, tokens[i].token_len);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resumé.txt>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[--len] = '\0';
        }
        add_token(line, len);
    }

    fclose(fp);

    print_tokens();

    return 0;
}