//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} Token;

int num_tokens = 0;
Token tokens[MAX_TOKENS];

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for line!\n");
        exit(1);
    }

    read = getline(&line, &len, fp);
    if (read <= 0) {
        fprintf(stderr, "Error: Failed to read line!\n");
        exit(1);
    }

    line[read - 1] = '\0'; // Remove newline character

    return line;
}

void parse_line(char *line) {
    char *token = strtok(line, ":");
    while (token!= NULL) {
        num_tokens++;
        if (num_tokens >= MAX_TOKENS) {
            fprintf(stderr, "Error: Too many tokens!\n");
            exit(1);
        }

        tokens[num_tokens - 1].name = strdup(token);
        token = strtok(NULL, ":");
        if (token!= NULL) {
            tokens[num_tokens - 1].value = strdup(token);
        } else {
            tokens[num_tokens - 1].value = NULL;
        }
    }
}

void print_tokens() {
    int i;

    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].name!= NULL && tokens[i].value!= NULL) {
            printf("%s: %s\n", tokens[i].name, tokens[i].value);
        } else if (tokens[i].name!= NULL) {
            printf("%s\n", tokens[i].name);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line = NULL;

    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a resume file!\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open resume file!\n");
        exit(1);
    }

    while ((line = read_line(fp))!= NULL) {
        parse_line(line);
    }

    print_tokens();

    return 0;
}