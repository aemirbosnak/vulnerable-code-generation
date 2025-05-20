//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NUM_TOKENS 10
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *data;
    int length;
} Token;

void tokenize(char *line, Token *tokens) {
    int i = 0;
    int j = 0;
    char *token = NULL;
    char *p = line;
    while (i < NUM_TOKENS) {
        token = strtok(p, " ");
        if (token == NULL) {
            break;
        }
        tokens[i].data = malloc(strlen(token) + 1);
        strcpy(tokens[i].data, token);
        tokens[i].length = strlen(token);
        p = NULL;
        i++;
    }
}

void process_line(Token *tokens) {
    int i = 0;
    char *ip = tokens[i].data;
    char *user_agent = tokens[i + 2].data;
    char *request_url = tokens[i + 3].data;
    char *status_code = tokens[i + 5].data;
    printf("IP: %s\n", ip);
    printf("User Agent: %s\n", user_agent);
    printf("Request URL: %s\n", request_url);
    printf("Status Code: %s\n\n", status_code);
}

void main() {
    FILE *fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        Token tokens[NUM_TOKENS];
        tokenize(line, tokens);
        process_line(tokens);
    }
    fclose(fp);
}