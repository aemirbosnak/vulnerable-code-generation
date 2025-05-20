//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **words;

void analyzeText(char *text) {
    char *word = strtok(text, " ");
    words = malloc(MAX_WORDS * sizeof(Word));
    int i = 0;
    while (word) {
        Word *newWord = malloc(sizeof(Word));
        newWord->word = strdup(word);
        newWord->frequency = 1;
        words[i++] = newWord;
        word = strtok(NULL, " ");
    }
}

int detectSpam(char *subject, char *body) {
    analyzeText(subject);
    analyzeText(body);

    int spamScore = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        Word *word = words[i];
        if (word->frequency > 5) {
            spamScore++;
        }
    }

    free(words);
    return spamScore;
}

int main() {
    char *subject = "Free iPhone!";
    char *body = "Buy this phone now and get a free iPhone!";

    int spamScore = detectSpam(subject, body);

    printf("Spam score: %d", spamScore);

    return 0;
}