//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

void parse_line(char *line) {
    char *token;
    int i;

    for (i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].name, "name") == 0) {
            printf("Name: %s\n", tokens[i].value);
        } else if (strcmp(tokens[i].name, "email") == 0) {
            printf("Email: %s\n", tokens[i].value);
        }
    }
}

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: too many tokens\n");
        exit(1);
    }

    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *name = NULL;
    char *value = NULL;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (line[0] == '#') {
            if (name!= NULL && value!= NULL) {
                add_token(name, value);
                name = NULL;
                value = NULL;
            }

            char *colon = strchr(line, ':');
            if (colon == NULL) {
                printf("Error: invalid line\n");
                exit(1);
            }

            name = strdup(line + 1);
            name[colon - line - 1] = '\0';
            value = strdup(colon + 1);
            value[strcspn(value, "\n")] = '\0';
        } else if (name == NULL) {
            printf("Error: missing name\n");
            exit(1);
        }
    }

    if (name!= NULL && value!= NULL) {
        add_token(name, value);
    }

    fclose(fp);

    parse_line(line);

    return 0;
}