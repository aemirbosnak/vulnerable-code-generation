//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList(int size) {
    Word **words = malloc(size * sizeof(Word));
    for (int i = 0; i < size; i++) {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(MAX_WORDS * sizeof(char));
        words[i]->frequency = 0;
    }
    return words;
}

void addWordToDictionary(Word **words, char *word) {
    int i = 0;
    for (; words[i] && strcmp(words[i]->word, word) != 0; i++) {}
    if (words[i] == NULL) {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(MAX_WORDS * sizeof(char));
        words[i]->frequency = 0;
    }
    strcpy(words[i]->word, word);
    words[i]->frequency++;
}

int main() {
    char *text = "This text contains a lot of spam words, such as free, buy, and miracle. It also has some nonsensical words, like blarney and quagmire.";

    Word **words = createWordList(10);
    addWordToDictionary(words, "free");
    addWordToDictionary(words, "buy");
    addWordToDictionary(words, "miracle");
    addWordToDictionary(words, "blarney");
    addWordToDictionary(words, "quagmire");

    int spamWordCount = 0;
    for (int i = 0; words[i]; i++) {
        if (words[i]->frequency > 1) {
            spamWordCount++;
        }
    }

    printf("Number of spam words: %d\n", spamWordCount);

    return 0;
}