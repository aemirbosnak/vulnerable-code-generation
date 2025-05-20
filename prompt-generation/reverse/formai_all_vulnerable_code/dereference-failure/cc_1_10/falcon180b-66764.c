//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    int count;
    token_t tokens[MAX_TOKENS];
} parser_t;

parser_t *create_parser() {
    parser_t *parser = (parser_t *)malloc(sizeof(parser_t));
    parser->count = 0;
    return parser;
}

void destroy_parser(parser_t *parser) {
    for (int i = 0; i < parser->count; i++) {
        free(parser->tokens[i].name);
        free(parser->tokens[i].value);
    }
    free(parser);
}

void add_token(parser_t *parser, char *name, char *value) {
    if (parser->count >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        return;
    }
    token_t token = {name, value};
    parser->tokens[parser->count++] = token;
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (!fp) {
        printf("Error: File not found\n");
        return 1;
    }
    char line[MAX_TOKEN_LENGTH];
    parser_t *parser = create_parser();
    while (fgets(line, sizeof(line), fp)) {
        char *token = strtok(line, " \n\t\r");
        while (token!= NULL) {
            if (strcasecmp(token, "Name") == 0) {
                token = strtok(NULL, " \n\t\r");
                add_token(parser, "name", token);
            } else if (strcasecmp(token, "Email") == 0) {
                token = strtok(NULL, " \n\t\r");
                add_token(parser, "email", token);
            } else if (strcasecmp(token, "Phone") == 0) {
                token = strtok(NULL, " \n\t\r");
                add_token(parser, "phone", token);
            }
            token = strtok(NULL, " \n\t\r");
        }
    }
    fclose(fp);
    for (int i = 0; i < parser->count; i++) {
        printf("%s: %s\n", parser->tokens[i].name, parser->tokens[i].value);
    }
    destroy_parser(parser);
    return 0;
}