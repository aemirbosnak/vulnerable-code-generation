//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100
#define MAX_TOKENS 10

typedef struct token {
    char *str;
    int len;
} token_t;

typedef struct translation {
    char *alien;
    char *english;
} translation_t;

int main() {
    char str[MAX_STR];
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;

    printf("Enter a string to translate:\n");
    fgets(str, MAX_STR, stdin);

    // Tokenize the input string
    char *tok = strtok(str, " ");
    while (tok != NULL && num_tokens < MAX_TOKENS) {
        tokens[num_tokens].str = tok;
        tokens[num_tokens].len = strlen(tok);
        num_tokens++;
        tok = strtok(NULL, " ");
    }

    // Translate each token
    translation_t *translations = malloc(sizeof(translation_t) * num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        translations[i].alien = malloc(MAX_STR);
        translations[i].english = malloc(MAX_STR);

        // Simple translation table
        if (strcmp(tokens[i].str, "hello") == 0) {
            strcpy(translations[i].alien, "zorgg");
            strcpy(translations[i].english, "hello");
        } else if (strcmp(tokens[i].str, "world") == 0) {
            strcpy(translations[i].alien, "klatuu");
            strcpy(translations[i].english, "world");
        } else if (strcmp(tokens[i].str, "!") == 0) {
            strcpy(translations[i].alien, "barada");
            strcpy(translations[i].english, "!");
        } else {
            strcpy(translations[i].alien, tokens[i].str);
            strcpy(translations[i].english, tokens[i].str);
        }
    }

    // Output the translation
    printf("Translation:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (%s)\n", translations[i].alien, translations[i].english);
    }

    // Free the allocated memory
    for (int i = 0; i < num_tokens; i++) {
        free(translations[i].alien);
        free(translations[i].english);
    }
    free(translations);

    return 0;
}