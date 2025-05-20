//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_SIZE 50

char *token_buffer[MAX_TOKENS];
int token_count = 0;

void parse_line(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (token_count >= MAX_TOKENS) {
            printf("Error: Too many tokens on line.\n");
            exit(1);
        }
        strncpy(token_buffer[token_count], token, MAX_TOKEN_SIZE);
        token_count++;
        token = strtok(NULL, " ");
    }
}

void print_tokens() {
    for (int i = 0; i < token_count; i++) {
        printf("%s ", token_buffer[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        parse_line(line);
    }

    fclose(fp);
    print_tokens();

    return 0;
}