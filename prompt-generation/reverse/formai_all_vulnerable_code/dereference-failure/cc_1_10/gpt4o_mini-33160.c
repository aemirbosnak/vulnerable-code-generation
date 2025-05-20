//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define POSITIVE_WORDS 6
#define NEGATIVE_WORDS 6

const char *positive_words[POSITIVE_WORDS] = {
    "love", "joy", "happy", "beauty", "peace", "delight"
};

const char *negative_words[NEGATIVE_WORDS] = {
    "hate", "death", "sad", "sorrow", "evil", "pain"
};

void analyze_sentiment(const char *text) {
    int positive_count = 0;
    int negative_count = 0;

    // Convert the text to lowercase for comparison
    char *lowercase_text = strdup(text);
    for (int i = 0; lowercase_text[i]; i++) {
        lowercase_text[i] = tolower(lowercase_text[i]);
    }

    // Analyzing word sentiment
    char *token = strtok(lowercase_text, " ,.\n");
    while (token != NULL) {
        for (int i = 0; i < POSITIVE_WORDS; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                positive_count++;
            }
        }
        for (int i = 0; i < NEGATIVE_WORDS; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                negative_count++;
            }
        }
        token = strtok(NULL, " ,.\n");
    }

    // Determining overall sentiment
    if (positive_count > negative_count) {
        printf("The sentiment of the text is: Positive\n");
    } else if (negative_count > positive_count) {
        printf("The sentiment of the text is: Negative\n");
    } else {
        printf("The sentiment of the text is: Neutral\n");
    }

    // Free allocated memory
    free(lowercase_text);
}

int main() {
    char input[MAX_INPUT];

    printf("Enter a monologue or a quote in the style of 'Romeo and Juliet':\n");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        analyze_sentiment(input);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}