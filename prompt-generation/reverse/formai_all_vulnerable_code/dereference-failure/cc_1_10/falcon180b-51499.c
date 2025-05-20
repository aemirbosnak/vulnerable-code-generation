//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

struct token {
    char *str;
    int len;
    int freq;
};

void count_tokens(char *text, struct token *tokens, int num_tokens) {
    int i, j;
    char *word = strtok(text, ",.!?;:");

    while (word!= NULL) {
        for (i = 0; i < num_tokens; i++) {
            if (strcmp(word, tokens[i].str) == 0) {
                tokens[i].freq++;
                break;
            }
        }

        if (i == num_tokens) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Too many tokens!\n");
                exit(1);
            }

            tokens[num_tokens].str = strdup(word);
            tokens[num_tokens].len = strlen(word);
            tokens[num_tokens].freq = 1;
            num_tokens++;
        }

        word = strtok(NULL, ",.!?;:");
    }
}

int main() {
    char *text;
    int len;
    struct token *tokens;
    int num_tokens = 0;

    printf("Enter some text:\n");
    fgets(text, 100000, stdin);
    len = strlen(text);

    tokens = (struct token *)malloc(sizeof(struct token) * MAX_TOKENS);

    count_tokens(text, tokens, num_tokens);

    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %d\n", tokens[i].str, tokens[i].freq);
    }

    return 0;
}