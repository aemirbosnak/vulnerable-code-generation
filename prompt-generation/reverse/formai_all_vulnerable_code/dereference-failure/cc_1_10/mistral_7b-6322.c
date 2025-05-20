//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Thou art hereby forbidden, cursed sorcerous symbols!
#define FORBIDDEN_CHARS "AEIOUaeiou"

// Thou shalt translate these thou art given
const char* words[] = {
    "thou", "art", "a", "cat", "translator", "program", "in", "medieval", "style", "C", "Language"
};

// Thy function to translate thee input word
char* translateWord(char* word) {
    int i, j;
    char* translated = (char*) malloc(strlen(word) + 1);

    for (i = 0; word[i]; i++) {
        if (strchr(FORBIDDEN_CHARS, word[i]) || isspace(word[i])) {
            // Thou shalt replace forbidden chars with 'x'
            translated[i] = 'x';
            continue;
        }

        // Translate thee medieval-style letter
        for (j = 0; words[0][j]; j++) {
            if (tolower(words[0][j]) == tolower(word[i])) {
                translated[i] = words[j][0];
                break;
            }
        }

        if (words[j][0] == '\0') {
            // If not found, keep the original char
            translated[i] = word[i];
        }
    }

    translated[strlen(word)] = '\0';
    return translated;
}

int main() {
    char input[100], output[100];
    int i;

    printf("Enter a word to translate: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    strcpy(output, input);

    for (i = 0; input[i]; i++) {
        output[i] = translateWord(input + i)[0];
    }

    printf("Translated word: %s\n", output);

    free(translateWord(input));

    return 0;
}