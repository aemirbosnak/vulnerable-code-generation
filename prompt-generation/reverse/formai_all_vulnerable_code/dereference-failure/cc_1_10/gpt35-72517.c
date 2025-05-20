//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000

int getSentimentScore(char *sentence);
int calculateScoreFromWords(char **words, int numWords);

int main() {
    char *sentence = (char *) malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    printf("Enter a sentence to check its sentiment: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strcspn(sentence, "\n")] = 0; // remove newline character
    int score = getSentimentScore(sentence);
    printf("\nThe sentiment score of the sentence is %d\n", score);
    free(sentence);
    return 0;
}

// returns the sentiment score of a sentence
int getSentimentScore(char *sentence) {
    char **words = (char **) malloc(MAX_SENTENCE_LENGTH * sizeof(char *));
    int numWords = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }
    int score = calculateScoreFromWords(words, numWords);
    free(words);
    return score;
}

// calculates sentiment score based on words in a sentence
int calculateScoreFromWords(char **words, int numWords) {
    int score = 0;
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0 || strcmp(words[i], "excellent") == 0) {
            score += 3;
        } else if (strcmp(words[i], "nice") == 0 || strcmp(words[i], "happy") == 0 || strcmp(words[i], "awesome") == 0) {
            score += 2;
        } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 || strcmp(words[i], "horrible") == 0) {
            score -= 3;
        } else if (strcmp(words[i], "sad") == 0 || strcmp(words[i], "disappointing") == 0 || strcmp(words[i], "frustrating") == 0) {
            score -= 2;
        }
    }
    return score;
}