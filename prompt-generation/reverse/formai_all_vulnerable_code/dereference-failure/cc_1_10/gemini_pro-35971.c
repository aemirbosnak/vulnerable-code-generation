//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    char *english;
    char *cat;
} word_pair;

word_pair dictionary[] = {
    {"hello", "meow"},
    {"goodbye", "purr"},
    {"food", "nom nom"},
    {"water", "lap lap"},
    {"sleep", "zzz"},
    {"play", "pounce"},
    {"love", "rub"},
    {"hate", "hiss"},
    {"angry", "growl"},
    {"happy", "chirp"}
};

char *translate(char *english) {
    char *cat = malloc(MAX_STR_LEN);
    int i;

    for (i = 0; i < sizeof(dictionary) / sizeof(word_pair); i++) {
        if (!strcmp(english, dictionary[i].english)) {
            strcpy(cat, dictionary[i].cat);
            return cat;
        }
    }

    strcpy(cat, "???");
    return cat;
}

int main() {
    char *english = "Hello, world!";
    char *cat = translate(english);

    printf("English: %s\n", english);
    printf("Cat: %s\n", cat);

    free(cat);

    return 0;
}