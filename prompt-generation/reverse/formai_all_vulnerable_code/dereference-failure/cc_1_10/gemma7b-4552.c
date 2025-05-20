//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList(char **text, int textLength) {
    Word **wordList = (Word **)malloc(textLength * sizeof(Word *));
    int i = 0;
    for (i = 0; i < textLength; i++) {
        wordList[i] = (Word *)malloc(sizeof(Word));
        wordList[i]->word = strdup(text[i]);
        wordList[i]->frequency = 1;
    }
    return wordList;
}

void analyzeSentiment(Word **wordList, int numWords) {
    int i = 0;
    for (i = 0; i < numWords; i++) {
        char *word = wordList[i]->word;
        if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0) {
            wordList[i]->frequency++;
        } else if (strcmp(word, "sad") == 0 || strcmp(word, "sadness") == 0) {
            wordList[i]->frequency--;
        } else if (strcmp(word, "angry") == 0 || strcmp(word, "hate") == 0) {
            wordList[i]->frequency--;
        }
    }
}

int main() {
    char **text = ("I am happy today. I am sad that I lost my phone. I am angry that I have to do homework.");
    int textLength = 10;

    Word **wordList = createWordList(text, textLength);
    analyzeSentiment(wordList, textLength);

    int i = 0;
    for (i = 0; i < textLength; i++) {
        printf("%s: %d\n", wordList[i]->word, wordList[i]->frequency);
    }

    return 0;
}