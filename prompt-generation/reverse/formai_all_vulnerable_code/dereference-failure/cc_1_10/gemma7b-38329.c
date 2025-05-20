//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 256

char *preprocess_text(char *text) {
    char *processed_text = malloc(MAX_LEN);
    int i = 0, j = 0;

    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            processed_text[j] = text[i];
            j++;
        } else if (isspace(text[i])) {
            processed_text[j] = ' ';
            j++;
        }
        i++;
    }

    processed_text[j] = '\0';

    return processed_text;
}

int sentiment_analysis(char *processed_text) {
    int sentiment = 0;
    char *words = malloc(MAX_LEN);
    char *word = NULL;

    word = strtok(processed_text, " ");

    while (word) {
        if (strcmp(word, "good") == 0) {
            sentiment++;
        } else if (strcmp(word, "bad") == 0) {
            sentiment--;
        }
        word = strtok(NULL, " ");
    }

    free(words);

    return sentiment;
}

int main() {
    char *text = "I am happy and you are too!";
    char *processed_text = NULL;
    int sentiment = 0;

    processed_text = preprocess_text(text);
    sentiment = sentiment_analysis(processed_text);

    printf("The sentiment of the text is: %d\n", sentiment);

    free(processed_text);

    return 0;
}