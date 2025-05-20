//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 256

typedef struct {
    char *name;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int numTokens;
} Line;

Line *createLine() {
    Line *line = malloc(sizeof(Line));
    line->tokens = malloc(MAX_TOKENS * sizeof(Token));
    line->numTokens = 0;
    return line;
}

void destroyLine(Line *line) {
    for (int i = 0; i < line->numTokens; i++) {
        free(line->tokens[i].name);
        free(line->tokens[i].value);
    }
    free(line->tokens);
    free(line);
}

void addToken(Line *line, char *name, char *value) {
    if (line->numTokens >= MAX_TOKENS) {
        printf("Error: Too many tokens in line.\n");
        exit(1);
    }
    Token *token = malloc(sizeof(Token));
    token->name = strdup(name);
    token->value = strdup(value);
    line->tokens[line->numTokens++] = *token;
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Line *lineData = createLine();
        char *token = strtok(line, ":");
        while (token!= NULL) {
            char *name = strtok(token, "=");
            char *value = strtok(NULL, ":");
            if (name!= NULL && value!= NULL) {
                addToken(lineData, name, value);
            }
            token = strtok(NULL, ":");
        }
        printf("Line parsed:\n");
        for (int i = 0; i < lineData->numTokens; i++) {
            printf("%s=%s\n", lineData->tokens[i].name, lineData->tokens[i].value);
        }
        destroyLine(lineData);
    }
    fclose(file);
    return 0;
}