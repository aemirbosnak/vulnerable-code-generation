//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char* name;
    char* value;
} token_t;

token_t* tokens = NULL;
int num_tokens = 0;

void add_token(char* name, char* value) {
    token_t* new_token = (token_t*)malloc(sizeof(token_t));
    new_token->name = name;
    new_token->value = value;
    tokens[num_tokens++] = *new_token;
}

int main(int argc, char** argv) {
    FILE* resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        printf("Error: Could not open resume file.\n");
        exit(1);
    }

    char line[MAX_TOKEN_LEN];
    while (fgets(line, MAX_TOKEN_LEN, resume_file)!= NULL) {
        char* token;
        char* value;
        token = strtok(line, ":");
        while (token!= NULL) {
            value = strtok(NULL, ":");
            if (value == NULL) {
                printf("Error: Invalid token format.\n");
                exit(1);
            }
            add_token(token, value);
            token = strtok(NULL, ":");
        }
    }

    fclose(resume_file);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    return 0;
}