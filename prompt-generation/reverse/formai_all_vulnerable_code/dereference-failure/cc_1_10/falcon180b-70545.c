//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int length;
} Word;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <movie_review>\n", argv[0]);
        return 1;
    }

    char *review = argv[1];
    int num_words = 0;
    Word words[MAX_WORDS];

    char *current_word = strtok(review, ",.!?;:");
    while (current_word!= NULL) {
        if (num_words == MAX_WORDS) {
            printf("Error: Too many words in review.\n");
            return 1;
        }

        int length = strlen(current_word);
        if (length > MAX_WORD_LENGTH) {
            printf("Error: Word '%s' is too long.\n", current_word);
            return 1;
        }

        words[num_words] = (Word) {
           .word = strdup(current_word),
           .length = length
        };
        num_words++;

        current_word = strtok(NULL, ",.!?;:");
    }

    double sentiment_score = 0.0;
    for (int i = 0; i < num_words; i++) {
        const char *word = words[i].word;
        int length = words[i].length;

        if (isalpha(word[0])) {
            sentiment_score += (double)length / (double)num_words;
        } else {
            sentiment_score -= (double)length / (double)num_words;
        }
    }

    printf("Sentiment score: %.2f\n", sentiment_score);

    return 0;
}