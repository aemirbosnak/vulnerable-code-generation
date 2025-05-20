//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CatPhrase {
    char *english;
    char *cat;
} CatPhrase;

CatPhrase catPhrases[] = {
    {"hello", "mrow mrow"},
    {"goodbye", "meow meow miaow miaow"},
    {"how are you?", "meow meow miaow miaow meow meow?"},
    {"I am fine.", "miaow miaow miaow miaow miaow meow miaow"},
    {"what is your name?", "miaow miaow meow meow meow meow meow meow meow meow?"},
    {"my name is", "miaow miaow miaow miaow miaow miaow miaow miaow miaow miaow miaow"},
    {"cat", "miaow miaow miaow miaow"},
    {"dog", "wuff wuff wuff wuff"},
    {"food", "miaow miaow miaow miaow miaow"},
    {NULL, NULL}
};

int findCatPhraseIndex(const char *english) {
    for (int i = 0; catPhrases[i].english != NULL; ++i) {
        if (strcmp(catPhrases[i].english, english) == 0) {
            return i;
        }
    }
    return -1;
}

void printCatPhrase(const CatPhrase *catPhrase) {
    printf("%s: %s\n", catPhrase->english, catPhrase->cat);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <English phrase>\n", argv[0]);
        return 1;
    }

    int index = findCatPhraseIndex(argv[1]);
    if (index == -1) {
        printf("Unknown English phrase: %s\n", argv[1]);
        return 1;
    }

    printCatPhrase(&catPhrases[index]);

    return 0;
}