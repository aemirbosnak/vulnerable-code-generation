//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

struct word {
    char *text;
    size_t length;
};

struct dict {
    struct word *words;
    size_t num_words;
};

void init_dict(struct dict *dict) {
    dict->words = NULL;
    dict->num_words = 0;
}

void add_word(struct dict *dict, const char *word) {
    struct word *new_word = malloc(sizeof(struct word));
    new_word->text = strdup(word);
    new_word->length = strlen(word);
    dict->words = realloc(dict->words, (dict->num_words + 1) * sizeof(struct word));
    dict->words[dict->num_words] = *new_word;
    dict->num_words++;
}

void check_spelling(struct dict *dict, const char *text) {
    size_t i, j;
    for (i = 0; i < strlen(text); i++) {
        char c = text[i];
        for (j = 0; j < dict->num_words; j++) {
            if (c == dict->words[j].text[j]) {
                // Found a match!
                break;
            }
        }
        if (j == dict->num_words) {
            // Not found, must be a misspelling!
            printf("Misspelling found at character %zu: %c\n", i, c);
        }
    }
}

int main() {
    struct dict dict;
    init_dict(&dict);

    // Add some words to the dictionary
    add_word(&dict, "hello");
    add_word(&dict, "world");
    add_word(&dict, "four score and seven years ago");

    // Check the spelling of a sentence
    char sentence[] = "Four scroe and seveen yeers ago";
    check_spelling(&dict, sentence);

    // Check the spelling of a single word
    char word[] = "sccroe";
    check_spelling(&dict, word);

    return 0;
}