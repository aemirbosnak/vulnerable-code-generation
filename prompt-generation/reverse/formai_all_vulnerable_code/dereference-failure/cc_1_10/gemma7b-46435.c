//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char **words;
    int wordCount;
    int maxWordCount;
} AlienWord;

AlienWord *alienWordCreate(int maxWordCount);
void alienWordDestroy(AlienWord *word);
void alienWordAddWord(AlienWord *word, char *wordStr);

int alienWordTranslate(AlienWord *word, char *phrase);

int main() {
    AlienWord *word = alienWordCreate(MAX_WORDS);
    alienWordAddWord(word, "Blorg");
    alienWordAddWord(word, "Zork");
    alienWordAddWord(word, "Zorg");

    char *phrase = "The Blorg has a big Zork.";
    int translated = alienWordTranslate(word, phrase);

    if (translated) {
        printf("The translated phrase is: %s\n", phrase);
    } else {
        printf("Translation failed.\n");
    }

    alienWordDestroy(word);

    return 0;
}

AlienWord *alienWordCreate(int maxWordCount) {
    AlienWord *word = malloc(sizeof(AlienWord));
    word->words = malloc(sizeof(char *) * maxWordCount);
    word->wordCount = 0;
    word->maxWordCount = maxWordCount;

    return word;
}

void alienWordDestroy(AlienWord *word) {
    free(word->words);
    free(word);
}

void alienWordAddWord(AlienWord *word, char *wordStr) {
    word->words[word->wordCount++] = strdup(wordStr);
}

int alienWordTranslate(AlienWord *word, char *phrase) {
    char **words = word->words;
    int i = 0;

    for (; words[i] && strcmp(words[i], phrase) != 0; i++) {}

    if (words[i] != NULL) {
        return 1;
    }

    return 0;
}