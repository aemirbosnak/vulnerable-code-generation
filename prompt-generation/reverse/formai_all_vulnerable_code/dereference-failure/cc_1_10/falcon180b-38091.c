//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    char *name;
    char *value;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} Line;

void init_line(Line *line) {
    line->tokens = (Token *) malloc(MAX_TOKENS * sizeof(Token));
    line->num_tokens = 0;
}

void destroy_line(Line *line) {
    for (int i = 0; i < line->num_tokens; i++) {
        free(line->tokens[i].name);
        free(line->tokens[i].value);
    }
    free(line->tokens);
}

void add_token(Line *line, char *name, char *value) {
    if (line->num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens in line\n");
        exit(1);
    }
    Token *token = &line->tokens[line->num_tokens++];
    token->name = strdup(name);
    token->value = strdup(value);
}

void print_line(Line *line) {
    for (int i = 0; i < line->num_tokens; i++) {
        printf("%s=%s\n", line->tokens[i].name, line->tokens[i].value);
    }
}

char *get_token_value(Line *line, char *name) {
    for (int i = 0; i < line->num_tokens; i++) {
        if (strcmp(line->tokens[i].name, name) == 0) {
            return line->tokens[i].value;
        }
    }
    return NULL;
}

char *read_line(FILE *fp) {
    char *line = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        printf("Error: unexpected end of file\n");
        exit(1);
    }
    return line;
}

void parse_line(Line *line, char *delimiter, char *name) {
    char *value = strtok(line->tokens[0].value, delimiter);
    while (value!= NULL) {
        add_token(line, name, value);
        value = strtok(NULL, delimiter);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    Line line;
    init_line(&line);
    char *line_str;
    while ((line_str = read_line(fp))!= NULL) {
        char *delimiter = ",";
        char *name = "name";
        parse_line(&line, delimiter, name);
        add_token(&line, "last_name", "Doe");
        add_token(&line, "email", "johndoe@example.com");
        add_token(&line, "phone", "555-1234");
        add_token(&line, "address", "123 Main St.");
        print_line(&line);
        destroy_line(&line);
        init_line(&line);
    }
    fclose(fp);
    return 0;
}