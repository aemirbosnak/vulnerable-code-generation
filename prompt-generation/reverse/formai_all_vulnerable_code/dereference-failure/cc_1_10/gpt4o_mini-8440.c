//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define POSITIVE_WORDS 5
#define NEGATIVE_WORDS 5

// Function to normalize the text input by converting to lowercase
void normalize(char *text) {
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }
}

// Function to count the sentiment score
int analyze_sentiment(char **words, int word_count, char **positive, int pos_count, char **negative, int neg_count) {
    int score = 0;

    for (int i = 0; i < word_count; i++) {
        for (int j = 0; j < pos_count; j++) {
            if (strcmp(words[i], positive[j]) == 0) {
                score++;
                break;
            }
        }

        for (int j = 0; j < neg_count; j++) {
            if (strcmp(words[i], negative[j]) == 0) {
                score--;
                break;
            }
        }
    }

    return score;
}

// Main function to execute the sentiment analysis
int main() {
    char *positive_words[POSITIVE_WORDS] = {"happy", "good", "great", "fantastic", "excellent"};
    char *negative_words[NEGATIVE_WORDS] = {"sad", "bad", "terrible", "awful", "horrible"};

    char input_text[MAX_WORDS * MAX_WORD_LENGTH];
    char *words[MAX_WORDS];
    int word_count = 0;

    printf("Enter your text for sentiment analysis:\n");
    fgets(input_text, sizeof(input_text), stdin);

    // Normalize the text to lower case
    normalize(input_text);

    // Tokenize the input text into words
    char *token = strtok(input_text, " \n");
    while (token != NULL && word_count < MAX_WORDS) {
        words[word_count] = strdup(token); // Allocate memory for the word
        word_count++;
        token = strtok(NULL, " \n");
    }

    // Analyze sentiment
    int sentiment_score = analyze_sentiment(words, word_count, positive_words, POSITIVE_WORDS, negative_words, NEGATIVE_WORDS);

    // Output the results
    if (sentiment_score > 0) {
        printf("The sentiment of the text is Positive with a score of: %d\n", sentiment_score);
    } else if (sentiment_score < 0) {
        printf("The sentiment of the text is Negative with a score of: %d\n", sentiment_score);
    } else {
        printf("The sentiment of the text is Neutral with a score of: %d\n");
    }

    // Free allocated memory for words
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}