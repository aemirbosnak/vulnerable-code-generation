//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *name;
    char *value;
} token_t;

char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, fp);
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
    return line;
}

void split_line(char *line, token_t tokens[], int *num_tokens) {
    char *token;
    int i = 0;
    token = strtok(line, " ");
    while (token!= NULL && i < MAX_TOKENS) {
        tokens[i].name = strdup(token);
        tokens[i].value = NULL;
        i++;
        token = strtok(NULL, " ");
    }
    *num_tokens = i;
}

void free_tokens(token_t tokens[], int num_tokens) {
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i].name!= NULL) {
            free(tokens[i].name);
        }
        if (tokens[i].value!= NULL) {
            free(tokens[i].value);
        }
    }
}

int main() {
    FILE *fp;
    char *line;
    token_t tokens[MAX_TOKENS];
    int num_tokens;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((line = read_line(fp))!= NULL) {
        split_line(line, tokens, &num_tokens);

        printf("Name: %s\n", tokens[0].name);
        printf("Email: %s\n", tokens[1].name);
        printf("Phone Number: %s\n", tokens[2].name);
        printf("Address: %s\n\n", tokens[3].name);

        free_tokens(tokens, num_tokens);
    }

    fclose(fp);
    return 0;
}