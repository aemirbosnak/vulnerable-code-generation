//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SENTENCES 100
#define MAX_LENGTH 256

// Sentiment categories
typedef enum {
    POSITIVE,
    NEGATIVE,
    NEUTRAL
} Sentiment;

// Function to determine sentiment
Sentiment analyze_sentiment(const char* sentence) {
    // Simple words for sentiment analysis
    const char* positive_words[] = {"good", "happy", "joy", "love", "excellent", NULL};
    const char* negative_words[] = {"bad", "sad", "hate", "terrible", "poor", NULL};

    int score = 0;

    // Check for positive words
    for (int i = 0; positive_words[i] != NULL; i++) {
        if (strstr(sentence, positive_words[i]) != NULL) {
            score++;
        }
    }

    // Check for negative words
    for (int i = 0; negative_words[i] != NULL; i++) {
        if (strstr(sentence, negative_words[i]) != NULL) {
            score--;
        }
    }

    if (score > 0) {
        return POSITIVE;
    } else if (score < 0) {
        return NEGATIVE;
    } else {
        return NEUTRAL;
    }
}

// Thread function to analyze sentiment
void* analyze(void* arg) {
    char* sentence = (char*)arg;
    Sentiment sentiment = analyze_sentiment(sentence);

    switch (sentiment) {
        case POSITIVE:
            printf("Sentiment Analysis: Positive - \"%s\"\n", sentence);
            break;
        case NEGATIVE:
            printf("Sentiment Analysis: Negative - \"%s\"\n", sentence);
            break;
        case NEUTRAL:
            printf("Sentiment Analysis: Neutral - \"%s\"\n", sentence);
            break;
    }

    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_SENTENCES];
    char input[MAX_LENGTH];
    int count = 0;

    printf("Sentiment Analysis Tool\n");
    printf("Enter sentences (type 'exit' to stop):\n");

    while (1) {
        // Read input from user
        fgets(input, sizeof(input), stdin);

        // Remove the newline character
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Create a new thread for each sentence
        char* sentence_copy = malloc(strlen(input) + 1);
        if (sentence_copy == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(1);
        }
        strcpy(sentence_copy, input);

        if (pthread_create(&threads[count], NULL, analyze, (void*)sentence_copy) != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(sentence_copy);
            exit(1);
        }

        count++;
        if (count >= MAX_SENTENCES) {
            printf("Reached maximum number of sentences. Please wait for analysis.\n");
            for (int i = 0; i < count; i++) {
                pthread_join(threads[i], NULL);
            }
            count = 0; // Reset count after processing
        }
    }

    // Join any remaining threads
    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sentiment Analysis Tool exited.\n");
    return 0;
}