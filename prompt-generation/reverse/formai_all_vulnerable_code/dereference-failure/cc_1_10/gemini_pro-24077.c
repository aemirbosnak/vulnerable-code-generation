//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SENTIMENT_POSITIVE,
    SENTIMENT_NEGATIVE,
    SENTIMENT_NEUTRAL
} sentiment_t;

typedef struct {
    char* word;
    sentiment_t sentiment;
} lexicon_entry_t;

// A simple lexicon of positive and negative words
static lexicon_entry_t lexicon[] = {
    { "good", SENTIMENT_POSITIVE },
    { "bad", SENTIMENT_NEGATIVE },
    { "happy", SENTIMENT_POSITIVE },
    { "sad", SENTIMENT_NEGATIVE },
    { "love", SENTIMENT_POSITIVE },
    { "hate", SENTIMENT_NEGATIVE },
    { NULL, SENTIMENT_NEUTRAL }
};

// Analyze the sentiment of a given string
sentiment_t analyze_sentiment(char* text) {
    // Initialize the sentiment to neutral
    sentiment_t sentiment = SENTIMENT_NEUTRAL;

    // Tokenize the text into individual words
    char* token = strtok(text, " ");

    // Iterate over each word and update the sentiment accordingly
    while (token != NULL) {
        // Lookup the word in the lexicon
        for (int i = 0; i < sizeof(lexicon) / sizeof(lexicon[0]); i++) {
            lexicon_entry_t entry = lexicon[i];

            if (strcmp(token, entry.word) == 0) {
                // Update the sentiment
                if (entry.sentiment == SENTIMENT_POSITIVE) {
                    sentiment = SENTIMENT_POSITIVE;
                } else if (entry.sentiment == SENTIMENT_NEGATIVE) {
                    sentiment = SENTIMENT_NEGATIVE;
                }

                break;
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return sentiment;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the sentiment of the input text
    sentiment_t sentiment = analyze_sentiment(argv[1]);

    // Print the sentiment
    switch (sentiment) {
        case SENTIMENT_POSITIVE:
            printf("The sentiment is positive.\n");
            break;
        case SENTIMENT_NEGATIVE:
            printf("The sentiment is negative.\n");
            break;
        case SENTIMENT_NEUTRAL:
            printf("The sentiment is neutral.\n");
            break;
    }

    return EXIT_SUCCESS;
}