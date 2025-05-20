//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

int main() {
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);

    int sentiment = analyzeSentiment(words);

    switch (sentiment) {
        case 0:
            printf("Neutral\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        case -1:
            printf("Negative\n");
            break;
    }

    return 0;
}

int tokenize(char *text, char **words) {
    int num_words = 0;
    words = (char **)malloc(MAX_WORDS * sizeof(char *));

    char *token = strtok(text, " ");
    while (token) {
        words[num_words++] = token;
        token = strtok(NULL, " ");
    }

    return num_words;
}

int analyzeSentiment(char **words) {
    int sentiment = 0;
    for (int i = 0; words[i] != NULL; i++) {
        char word[20];
        strcpy(word, words[i]);

        if (isPositiveWord(word)) {
            sentiment++;
        } else if (isNegativeWord(word)) {
            sentiment--;
        }
    }

    return sentiment;
}

int isPositiveWord(char *word) {
    // List of positive words
    char *positive_words[] = {"happy", "joy", "good", "excellent", "marvelous"};

    for (int i = 0; positive_words[i] != NULL; i++) {
        if (strcmp(word, positive_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int isNegativeWord(char *word) {
    // List of negative words
    char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful"};

    for (int i = 0; negative_words[i] != NULL; i++) {
        if (strcmp(word, negative_words[i]) == 0) {
            return -1;
        }
    }

    return 0;
}