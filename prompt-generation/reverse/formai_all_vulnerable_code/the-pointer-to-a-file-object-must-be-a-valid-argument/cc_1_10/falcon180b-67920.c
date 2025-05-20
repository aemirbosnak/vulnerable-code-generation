//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} word_pair_t;

void load_words(word_pair_t *words) {
    FILE *file = fopen("words.txt", "r");
    int i = 0;
    char line[MAX_WORD_LENGTH];

    while (fgets(line, MAX_WORD_LENGTH, file)) {
        word_pair_t pair;
        sscanf(line, "%s %s", pair.word, pair.translation);
        words[i++] = pair;
    }

    fclose(file);
}

void translate_text(char *text, word_pair_t *words) {
    char *token = strtok(text, " ");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORDS && strcmp(words[i].word, token)!= 0) {
            i++;
        }

        if (i < MAX_WORDS) {
            printf("%s ", words[i].translation);
        } else {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    word_pair_t words[MAX_WORDS];
    load_words(words);

    char text[MAX_WORD_LENGTH];
    printf("Enter text to translate: ");
    fgets(text, MAX_WORD_LENGTH, stdin);

    translate_text(text, words);

    return 0;
}