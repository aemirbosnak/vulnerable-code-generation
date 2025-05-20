//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 10000
#define MAX_NUM_TOKENS 1000
#define MAX_TOKEN_LENGTH 1000

char *log_filename;
char *delimiter;

struct token {
    char *value;
    int count;
};

struct token *tokens;
int num_tokens;

void initialize_tokens() {
    tokens = malloc(MAX_NUM_TOKENS * sizeof(struct token));
    memset(tokens, 0, MAX_NUM_TOKENS * sizeof(struct token));
    num_tokens = 0;
}

void add_token(char *value) {
    if (num_tokens >= MAX_NUM_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].value = strdup(value);
    tokens[num_tokens].count = 1;
    num_tokens++;
}

void print_tokens() {
    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].value, tokens[i].count);
    }
}

int main() {
    log_filename = "example.log";
    delimiter = " ";

    initialize_tokens();

    FILE *file = fopen(log_filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", log_filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        char *token = strtok(line, delimiter);
        while (token!= NULL) {
            add_token(token);
            token = strtok(NULL, delimiter);
        }
    }

    fclose(file);

    print_tokens();

    return 0;
}