//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_LEN 100

typedef struct {
    char *word;
    int count;
    float sentiment;
} Word;


// Initialize the sentiment analysis tool.
void init(Word *words, int *num_words) {
    *num_words = 0;
}

// Add a word to the sentiment analysis tool.
void add_word(Word *words, int *num_words, char *word, float sentiment) {
    if (*num_words >= MAX_WORDS) {
        return;
    }

    words[*num_words].word = strdup(word);
    words[*num_words].count = 1;
    words[*num_words].sentiment = sentiment;
    (*num_words)++;
}

// Get the sentiment of a text.
float get_sentiment(Word *words, int num_words, char *text) {
    float sentiment = 0.0;
    int num_matches = 0;

    char *token = strtok(text, " ");
    while (token != NULL) {
        for (int i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                sentiment += words[i].sentiment;
                num_matches++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    if (num_matches == 0) {
        return 0.0;
    }

    return sentiment / num_matches;
}

// Free the resources used by the sentiment analysis tool.
void cleanup(Word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
}


int main() {
    Word words[MAX_WORDS];
    int num_words;

    init(words, &num_words);

    add_word(words, &num_words, "love", 1.0);
    add_word(words, &num_words, "hate", -1.0);
    add_word(words, &num_words, "happy", 1.0);
    add_word(words, &num_words, "sad", -1.0);

    char *text = "I love this movie!";
    float sentiment = get_sentiment(words, num_words, text);

    printf("The sentiment of the text is: %f\n", sentiment);

    cleanup(words, num_words);

    return 0;
}