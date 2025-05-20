//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 64

typedef struct {
    char *name;
    char *value;
} token_t;

token_t tokens[MAX_TOKENS];
int num_tokens = 0;

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
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token_name = strtok(line, ": ");
        char *token_value = strtok(NULL, ": ");

        if (token_name == NULL || token_value == NULL) {
            printf("Error: Invalid metadata format!\n");
            fclose(file);
            return 1;
        }

        add_token(token_name, token_value);
    }

    fclose(file);
    print_tokens();

    return 0;
}