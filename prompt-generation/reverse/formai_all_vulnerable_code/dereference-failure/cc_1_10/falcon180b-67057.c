//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens!\n");
        exit(1);
    }
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

void print_tokens() {
    int i;
    for (i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main() {
    char line[1000];
    char *token;
    char *value;
    int in_section = 0;
    char section[100];

    while (fgets(line, sizeof(line), stdin)!= NULL) {
        if (line[0] == '[') {
            if (in_section) {
                printf("Error: Nested sections not allowed!\n");
                exit(1);
            }
            in_section = 1;
            strcpy(section, line + 1);
            section[strcspn(section, "]")] = '\0';
        } else if (line[0] == ']') {
            if (!in_section) {
                printf("Error: Mismatched section end!\n");
                exit(1);
            }
            in_section = 0;
        } else if (in_section) {
            token = strtok(line, " \t\r\n");
            value = strtok(NULL, " \t\r\n");
            if (token == NULL || value == NULL) {
                printf("Error: Invalid token/value!\n");
                exit(1);
            }
            add_token(token, value);
        }
    }

    print_tokens();

    return 0;
}