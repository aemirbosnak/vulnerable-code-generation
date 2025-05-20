//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *token;
    int count;
} Token;

void tokenize(char *line, Token tokens[], int num_tokens) {
    char *token = strtok(line, " ");
    int i = 0;

    while (token!= NULL) {
        if (i >= num_tokens) {
            break;
        }

        tokens[i].token = malloc(strlen(token) + 1);
        strcpy(tokens[i].token, token);
        tokens[i].count = 1;

        i++;
        token = strtok(NULL, " ");
    }
}

void print_tokens(Token tokens[], int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        tokenize(line, tokens, MAX_TOKENS);
        num_tokens = 0;

        for (int i = 0; i < MAX_TOKENS; i++) {
            if (tokens[i].token!= NULL) {
                num_tokens++;
            }
        }

        if (num_tokens > 0) {
            print_tokens(tokens, num_tokens);
        }
    }

    fclose(log_file);

    return 0;
}