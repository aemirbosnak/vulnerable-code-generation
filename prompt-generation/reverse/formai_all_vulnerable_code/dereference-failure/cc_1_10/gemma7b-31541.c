//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_SENTIMENT_WORDS 100

typedef struct SentimentWord {
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord sentiment_words[MAX_SENTIMENT_WORDS];

void initialize_sentiment_words() {
    sentiment_words[0].word = "happy";
    sentiment_words[0].sentiment = 1;

    sentiment_words[1].word = "sad";
    sentiment_words[1].sentiment = -1;

    sentiment_words[2].word = "angry";
    sentiment_words[2].sentiment = -1;

    sentiment_words[3].word = "joy";
    sentiment_words[3].sentiment = 1;

    sentiment_words[4].word = "fear";
    sentiment_words[4].sentiment = -1;

    sentiment_words[5].word = "love";
    sentiment_words[5].sentiment = 1;

    sentiment_words[6].word = "hate";
    sentiment_words[6].sentiment = -1;

    sentiment_words[7].word = "surprise";
    sentiment_words[7].sentiment = 0;

    sentiment_words[8].word = "shame";
    sentiment_words[8].sentiment = -1;

    sentiment_words[9].word = "pride";
    sentiment_words[9].sentiment = 1;
}

int analyze_sentiment(char *sentence) {
    initialize_sentiment_words();

    int sentiment = 0;
    for (int i = 0; i < MAX_SENTIMENT_WORDS; i++) {
        if (strcmp(sentence, sentiment_words[i].word) == 0) {
            sentiment += sentiment_words[i].sentiment;
        }
    }

    return sentiment;
}

int main() {
    char *sentence = "I am happy today.";

    int sentiment = analyze_sentiment(sentence);

    if (sentiment > 0) {
        printf("Sentiment: Positive\n");
    } else if (sentiment < 0) {
        printf("Sentiment: Negative\n");
    } else {
        printf("Sentiment: Neutral\n");
    }

    return 0;
}