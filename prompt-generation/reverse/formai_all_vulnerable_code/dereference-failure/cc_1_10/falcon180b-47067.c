//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *name;
    int value;
} Token;

int main(int argc, char **argv) {
    FILE *inputFile = NULL;
    char line[200];
    char *token = NULL;
    int numTokens = 0;
    Token tokens[MAX_TOKENS];

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (numTokens >= MAX_TOKENS) {
                printf("Error: Maximum number of tokens reached.\n");
                exit(1);
            }

            strncpy(tokens[numTokens].name, token, MAX_TOKEN_LENGTH);
            tokens[numTokens].name[MAX_TOKEN_LENGTH - 1] = '\0';

            if (isdigit(tokens[numTokens].name[0])) {
                tokens[numTokens].value = atoi(tokens[numTokens].name);
            } else {
                tokens[numTokens].value = 0;
            }

            numTokens++;

            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    printf("Number of tokens: %d\n", numTokens);
    for (int i = 0; i < numTokens; i++) {
        printf("Token %d: %s\n", i + 1, tokens[i].name);
        printf("Value: %d\n\n", tokens[i].value);
    }

    return 0;
}