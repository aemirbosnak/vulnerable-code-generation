//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

int calculateSentimentScore(char* sentence);

int main() {
    char sentence[1000];
    printf("Enter a sentence to analyze its sentiment: ");
    fgets(sentence, 1000, stdin);

    int sentimentScore = calculateSentimentScore(sentence);

    if (sentimentScore > 0) {
        printf("\nPositive Sentiment with Score of %d", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("\nNegative Sentiment with Score of %d", sentimentScore);
    } else {
        printf("\nNeutral Sentiment");
    }

    return 0;
}

int calculateSentimentScore(char* sentence) {
    char* positiveWords[5] = {"good", "great", "awesome", "amazing", "excellent"};
    char* negativeWords[5] = {"bad", "terrible", "awful", "horrible", "poor"};

    int positiveScore = 0;
    int negativeScore = 0;
    int sentenceLength = strlen(sentence);

    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ') {
            char word[i];
            strncpy(word, sentence, i);
            word[i] = '\0';
            for (int j = 0; j < 5; j++) {
                if (strcmp(word, positiveWords[j]) == 0) {
                    positiveScore += 1;
                }
                if (strcmp(word, negativeWords[j]) == 0) {
                    negativeScore += 1;
                }
            }
            sentence += i + 1;
            sentenceLength -= i + 1;
            i = 0;
        }
    }

    return positiveScore - negativeScore;
}