//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **loadWords(char *text) {
    Word **words = malloc(MAX_WORDS * sizeof(Word));
    char *word = strtok(text, " ");
    int i = 0;
    while (word) {
        Word *newWord = malloc(sizeof(Word));
        newWord->word = strdup(word);
        newWord->frequency = 1;
        words[i++] = newWord;
        word = strtok(NULL, " ");
    }
    return words;
}

int analyzeSentiment(Word **words) {
    int totalSentiment = 0;
    for (int i = 0; words[i] != NULL; i++) {
        char *word = words[i]->word;
        if (strcmp(word, "sad") == 0 || strcmp(word, "sadness") == 0) {
            totalSentiment -= 2;
        } else if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0) {
            totalSentiment += 2;
        } else if (strcmp(word, "angry") == 0 || strcmp(word, "anger") == 0) {
            totalSentiment -= 1;
        } else if (strcmp(word, "love") == 0 || strcmp(word, "lovely") == 0) {
            totalSentiment += 1;
        }
    }
    return totalSentiment;
}

int main() {
    char text[] = "I am sad, but I am also happy. I am angry, but I am also loving.";
    Word **words = loadWords(text);
    int sentiment = analyzeSentiment(words);
    printf("Overall sentiment: %d\n", sentiment);
    return 0;
}