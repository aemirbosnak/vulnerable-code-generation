//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define TEXT_CHUNK_SIZE 256
#define NUM_WORKERS 4

// Sentiment score
int sentiment_score;

// Mutex for thread synchronization
pthread_mutex_t lock;

// Sample sentiment data
char *positive_words[] = {"happy", "joy", "love", "great", "excellent", NULL};
char *negative_words[] = {"sad", "bad", "hate", "terrible", "awful", NULL};

// Function to calculate sentiment score
int calculate_sentiment(char *text_chunk) {
    int score = 0;
    char *token = strtok(text_chunk, " ");
    
    while (token != NULL) {
        for (int i = 0; positive_words[i] != NULL; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score++;
            }
        }
        for (int j = 0; negative_words[j] != NULL; j++) {
            if (strcmp(token, negative_words[j]) == 0) {
                score--;
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

// Worker thread function
void *worker_thread(void *arg) {
    char *text_chunk = (char *)arg;
    int local_score = calculate_sentiment(text_chunk);
    
    // Lock to update the global sentiment score
    pthread_mutex_lock(&lock);
    sentiment_score += local_score;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

// Main function
int main() {
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);
    
    // Sample text chunks to analyze
    char *text_chunks[NUM_WORKERS] = {
        "I am happy and joy",
        "This is bad and awful",
        "Great love is a wonderful feeling",
        "Life can be terrible and sad"
    };
    
    pthread_t workers[NUM_WORKERS];
    sentiment_score = 0;
    
    // Create worker threads
    for (int i = 0; i < NUM_WORKERS; i++) {
        if (pthread_create(&workers[i], NULL, worker_thread, (void *)text_chunks[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for worker threads to finish
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }
    
    // Output the result
    printf("Total Sentiment Score: %d\n", sentiment_score);
    
    // Cleanup
    pthread_mutex_destroy(&lock);
    
    return 0;
}