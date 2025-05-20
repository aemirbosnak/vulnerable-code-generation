//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 1;
    newWord->next = NULL;

    if (head == NULL) {
        head = newWord;
    } else {
        Word *currentWord = head;
        while (currentWord->next) {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }

    return head;
}

int main() {
    char text[] = "This is a sample text that will be analyzed. It contains some words, like happy, sad, and angry. The text also includes some punctuation marks, such as commas and periods.";

    Word *head = insertWord(NULL, text);

    // Calculate the sentiment of the text
    int sentiment = calculateSentiment(head);

    // Print the sentiment
    printf("The sentiment of the text is: %d", sentiment);

    return 0;
}

int calculateSentiment(Word *head) {
    int sentiment = 0;
    Word *currentWord = head;

    while (currentWord) {
        // Check if the word is a sentiment word
        if (isSentimentWord(currentWord->word)) {
            // Add the word's sentiment value to the total sentiment
            sentiment += getSentimentValue(currentWord->word);
        }
        currentWord = currentWord->next;
    }

    return sentiment;
}

int isSentimentWord(char *word) {
    // List of sentiment words
    char *sentimentWords[] = {"happy", "sad", "angry", "joy", "fear", "love"};

    for (int i = 0; i < 6; i++) {
        if (strcmp(word, sentimentWords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

int getSentimentValue(char *word) {
    // Sentiment values for each word
    int sentimentValues[] = {2, -1, -3, 4, -2, 5};

    for (int i = 0; i < 6; i++) {
        if (strcmp(word, sentimentValues[i]) == 0) {
            return sentimentValues[i];
        }
    }

    return 0;
}