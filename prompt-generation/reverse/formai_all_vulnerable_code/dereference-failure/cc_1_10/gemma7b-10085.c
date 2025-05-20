//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100

struct Word {
    char *word;
    struct Word *next;
};

struct Translator {
    struct Word **words;
    int current_index;
    int max_index;
};

void translator_init(struct Translator *translator) {
    translator->words = NULL;
    translator->current_index = 0;
    translator->max_index = MAX_WORDS - 1;
}

void translator_add_word(struct Translator *translator, char *word) {
    struct Word *new_word = malloc(sizeof(struct Word));
    new_word->word = strdup(word);
    new_word->next = NULL;

    if (translator->words == NULL) {
        translator->words = &new_word;
    } else {
        translator->words[translator->current_index]->next = new_word;
        translator->current_index++;
    }

    if (translator->current_index == translator->max_index) {
        translator->max_index++;
    }
}

char *translator_get_word(struct Translator *translator, int index) {
    struct Word *word = translator->words[index];
    return word->word;
}

int main() {
    struct Translator translator;
    translator_init(&translator);

    translator_add_word(&translator, "Hello");
    translator_add_word(&translator, "World");
    translator_add_word(&translator, "Cat");

    char *word = translator_get_word(&translator, 1);
    printf("%s\n", word);

    return 0;
}