//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

typedef struct Word {
    char *word;
    int frequency;
} Word;

typedef struct Sentence {
    char *sentence;
    Word *words;
} Sentence;

Sentence *createSentence(char *sentence) {
    Sentence *s = malloc(sizeof(Sentence));
    s->sentence = strdup(sentence);

    char *words = strtok(sentence, " ");
    s->words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    while (words) {
        s->words[i].word = strdup(words);
        s->words[i].frequency = 1;
        words = strtok(NULL, " ");
        i++;
    }

    return s;
}

void analyzeSentiment(Sentence *s) {
    int positiveWords = 0;
    int negativeWords = 0;
    for (int i = 0; i < s->words->frequency; i++) {
        if (strcmp(s->words[i].word, "good") == 0 || strcmp(s->words[i].word, "happy") == 0) {
            positiveWords++;
        } else if (strcmp(s->words[i].word, "bad") == 0 || strcmp(s->words[i].word, "sad") == 0) {
            negativeWords++;
        }
    }

    printf("Sentiment analysis:\n");
    printf("Positive words: %d\n", positiveWords);
    printf("Negative words: %d\n", negativeWords);
    printf("Overall sentiment: %s\n", positiveWords > negativeWords ? "Positive" : "Negative");
}

int main() {
    char sentence[] = "I am happy today, but I am sad that I lost my cat.";
    Sentence *s = createSentence(sentence);
    analyzeSentiment(s);

    free(s);
    return 0;
}