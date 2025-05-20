//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int sentiment;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

int calculate_sentiment(char *word) {
    int sentiment = 0;
    int i;

    for (i = 0; i < strlen(word); i++) {
        sentiment += (int)toupper((unsigned char)word[i]);
        if (i > 0 && (word[i] == '-' || word[i] == '--')) {
            sentiment -= 2;
        }
        if (i > 0 && (word[i-1] == '.' || word[i-1] == '!' || word[i-1] == '?')) {
            sentiment += 2;
        }
    }

    return sentiment;
}

void add_word(char *word) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        return;
    }

    strcpy(words[num_words].word, word);
    words[num_words].sentiment = calculate_sentiment(word);
    num_words++;
}

void analyze_sentence(char *sentence) {
    char *word = strtok(sentence, " ,.-:!?");
    int total_sentiment = 0;

    while (word != NULL) {
        int i;

        for (i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                total_sentiment += words[i].sentiment;
                break;
            }
        }

        if (i == num_words) {
            add_word(word);
            total_sentiment += calculate_sentiment(word);
        }

        word = strtok(NULL, " ,.-:!?");
    }

    printf("Sentiment score: %d\n", total_sentiment);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    analyze_sentence(argv[1]);

    return 0;
}