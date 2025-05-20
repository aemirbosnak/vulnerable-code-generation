//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 50

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    int num_tokens;
    token_t tokens[MAX_TOKENS];
} resume_t;

void add_token(resume_t *resume, char *name, char *value) {
    if (resume->num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens exceeded.\n");
        return;
    }

    resume->tokens[resume->num_tokens].name = strdup(name);
    resume->tokens[resume->num_tokens].value = strdup(value);
    resume->num_tokens++;
}

int main() {
    char line[MAX_TOKEN_LEN];
    char *token;
    char *name;
    char *value;
    resume_t resume;

    resume.num_tokens = 0;

    printf("Enter the name: ");
    fgets(line, MAX_TOKEN_LEN, stdin);
    token = strtok(line, "\n");
    name = strdup(token);
    add_token(&resume, name, "");

    while (1) {
        printf("Enter an attribute (name:value): ");
        fgets(line, MAX_TOKEN_LEN, stdin);
        token = strtok(line, "\n");
        if (token == NULL) {
            break;
        }

        name = strdup(token);
        value = strdup(strtok(NULL, ":"));
        add_token(&resume, name, value);
    }

    printf("Name: %s\n", resume.tokens[0].value);
    for (int i = 1; i < resume.num_tokens; i++) {
        printf("%s: %s\n", resume.tokens[i].name, resume.tokens[i].value);
    }

    return 0;
}