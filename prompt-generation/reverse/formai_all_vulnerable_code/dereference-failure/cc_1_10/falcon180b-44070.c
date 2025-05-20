//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 64
#define MAX_TOKENS 1000
#define MIN_TOKEN_LENGTH 3

// Token structure
typedef struct {
    char *token;
    int count;
} token_t;

// Token list
token_t tokens[MAX_TOKENS];
int num_tokens = 0;

// Function to split input into tokens
void tokenize(char *input) {
    char *token;
    int i = 0;

    // Remove leading/trailing whitespace
    while (isspace(*input)) {
        input++;
    }
    while (i < strlen(input) &&!isspace(input[i])) {
        i++;
    }
    input[i] = '\0';

    // Split input into tokens
    token = strtok(input, " ");
    while (token!= NULL) {
        if (strlen(token) >= MIN_TOKEN_LENGTH) {
            if (num_tokens >= MAX_TOKENS) {
                break;
            }
            tokens[num_tokens].token = strdup(token);
            tokens[num_tokens].count = 1;
            num_tokens++;
        }
        token = strtok(NULL, " ");
    }
}

// Function to compare two tokens
int compare_tokens(const void *a, const void *b) {
    token_t *ta = (token_t *)a;
    token_t *tb = (token_t *)b;
    return strcmp(ta->token, tb->token);
}

// Function to count token frequency
void count_tokens(char *input) {
    tokenize(input);

    // Sort tokens
    qsort(tokens, num_tokens, sizeof(token_t), compare_tokens);

    // Print token frequencies
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].token, tokens[i].count);
    }
}

int main() {
    char input[1024];
    printf("Enter input:\n");
    fgets(input, sizeof(input), stdin);
    count_tokens(input);
    return 0;
}