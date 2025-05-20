//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_CHAR_PER_WORD 20

typedef struct Word {
    char **characters;
    int length;
} Word;

Word **createWord(int length) {
    Word **word = malloc(sizeof(Word) * length);
    for (int i = 0; i < length; i++) {
        word[i] = malloc(sizeof(Word) * MAX_CHAR_PER_WORD);
        word[i]->characters = malloc(sizeof(char *) * MAX_CHAR_PER_WORD);
        word[i]->length = 0;
    }
    return word;
}

int main() {
    Word **words = createWord(MAX_WORDS);

    // Insert words into the dictionary
    words[0]->characters[0] = "Donald";
    words[0]->length++;

    words[1]->characters[0] = "Knuth";
    words[1]->length++;

    // Search for a word
    int found = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < words[i]->length; j++) {
            if (strcmp(words[i]->characters[j], "Donald") == 0) {
                found = 1;
            }
        }
    }

    // Print the result
    if (found) {
        printf("Word found!\n");
    } else {
        printf("Word not found.\n");
    }

    return 0;
}