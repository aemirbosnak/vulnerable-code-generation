//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_WORD_LENGTH 100

typedef struct token {
    char *word;
    int count;
} Token;

typedef struct sentence {
    int num_tokens;
    Token *tokens;
} Sentence;

void init_token(Token *token) {
    token->word = malloc(MAX_WORD_LENGTH * sizeof(char));
    token->word[0] = '\0';
    token->count = 0;
}

void init_sentence(Sentence *sentence) {
    sentence->num_tokens = 0;
    sentence->tokens = malloc(MAX_TOKENS * sizeof(Token));
}

void add_token(Sentence *sentence, char *word) {
    Token *token = &sentence->tokens[sentence->num_tokens];
    init_token(token);
    strcpy(token->word, word);
    sentence->num_tokens++;
}

void print_sentence(Sentence *sentence) {
    for (int i = 0; i < sentence->num_tokens; i++) {
        Token *token = &sentence->tokens[i];
        printf("%s: %d\n", token->word, token->count);
    }
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: input file not found.\n");
        return 1;
    }

    Sentence sentence;
    init_sentence(&sentence);

    char word[MAX_WORD_LENGTH];
    while (fscanf(input_file, "%s", word)!= EOF) {
        add_token(&sentence, word);
    }

    fclose(input_file);

    print_sentence(&sentence);

    return 0;
}