//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 64

typedef struct {
    char *name;
    int line_num;
} Token;

int num_tokens = 0;
Token tokens[MAX_TOKENS];

void add_token(char *name, int line_num) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].line_num = line_num;
    num_tokens++;
}

int main(int argc, char **argv) {
    FILE *fp;
    char filename[MAX_TOKEN_LEN];
    char line[MAX_TOKEN_LEN];
    int line_num = 1;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            add_token(token, line_num);
            token = strtok(NULL, " \t\n\r\f\v");
        }
        line_num++;
    }

    fclose(fp);

    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%d: %s\n", tokens[i].line_num, tokens[i].name);
    }

    return 0;
}