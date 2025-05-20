//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char str[1000];
    printf("Enter a message: ");
    fgets(str, 1000, stdin);

    int sentiment = analyzeSentiment(str);

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

int analyzeSentiment(char *str) {
    int length = strlen(str);
    int positiveWords = 0;
    int negativeWords = 0;

    // Iterate over the string and count the number of positive and negative words
    for (int i = 0; i < length; i++) {
        char word[20];
        word[0] = str[i];
        word[1] = '\0';

        if (isPositiveWord(word)) {
            positiveWords++;
        } else if (isNegativeWord(word)) {
            negativeWords++;
        }
    }

    // Calculate the sentiment score
    int sentiment = (positiveWords - negativeWords) / length;

    return sentiment;
}

int isPositiveWord(char *word) {
    char *positiveWords[] = {"happy", "joy", "love", "good", "excellent"};

    for (int i = 0; i < 5; i++) {
        if (strcmp(word, positiveWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int isNegativeWord(char *word) {
    char *negativeWords[] = {"sad", "hate", "fear", "bad", "terrible"};

    for (int i = 0; i < 5; i++) {
        if (strcmp(word, negativeWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}