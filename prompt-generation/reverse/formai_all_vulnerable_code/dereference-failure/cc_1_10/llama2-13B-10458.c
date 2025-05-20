//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 42

struct word {
    char *text;
    size_t length;
};

struct dict {
    struct word *words;
    size_t count;
};

struct spell_checker {
    struct dict *dict;
    size_t position;
};

void init_dict(struct dict **dict) {
    *dict = calloc(1, sizeof(struct word));
    return;
}

void add_word(struct dict *dict, char *word) {
    struct word *new_word = calloc(1, sizeof(struct word));
    new_word->text = word;
    new_word->length = strlen(word);
    dict->words = realloc(dict->words, (dict->count + 1) * sizeof(struct word));
    dict->words[dict->count++] = *new_word;
    return;
}

void check_spelling(struct spell_checker *spell_checker, char *text) {
    size_t i, j;
    for (i = 0; i < spell_checker->position; i++) {
        struct word *word = spell_checker->dict->words + i;
        for (j = 0; j < word->length; j++) {
            if (text[j] != word->text[j]) {
                printf("Error: %c is not %c\n", text[j], word->text[j]);
                return;
            }
        }
    }
    return;
}

int main() {
    struct spell_checker spell_checker;
    struct dict *dict;

    init_dict(&dict);
    add_word(dict, "cat");
    add_word(dict, "dog");
    add_word(dict, "elephant");

    spell_checker.dict = dict;
    spell_checker.position = 0;

    char text[] = "The cat sat on the mat and sewed a needle";
    check_spelling(&spell_checker, text);

    return 0;
}