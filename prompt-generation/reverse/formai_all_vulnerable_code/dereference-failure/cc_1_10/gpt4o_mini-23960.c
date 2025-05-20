//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4
#define SPAM_KEYWORDS 5

const char *spam_keywords[SPAM_KEYWORDS] = {"buy now", "free", "click here", "limited time", "winner"};

typedef struct {
    char *message;
    int thread_id;
} ThreadData;

void *detect_spam(void *data) {
    ThreadData *thread_data = (ThreadData *)data;
    char *msg = thread_data->message;
    int spam_count = 0;

    // Check for spam keywords
    for (int i = 0; i < SPAM_KEYWORDS; i++) {
        if (strstr(msg, spam_keywords[i]) != NULL) {
            spam_count++;
            printf("[Thread %d] Detected spam keyword: %s\n", thread_data->thread_id, spam_keywords[i]);
        }
    }

    if (spam_count > 0) {
        printf("[Thread %d] Message considered as spam (found %d keywords): %s\n", thread_data->thread_id, spam_count, msg);
    } else {
        printf("[Thread %d] Message is clean: %s\n", thread_data->thread_id, msg);
    }

    free(thread_data);
    return NULL;
}

void handle_incoming_messages(char *messages[], int msg_count) {
    pthread_t threads[NUM_THREADS];
    int thread_index = 0;

    for (int i = 0; i < msg_count; i++) {
        ThreadData *thread_data = (ThreadData *)malloc(sizeof(ThreadData));
        thread_data->message = messages[i];
        thread_data->thread_id = thread_index;

        if (pthread_create(&threads[thread_index], NULL, detect_spam, (void *)thread_data) != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(thread_data);
            continue;
        }

        thread_index++;
        if (thread_index >= NUM_THREADS) {
            for (int j = 0; j < NUM_THREADS; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_index = 0; // Reset thread index
        }
    }

    // Join remaining threads
    for (int j = 0; j < thread_index; j++) {
        pthread_join(threads[j], NULL);
    }
}

int main() {
    char *messages[] = {
        "Congratulations! You are a winner of a free gift!",
        "This is a normal message with no spam.",
        "Buy now and get 50% off!",
        "See our latest updates.",
        "Click here to claim your prize!",
        "Let's have a meeting next week.",
        "Limited time offer, act fast!",
        "Join us for a fun event.",
        "Check out our latest products!"
    };

    int msg_count = sizeof(messages) / sizeof(messages[0]);
    handle_incoming_messages(messages, msg_count);

    return 0;
}