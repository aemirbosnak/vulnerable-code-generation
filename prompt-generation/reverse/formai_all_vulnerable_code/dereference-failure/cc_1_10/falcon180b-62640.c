//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

typedef struct {
    char *name;
    char *value;
} metadata_token;

metadata_token *tokens = NULL;
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many metadata tokens.\n");
        exit(1);
    }
    tokens = realloc(tokens, sizeof(metadata_token) * (num_tokens + 1));
    tokens[num_tokens].name = strdup(name);
    tokens[num_tokens].value = strdup(value);
    num_tokens++;
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char *name, *value;
    int in_metadata = 0;
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        line_number++;
        if (line[0] == '#' && in_metadata == 0) {
            in_metadata = 1;
            continue;
        } else if (line[0]!= '#' && in_metadata == 1) {
            in_metadata = 0;
            continue;
        }
        if (in_metadata == 1) {
            name = strtok(line, ": ");
            value = strtok(NULL, ": ");
            if (name == NULL || value == NULL) {
                printf("Error: Invalid metadata on line %d.\n", line_number);
                exit(1);
            }
            add_token(name, value);
        }
    }

    printf("Metadata:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }

    free(tokens);
    return 0;
}