//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LEN 1000
#define MAX_WORD_LEN 50
#define NUM_SENTIMENTS 6

typedef struct sentiment {
    char* name;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"joy", 1},
    {"sadness", -1},
    {"anger", -1},
    {"fear", -1},
    {"surprise", 1},
    {"disgust", -1}
};

int get_sentiment_index(char* sentiment_name) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(sentiment_name, sentiments[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_word_sentiment(char* word) {
    int i;
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (strcmp(word, sentiments[i].name) == 0) {
            return sentiments[i].value;
        }
    }
    return 0;
}

int analyze_sentence(char* sentence) {
    int len = strlen(sentence);
    int i = 0;
    int word_start = 0;
    int word_len = 0;
    int num_words = 0;
    int total_sentiment = 0;

    while (i < len) {
        if (isspace(sentence[i])) {
            if (word_len > 0) {
                num_words++;
                total_sentiment += get_word_sentiment(sentence + word_start);
                word_start = i + 1;
                word_len = 0;
            }
        } else {
            if (word_len >= MAX_WORD_LEN) {
                break;
            }
            sentence[i] = tolower(sentence[i]);
            word_len++;
        }
        i++;
    }

    if (word_len > 0) {
        num_words++;
        total_sentiment += get_word_sentiment(sentence + word_start);
    }

    return total_sentiment / num_words;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char* sentence = argv[1];
    int sentiment_score = analyze_sentence(sentence);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}