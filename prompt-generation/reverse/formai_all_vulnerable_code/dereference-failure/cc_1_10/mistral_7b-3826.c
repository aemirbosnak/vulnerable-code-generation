//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 128

typedef struct {
    char token[MAX_TOKEN_LENGTH];
    int count;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens;

void parse_line(char *line) {
    char *token, *save_ptr;
    int i;

    num_tokens = 0;
    tokens[num_tokens].count = 1;

    token = strtok_r(line, " ", &save_ptr);
    while (token != NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: too many tokens\n");
            exit(1);
        }

        strcpy(tokens[num_tokens].token, token);
        num_tokens++;

        for (i = 0; i < num_tokens - 1; i++) {
            if (strcmp(tokens[i].token, tokens[i + 1].token) == 0) {
                tokens[i].count++;
                tokens[num_tokens - 1].count = 0;
                num_tokens--;
                break;
            }
        }

        token = strtok_r(NULL, " ", &save_ptr);
    }
}

void print_stats() {
    int i;

    printf("\nLog file analysis statistics:\n");
    printf("----------------------------------\n");

    for (i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: unable to open log file %s\n", argv[1]);
        exit(1);
    }

    printf("Log file analysis:\n");
    printf("--------------------\n");

    while (fgets(line, sizeof(line), log_file) != NULL) {
        parse_line(line);
    }

    fclose(log_file);

    print_stats();

    return 0;
}

// vim: set ts=4 sw=4 et: