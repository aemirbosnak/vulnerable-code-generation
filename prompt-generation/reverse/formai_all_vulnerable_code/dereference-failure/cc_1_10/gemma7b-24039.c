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

Word **createWordList(char **text) {
    Word **words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    char *word = NULL;
    for (int j = 0; text[j] != NULL; j++) {
        word = malloc(20 * sizeof(char));
        strcpy(word, text[j]);
        words[i] = malloc(sizeof(Word));
        words[i]->word = word;
        words[i]->frequency = 1;
        i++;
    }
    return words;
}

int analyzeSentiment(Word **words) {
    int positive = 0;
    int negative = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (strcmp(words[i]->word, "good") == 0 || strcmp(words[i]->word, "nice") == 0 || strcmp(words[i]->word, "excellent") == 0) {
            positive++;
        } else if (strcmp(words[i]->word, "bad") == 0 || strcmp(words[i]->word, "awful") == 0 || strcmp(words[i]->word, "terrible") == 0) {
            negative++;
        }
    }
    return (positive - negative) * 100 / (positive + negative);
}

int main() {
    char **text = malloc(100 * sizeof(char *));
    text[0] = "This is a positive text";
    text[1] = "It is a very good text";
    text[2] = "I am happy with this text";

    Word **words = createWordList(text);
    int sentiment = analyzeSentiment(words);

    printf("Sentiment score: %d%%", sentiment);

    return 0;
}