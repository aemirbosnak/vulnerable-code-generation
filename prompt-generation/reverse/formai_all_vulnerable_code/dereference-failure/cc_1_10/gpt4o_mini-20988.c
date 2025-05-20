//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MESSAGE_LENGTH 256
#define NUM_NODES 4

// Structure to hold message information
typedef struct {
    char text[MESSAGE_LENGTH];
    bool is_spam;
} Message;

// Shared message buffer
Message message_buffer[MAX_MESSAGES];
int message_count = 0;

// Mutex for synchronizing access to the message buffer
pthread_mutex_t mutex;

// Function to determine if a message is spam
bool detect_spam(const char *text) {
    // Simple spam heuristics: check for common spam words
    const char *spam_words[] = { "free", "win", "winner", "money", "click here", "offer" };
    for (int i = 0; i < 6; i++) {
        if (strstr(text, spam_words[i]) != NULL) {
            return true; // It's spam
        }
    }
    return false; // Not spam
}

// Function to simulate a node that checks for spam
void *node_function(void *arg) {
    int node_id = *(int *)arg;
    free(arg); // Free the dynamically allocated integer

    while (true) {
        pthread_mutex_lock(&mutex);
        if (message_count > 0) {
            Message msg = message_buffer[--message_count];
            pthread_mutex_unlock(&mutex);
            msg.is_spam = detect_spam(msg.text);
            
            printf("Node %d processed message: \"%s\" - %s\n", node_id, msg.text, 
                   msg.is_spam ? "SPAM" : "NOT SPAM");
        } else {
            pthread_mutex_unlock(&mutex);
            sleep(1); // Wait before checking again if no messages
        }
    }
    return NULL;
}

// Function to send messages to the buffer
void send_message(const char *text) {
    pthread_mutex_lock(&mutex);
    if (message_count < MAX_MESSAGES) {
        strcpy(message_buffer[message_count].text, text);
        message_buffer[message_count].is_spam = false; // Initial assumption
        message_count++;
        printf("Message sent: \"%s\"\n", text);
    } else {
        printf("Message buffer full. Unable to send: \"%s\"\n", text);
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t nodes[NUM_NODES];
    pthread_mutex_init(&mutex, NULL);

    // Create nodes
    for (int i = 0; i < NUM_NODES; i++) {
        int *node_id = malloc(sizeof(int)); // Allocate memory for node_id
        *node_id = i + 1; // Node IDs start from 1
        if (pthread_create(&nodes[i], NULL, node_function, node_id) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Simulate sending messages
    send_message("Congratulations! You've won a free iPhone.");
    send_message("Hello, how are you today?");
    send_message("Look at this offer to make money fast!");
    send_message("Are we still on for the meeting?");
    send_message("Click here to claim your free gift.");

    // Sleep for a while to allow nodes to process messages
    sleep(10);

    // Cleanup and exit threads (not actually terminating them for infinite running)
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_cancel(nodes[i]);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}