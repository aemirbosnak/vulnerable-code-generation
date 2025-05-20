//FormAI DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

// Constants
#define MAX_MESSAGE_LENGTH 100
#define SPAM_THRESHOLD 3

// Struct for messages
typedef struct {
    int id;
    char message[MAX_MESSAGE_LENGTH];
    bool is_spam;
} Message;

// Global variables
Message messages[100];
int num_messages = 0;
int num_spam_messages = 0;
pthread_mutex_t message_lock;

// Function to check if a message is spam
bool is_spam(char* message) {
    int count = 0;
    char* word = strtok(message, " ");
    while (word != NULL) {
        if (strcmp(word, "spam") == 0) {
            count++;
        }
        word = strtok(NULL, " ");
    }
    return count >= SPAM_THRESHOLD;
}

// Function to process messages asynchronously
void* process_message(void* arg) {
    Message* message = (Message*) arg;
    printf("Processing message #%d: %s\n", message->id, message->message);

    pthread_mutex_lock(&message_lock);
    // Check if message is spam
    message->is_spam = is_spam(message->message);
    if (message->is_spam) {
        printf("Detected spam message #%d.\n", message->id);
        num_spam_messages++;
    }
    messages[num_messages] = *message;
    num_messages++;
    pthread_mutex_unlock(&message_lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];

    // Initialize mutex lock
    pthread_mutex_init(&message_lock, NULL);

    // Read messages from input
    for (int i = 0; i < 10; i++) {
        Message* message = (Message*) malloc(sizeof(Message));
        message->id = i + 1;
        printf("Enter message #%d: ", message->id);
        fgets(message->message, MAX_MESSAGE_LENGTH, stdin);
        pthread_create(&threads[i], NULL, process_message, (void*) message);
    }

    // Wait for threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("Total messages: %d\n", num_messages);
    printf("Spam messages: %d\n", num_spam_messages);
    printf("Non-spam messages:\n");
    for (int i = 0; i < num_messages; i++) {
        if (!messages[i].is_spam) {
            printf("#%d: %s\n", messages[i].id, messages[i].message);
        }
    }

    // Destroy mutex lock
    pthread_mutex_destroy(&message_lock);

    return 0;
}