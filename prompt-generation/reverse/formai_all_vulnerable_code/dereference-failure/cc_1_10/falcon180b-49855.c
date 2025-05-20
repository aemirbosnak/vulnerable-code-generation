//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *value;
    int count;
} Token;

Token tokens[MAX_TOKEN_LENGTH];
int numTokens;

void tokenize(char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        for (int i = 0; i < numTokens; i++) {
            if (strcmp(tokens[i].value, token) == 0) {
                tokens[i].count++;
                break;
            }
        }
        if (numTokens >= MAX_TOKEN_LENGTH) {
            printf("Error: Too many tokens!\n");
            exit(1);
        }
        strcpy(tokens[numTokens].value, token);
        tokens[numTokens].count = 1;
        numTokens++;
        token = strtok(NULL, " ");
    }
}

void printTopTokens(int num) {
    printf("Top %d tokens:\n", num);
    for (int i = 0; i < numTokens; i++) {
        if (tokens[i].count >= num) {
            printf("%s: %d\n", tokens[i].value, tokens[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open log file!\n");
        return 1;
    }

    char line[MAX_LOG_LINES];
    numTokens = 0;

    while (fgets(line, MAX_LOG_LINES, fp)!= NULL) {
        tokenize(line);
    }

    fclose(fp);

    printf("Total lines: %d\n", numTokens);
    printTopTokens(10);

    return 0;
}