//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *filename;
    int linenumber;
    int numtokens;
    char **tokens;
} Metadata;

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Line Number: %d\n", metadata->linenumber);
    printf("Number of Tokens: %d\n", metadata->numtokens);
    for (int i = 0; i < metadata->numtokens; i++) {
        printf("Token %d: %s\n", i, metadata->tokens[i]);
    }
}

void free_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->numtokens; i++) {
        free(metadata->tokens[i]);
    }
    free(metadata->tokens);
    free(metadata);
}

Metadata *extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[MAX_TOKEN_LEN];
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->filename = filename;
    metadata->linenumber = 1;
    metadata->numtokens = 0;
    metadata->tokens = malloc(MAX_TOKENS * sizeof(char *));

    while (fgets(line, MAX_TOKEN_LEN, file)!= NULL) {
        char *token;
        int numtokens = 0;
        for (int i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                line[i] = '\0';
            }
        }
        token = strtok(line, " ");
        while (token!= NULL) {
            metadata->tokens[numtokens] = strdup(token);
            numtokens++;
            token = strtok(NULL, " ");
        }
        metadata->numtokens = numtokens;
        metadata->linenumber++;
    }

    fclose(file);
    return metadata;
}

int main() {
    char filename[MAX_TOKEN_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    Metadata *metadata = extract_metadata(filename);
    if (metadata == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    print_metadata(metadata);
    free_metadata(metadata);

    return 0;
}