//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} token_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token, *saveptr;
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;

    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok_r(line, "\n", &saveptr);
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens.\n");
                fclose(fp);
                return 1;
            }

            tokens[num_tokens].name = strdup(token);
            tokens[num_tokens].value = strdup("");

            token = strtok_r(NULL, "\n", &saveptr);
            num_tokens++;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_tokens; i++) {
        printf("Name: %s\nValue: %s\n\n", tokens[i].name, tokens[i].value);
    }

    return 0;
}