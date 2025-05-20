//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int sentiment;
} Word;

Word **createWordList(int size) {
    Word **words = malloc(size * sizeof(Word));
    for (int i = 0; i < size; i++) {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(MAX_WORDS * sizeof(char));
        words[i]->sentiment = 0;
    }
    return words;
}

void analyzeSentiment(Word **words, char *text) {
    char *wordsArray[MAX_WORDS];
    char *token = strtok(text, " ");
    int i = 0;
    while (token) {
        wordsArray[i++] = token;
        token = strtok(NULL, " ");
    }

    for (int j = 0; wordsArray[j] != NULL; j++) {
        for (int k = 0; words[k] != NULL; k++) {
            if (strcmp(wordsArray[j], words[k]->word) == 0) {
                words[k]->sentiment++;
            }
        }
    }
}

int main() {
    Word **words = createWordList(10);
    words[0]->word = "Amazing";
    words[0]->sentiment = 5;
    words[1]->word = "Sad";
    words[1]->sentiment = -3;
    words[2]->word = "Beautiful";
    words[2]->sentiment = 4;

    char *text = "The movie was amazing, but the ending was sad.";

    analyzeSentiment(words, text);

    for (int i = 0; words[i] != NULL; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->sentiment);
    }

    return 0;
}