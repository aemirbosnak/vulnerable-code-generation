//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 1024

int main() {
    setlocale(LC_ALL, "");

    char text[MAX_WORDS];
    printf("Enter a text: ");
    fgets(text, MAX_WORDS, stdin);

    char words[MAX_WORDS][MAX_WORDS];
    int num_words = tokenize(text, words);

    int sentiment_score = calculate_sentiment(words);

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}

int tokenize(char *text, char **words) {
    char *p = text;
    int i = 0;
    words[0] = NULL;

    while (p) {
        char *word = malloc(MAX_WORDS);
        word = strpbrk(p, " \t\n");
        if (word) {
            *words++ = word;
            p = word + 1;
        } else {
            words[i] = NULL;
            break;
        }
        i++;
    }

    return i;
}

int calculate_sentiment(char **words) {
    int sentiment_score = 0;
    for (int i = 0; words[i] != NULL; i++) {
        if (is_positive(words[i])) {
            sentiment_score++;
        } else if (is_negative(words[i])) {
            sentiment_score--;
        }
    }

    return sentiment_score;
}

int is_positive(char *word) {
    char *positive_words[] = {"happy", "joy", "good", "excellent", "wonderful"};
    for (int i = 0; positive_words[i] != NULL; i++) {
        if (strcmp(word, positive_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int is_negative(char *word) {
    char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful"};
    for (int i = 0; negative_words[i] != NULL; i++) {
        if (strcmp(word, negative_words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}