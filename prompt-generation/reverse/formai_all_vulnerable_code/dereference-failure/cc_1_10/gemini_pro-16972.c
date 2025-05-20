//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *text;
    size_t length;
} text_t;

typedef struct {
    char *word;
    size_t length;
    size_t count;
} word_t;

static size_t _word_count(const char *text) {
    size_t count = 0;
    bool in_word = false;
    for (size_t i = 0; i < strlen(text); ++i) {
        if (isalpha(text[i])) {
            if (!in_word) {
                ++count;
                in_word = true;
            }
        } else {
            in_word = false;
        }
    }
    return count;
}

static word_t *_add_word(word_t *words, size_t *word_count, const char *word) {
    for (size_t i = 0; i < *word_count; ++i) {
        if (strcmp(words[i].word, word) == 0) {
            ++words[i].count;
            return &words[i];
        }
    }
    words = realloc(words, sizeof(word_t) * (*word_count + 1));
    words[*word_count].word = strdup(word);
    words[*word_count].length = strlen(word);
    words[*word_count].count = 1;
    ++*word_count;
    return &words[*word_count - 1];
}

static void _print_words(const word_t *words, size_t word_count) {
    for (size_t i = 0; i < word_count; ++i) {
        printf("%s: %zu\n", words[i].word, words[i].count);
    }
}

static void _free_words(word_t *words, size_t word_count) {
    for (size_t i = 0; i < word_count; ++i) {
        free(words[i].word);
    }
    free(words);
}

static void _usage(const char *argv0) {
    fprintf(stderr, "Usage: %s <text>\n", argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        _usage(argv[0]);
    }

    text_t text = { .text = argv[1], .length = strlen(argv[1]) };

    size_t word_count = _word_count(text.text);
    word_t *words = calloc(word_count, sizeof(word_t));

    const char *start = text.text;
    for (size_t i = 0; i < text.length; ++i) {
        if (!isalpha(text.text[i])) {
            if (start != text.text + i) {
                _add_word(words, &word_count, start);
            }
            start = text.text + i + 1;
        }
    }
    if (start != text.text + text.length) {
        _add_word(words, &word_count, start);
    }

    _print_words(words, word_count);
    _free_words(words, word_count);

    return EXIT_SUCCESS;
}