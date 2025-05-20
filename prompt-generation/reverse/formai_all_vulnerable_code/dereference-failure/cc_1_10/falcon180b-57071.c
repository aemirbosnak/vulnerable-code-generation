//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

void tokenize(char *input, token_t tokens[]) {
    int i = 0;
    char *token = strtok(input, " ");

    while (token!= NULL) {
        tokens[i].name = strdup(token);
        tokens[i].value = NULL;
        i++;

        if (i >= MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }

        token = strtok(NULL, " ");
    }
}

void parse_resume(token_t tokens[]) {
    int i = 0;

    while (tokens[i].name!= NULL) {
        if (strcmp(tokens[i].name, "Name") == 0) {
            printf("Name: %s\n", tokens[i].value);
        } else if (strcmp(tokens[i].name, "Email") == 0) {
            printf("Email: %s\n", tokens[i].value);
        } else if (strcmp(tokens[i].name, "Phone") == 0) {
            printf("Phone: %s\n", tokens[i].value);
        } else if (strcmp(tokens[i].name, "Education") == 0) {
            printf("Education:\n");
        } else if (strcmp(tokens[i].name, "Experience") == 0) {
            printf("Experience:\n");
        } else if (strcmp(tokens[i].name, "Skills") == 0) {
            printf("Skills:\n");
        }

        i++;
    }
}

int main() {
    char input[1024];
    token_t tokens[MAX_TOKENS];

    printf("Enter resume text:\n");
    fgets(input, 1024, stdin);

    tokenize(input, tokens);
    parse_resume(tokens);

    return 0;
}