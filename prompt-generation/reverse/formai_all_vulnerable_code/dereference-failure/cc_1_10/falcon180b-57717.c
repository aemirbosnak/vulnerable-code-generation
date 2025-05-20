//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} Token;

Token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *str, int len) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum tokens reached.\n");
        exit(1);
    }
    tokens[num_tokens].token = (char *) malloc(len + 1);
    strncpy(tokens[num_tokens].token, str, len);
    tokens[num_tokens].token_len = len;
    num_tokens++;
}

void print_tokens() {
    int i;
    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].token);
    }
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            int word_len = strlen(word);
            if (word_len > 0) {
                add_token(word, word_len);
            }
            word = strtok(NULL, ",.!?;:");
        }
    }
    print_tokens();
    return 0;
}