//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SENTIMENT_POSITIVE 1
#define SENTIMENT_NEGATIVE -1
#define SENTIMENT_NEUTRAL 0

struct sentiment_lexicon {
    char **words;
    int *sentiments;
    int size;
};

struct sentiment_analyzer {
    struct sentiment_lexicon *lexicon;
};

struct sentiment_lexicon *sentiment_lexicon_new(const char *filename) {
    struct sentiment_lexicon *lexicon = malloc(sizeof(struct sentiment_lexicon));
    lexicon->words = NULL;
    lexicon->sentiments = NULL;
    lexicon->size = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening sentiment lexicon file: %s\n", filename);
        return NULL;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, "\t");
        char *sentiment = strtok(NULL, "\t");
        if (word != NULL && sentiment != NULL) {
            lexicon->words = realloc(lexicon->words, (lexicon->size + 1) * sizeof(char *));
            lexicon->words[lexicon->size] = strdup(word);
            lexicon->sentiments = realloc(lexicon->sentiments, (lexicon->size + 1) * sizeof(int));
            lexicon->sentiments[lexicon->size] = atoi(sentiment);
            lexicon->size++;
        }
    }

    fclose(file);

    return lexicon;
}

void sentiment_lexicon_free(struct sentiment_lexicon *lexicon) {
    for (int i = 0; i < lexicon->size; i++) {
        free(lexicon->words[i]);
    }
    free(lexicon->words);
    free(lexicon->sentiments);
    free(lexicon);
}

struct sentiment_analyzer *sentiment_analyzer_new(const char *filename) {
    struct sentiment_analyzer *analyzer = malloc(sizeof(struct sentiment_analyzer));
    analyzer->lexicon = sentiment_lexicon_new(filename);
    return analyzer;
}

void sentiment_analyzer_free(struct sentiment_analyzer *analyzer) {
    sentiment_lexicon_free(analyzer->lexicon);
    free(analyzer);
}

int sentiment_analyzer_analyze(struct sentiment_analyzer *analyzer, const char *text) {
    int sentiment = SENTIMENT_NEUTRAL;
    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < analyzer->lexicon->size; i++) {
            if (strcmp(token, analyzer->lexicon->words[i]) == 0) {
                sentiment += analyzer->lexicon->sentiments[i];
            }
        }
        token = strtok(NULL, " ");
    }
    return sentiment;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sentiment-lexicon-file> <text-to-analyze>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sentiment_analyzer *analyzer = sentiment_analyzer_new(argv[1]);
    int sentiment = sentiment_analyzer_analyze(analyzer, argv[2]);
    sentiment_analyzer_free(analyzer);

    if (sentiment > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return EXIT_SUCCESS;
}