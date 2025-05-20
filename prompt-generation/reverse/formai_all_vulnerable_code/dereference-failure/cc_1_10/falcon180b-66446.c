//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    int num_tokens;
    char **tokens;
} TokenArray;

void tokenize(char *sentence, TokenArray *tokens) {
    char *delimiters = ",.!?;:\"'";
    int num_tokens = 0;
    char *token = strtok(sentence, delimiters);

    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }
        tokens->tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, delimiters);
    }

    tokens->num_tokens = num_tokens;
}

void count_words(TokenArray *tokens, WordCount *word_counts) {
    int i, j;
    for (i = 0; i < tokens->num_tokens; i++) {
        if (strlen(tokens->tokens[i]) > MAX_WORD_LENGTH) {
            printf("Error: Word too long.\n");
            exit(1);
        }
        for (j = 0; j < i; j++) {
            if (strcmp(tokens->tokens[i], tokens->tokens[j]) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (j == i) {
            word_counts[i].word = strdup(tokens->tokens[i]);
            word_counts[i].count = 1;
        }
    }
}

void print_word_counts(WordCount *word_counts, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char *sentence = argv[1];
    TokenArray tokens;
    WordCount word_counts[MAX_TOKENS];

    tokenize(sentence, &tokens);
    count_words(&tokens, word_counts);
    print_word_counts(word_counts, tokens.num_tokens);

    return 0;
}