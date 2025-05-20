//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 50

typedef struct {
    char *token;
    int count;
} Token;

int main(int argc, char **argv) {
    int num_tokens = 0;
    Token *tokens = (Token *) malloc(MAX_TOKENS * sizeof(Token));
    memset(tokens, 0, MAX_TOKENS * sizeof(Token));

    FILE *file = fopen("spam.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_TOKEN_LENGTH];
    while (fgets(line, MAX_TOKEN_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_tokens; i++) {
                if (strcmp(word, tokens[i].token) == 0) {
                    tokens[i].count++;
                    break;
                }
            }
            if (i == num_tokens) {
                if (num_tokens == MAX_TOKENS) {
                    printf("Error: Maximum number of tokens reached.\n");
                    exit(1);
                }
                tokens[num_tokens].token = strdup(word);
                tokens[num_tokens].count = 1;
                num_tokens++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    int total_tokens = 0;
    for (int i = 0; i < num_tokens; i++) {
        total_tokens += tokens[i].count;
    }

    printf("Total tokens: %d\n", total_tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }

    free(tokens);
    return 0;
}