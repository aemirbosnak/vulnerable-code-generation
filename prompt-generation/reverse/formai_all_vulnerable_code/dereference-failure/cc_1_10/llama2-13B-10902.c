//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WORD_COUNT_MAX 100000

struct word {
    char *text;
    size_t len;
};

struct doc {
    struct word *words;
    size_t count;
};

void init_word_list(struct doc *doc) {
    doc->words = calloc(WORD_COUNT_MAX, sizeof(struct word));
    doc->count = 0;
}

void add_word(struct doc *doc, char *text) {
    size_t len = strlen(text);
    struct word *word = calloc(1, sizeof(struct word));
    word->text = text;
    word->len = len;
    doc->words[doc->count++] = *word;
}

size_t get_word_count(struct doc *doc) {
    return doc->count;
}

void print_word_list(struct doc *doc) {
    for (size_t i = 0; i < doc->count; i++) {
        printf("%s (%zu)\n", doc->words[i].text, doc->words[i].len);
    }
}

int main() {
    struct doc doc;
    init_word_list(&doc);

    char *text = "The quick brown fox jumps over the lazy dog.";
    add_word(&doc, text);

    text = "The quick brown fox jumps over the lazy dog again.";
    add_word(&doc, text);

    text = "The quick brown fox jumps over the lazy dog once more.";
    add_word(&doc, text);

    print_word_list(&doc);

    return 0;
}