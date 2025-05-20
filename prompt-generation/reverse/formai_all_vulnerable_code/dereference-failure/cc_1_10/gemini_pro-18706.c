//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SENTIMENT_POSITIVE,
    SENTIMENT_NEUTRAL,
    SENTIMENT_NEGATIVE
} sentiment_t;

typedef struct {
    char *word;
    sentiment_t sentiment;
} word_t;

word_t *words = NULL;
size_t num_words = 0;

void load_lexicon() {
    FILE *fp = fopen("lexicon.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening lexicon file\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *word = strtok(line, "\t");
        char *sentiment = strtok(NULL, "\n");

        if (word != NULL && sentiment != NULL) {
            word_t *new_word = malloc(sizeof(word_t));
            new_word->word = strdup(word);
            if (strcmp(sentiment, "positive") == 0) {
                new_word->sentiment = SENTIMENT_POSITIVE;
            } else if (strcmp(sentiment, "neutral") == 0) {
                new_word->sentiment = SENTIMENT_NEUTRAL;
            } else if (strcmp(sentiment, "negative") == 0) {
                new_word->sentiment = SENTIMENT_NEGATIVE;
            }

            words = realloc(words, (num_words + 1) * sizeof(word_t));
            words[num_words++] = *new_word;
        }
    }

    fclose(fp);
}

sentiment_t analyze_sentiment(char *text) {
    sentiment_t sentiment = SENTIMENT_NEUTRAL;

    char *token = strtok(text, " ");
    while (token != NULL) {
        for (size_t i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                sentiment = words[i].sentiment;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    return sentiment;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        exit(1);
    }

    load_lexicon();

    sentiment_t sentiment = analyze_sentiment(argv[1]);

    switch (sentiment) {
        case SENTIMENT_POSITIVE:
            printf("The text has a positive sentiment\n");
            break;
        case SENTIMENT_NEUTRAL:
            printf("The text has a neutral sentiment\n");
            break;
        case SENTIMENT_NEGATIVE:
            printf("The text has a negative sentiment\n");
            break;
    }

    return 0;
}