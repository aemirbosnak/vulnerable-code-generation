//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <string.h>

// function for sentiment analysis
char* sentiment_analysis(char* sentence) {
    // words for positive sentiment analysis
    char positive[5][10] = {"happy", "love", "amazing", "success", "great"};

    // words for negative sentiment analysis
    char negative[5][10] = {"hate", "sad", "fail", "angry", "terrible"};

    int positive_count = 0;
    int negative_count = 0;

    // splitting the sentence into words
    char* word = strtok(sentence, " ");

    while (word != NULL) {
        // checking if the word is in positive sentiment word list
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, positive[i]) == 0) {
                positive_count++;
                break;
            }
        }

        // checking if the word is in negative sentiment word list
        for (int i = 0; i < 5; i++) {
            if (strcmp(word, negative[i]) == 0) {
                negative_count++;
                break;
            }
        }

        // getting the next word
        word = strtok(NULL, " ");
    }

    // final sentiment analysis
    if (positive_count > negative_count) {
        return "POSITIVE SENTIMENT";
    } else if (negative_count > positive_count) {
        return "NEGATIVE SENTIMENT";
    } else {
        return "NEUTRAL SENTIMENT";
    }
}

int main() {
    char* sentence = "I am feeling happy today";  // input sentence for analysis
    printf("Sentiment of the sentence '%s' is %s\n", sentence, sentiment_analysis(sentence));

    return 0;
}