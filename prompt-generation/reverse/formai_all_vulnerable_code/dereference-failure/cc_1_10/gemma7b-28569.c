//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

typedef struct Word {
    char *word;
    int sentiment;
} Word;

Word *read_words(char *text) {
    Word *words = malloc(MAX_WORDS * sizeof(Word));
    char *word_ptr = strtok(text, " ");
    int i = 0;

    while (word_ptr) {
        words[i].word = strdup(word_ptr);
        words[i].sentiment = sentiment_score(words[i].word);
        i++;
        word_ptr = strtok(NULL, " ");
    }

    return words;
}

int sentiment_score(char *word) {
    int score = 0;

    if (strcmp(word, "happy") == 0) {
        score = 5;
    } else if (strcmp(word, "sad") == 0) {
        score = -5;
    } else if (strcmp(word, "angry") == 0) {
        score = -3;
    } else if (strcmp(word, "excited") == 0) {
        score = 3;
    } else if (strcmp(word, "neutral") == 0) {
        score = 0;
    }

    return score;
}

int main() {
    char text[] = "I am happy today, but I am sad that I have to go to school. I am angry that I lost my phone, but I am excited about the party later.";

    Word *words = read_words(text);

    for (int i = 0; words[i].word; i++) {
        printf("%s has a sentiment score of %d\n", words[i].word, words[i].sentiment);
    }

    free(words);

    return 0;
}