//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTIMENT_POSITIVE 1
#define SENTIMENT_NEGATIVE -1
#define SENTIMENT_NEUTRAL 0

char *sentiment_dict[] = {
    "love", "happy", "good", "great", "awesome",
    "hate", "sad", "bad", "terrible", "awful"
};

int sentiment_analysis(char *text) {
    int sentiment = SENTIMENT_NEUTRAL;
    char *word;

    for (word = strtok(text, " "); word; word = strtok(NULL, " ")) {
        int i;
        for (i = 0; i < sizeof(sentiment_dict) / sizeof(char *); i++) {
            if (strcmp(word, sentiment_dict[i]) == 0) {
                sentiment += (i < 5) ? SENTIMENT_POSITIVE : SENTIMENT_NEGATIVE;
                break;
            }
        }
    }

    return sentiment;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sentiment = sentiment_analysis(argv[1]);

    switch (sentiment) {
        case SENTIMENT_POSITIVE:
            printf("The text has a positive sentiment.\n");
            break;
        case SENTIMENT_NEGATIVE:
            printf("The text has a negative sentiment.\n");
            break;
        case SENTIMENT_NEUTRAL:
            printf("The text has a neutral sentiment.\n");
            break;
        default:
            printf("Invalid sentiment.\n");
            break;
    }

    return EXIT_SUCCESS;
}