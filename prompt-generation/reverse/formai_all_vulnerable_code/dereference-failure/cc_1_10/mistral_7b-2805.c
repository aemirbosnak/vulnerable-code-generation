//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

typedef struct {
    char symbol;
    char *translation;
} TranslationTable;

TranslationTable catTranslations[26] = {
    {'A', "MEOW A"},
    {'B', "HISs B"},
    {'C', "MEOW C"},
    {'D', "GRRR D"},
    {'E', "MEOW E"},
    {'F', "FIDDle F"},
    {'G', "GRRR G"},
    {'H', "HISs H"},
    {'I', "MEOW I"},
    {'J', "JUMP J"},
    {'K', "KITTEN K"},
    {'L', "LOL L"},
    {'M', "MEOW M"},
    {'N', "NAP N"},
    {'O', "OW O"},
    {'P', "PURR P"},
    {'Q', "QUACK Q"}, // Cats can quack too, who knows?
    {'R', "RRAWR R"},
    {'S', "SIT S"},
    {'T', "TAP T"},
    {'U', "MEOW U"},
    {'V', "VVC V"},
    {'W', "WOW W"},
    {'X', "XXX X"},
    {'Y', "YAWN Y"},
    {'Z', "Zzz Z"}
};

void translate(char input[]) {
    int i, length = strlen(input);

    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            putchar(catTranslations[tolower(input[i]) - 'A'].symbol);
            puts(catTranslations[tolower(input[i]) - 'A'].translation);
        } else {
            putchar(input[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_LEN];

    if (argc != 2) {
        puts("Usage: catTranslate <text to translate>");
        return 1;
    }

    strcpy(input, argv[1]);
    translate(input);

    return 0;
}