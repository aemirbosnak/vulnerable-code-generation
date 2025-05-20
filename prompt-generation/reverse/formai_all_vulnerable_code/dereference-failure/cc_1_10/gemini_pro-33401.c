//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

struct cat_language_translator {
    char *english_word;
    char *cat_word;
};

struct cat_language_translator cat_language_table[] = {
    {"hello", "meow"},
    {"goodbye", "meow meow"},
    {"thank you", "purr"},
    {"please", "meow meow"},
    {"yes", "meow"},
    {"no", "hiss"},
    {"food", "meow meow"},
    {"water", "meow meow meow"},
    {"play", "meow meow meow meow"},
    {"sleep", "zzz"},
    {NULL, NULL}
};

char *translate_english_to_cat(char *english_word) {
    int i;
    for (i = 0; cat_language_table[i].english_word != NULL; i++) {
        if (strcmp(cat_language_table[i].english_word, english_word) == 0) {
            return cat_language_table[i].cat_word;
        }
    }
    return NULL;
}

char *translate_cat_to_english(char *cat_word) {
    int i;
    for (i = 0; cat_language_table[i].english_word != NULL; i++) {
        if (strcmp(cat_language_table[i].cat_word, cat_word) == 0) {
            return cat_language_table[i].english_word;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    char *english_sentence;
    char *cat_sentence;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <english sentence> <cat sentence>\n", argv[0]);
        return EXIT_FAILURE;
    }

    english_sentence = argv[1];
    cat_sentence = argv[2];

    printf("English sentence: %s\n", english_sentence);
    printf("Cat sentence: %s\n", cat_sentence);

    char *translated_english_sentence = translate_cat_to_english(cat_sentence);
    char *translated_cat_sentence = translate_english_to_cat(english_sentence);

    printf("Translated English sentence: %s\n", translated_english_sentence);
    printf("Translated Cat sentence: %s\n", translated_cat_sentence);

    return EXIT_SUCCESS;
}