//Falcon-180B DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define DELIMITER " \t\r\n"

typedef struct {
    char *name;
    char *value;
} token_t;

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char *delim = DELIMITER;
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;
    FILE *fp;
    char *filename = argv[1];
    char query[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok_r(line, delim, &line);
        while (token!= NULL) {
            if (num_tokens == MAX_TOKENS) {
                printf("Error: Too many tokens in line\n");
                exit(1);
            }
            tokens[num_tokens].name = strdup(token);
            token = strtok_r(NULL, delim, &line);
            if (token == NULL) {
                tokens[num_tokens].value = strdup("");
            } else {
                tokens[num_tokens].value = strdup(token);
            }
            num_tokens++;
        }
    }

    fclose(fp);

    printf("Enter SQL query:\n");
    fgets(query, MAX_LINE_LENGTH, stdin);

    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i].name, "name") == 0) {
            strcat(query, " AND name='");
            strcat(query, tokens[i].value);
            strcat(query, "'");
        } else if (strcmp(tokens[i].name, "age") == 0) {
            strcat(query, " AND age='");
            strcat(query, tokens[i].value);
            strcat(query, "'");
        }
    }

    printf("SQL query: %s\n", query);

    return 0;
}