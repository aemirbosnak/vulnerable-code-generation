//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_MESSAGES 100
#define MESSAGE_LENGTH 256
#define KEYWORDS 5

const char *spam_keywords[KEYWORDS] = {
    "buy", 
    "free", 
    "urgent", 
    "limited", 
    "offer"
};

char *messages[MAX_MESSAGES];
int message_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *detect_spam(void *arg) {
    char *message = (char *)arg;
    int detected = 0;

    for (int i = 0; i < KEYWORDS; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            detected = 1;
            break;
        }
    }

    pthread_mutex_lock(&mutex);
    if (detected) {
        printf("Spam detected: \"%s\"\n", message);
    } else {
        printf("No spam detected: \"%s\"\n", message);
    }
    pthread_mutex_unlock(&mutex);

    free(message);
    return NULL;
}

void *receive_messages(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (message_count >= MAX_MESSAGES) {
            pthread_mutex_unlock(&mutex);
            usleep(100000); // Sleep for 100 ms
            continue;
        }

        char *message = (char *)malloc(MESSAGE_LENGTH);
        printf("Enter a message (type 'exit' to quit): ");
        fgets(message, MESSAGE_LENGTH, stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline char

        if (strcmp(message, "exit") == 0) {
            free(message);
            break;
        }

        messages[message_count++] = message;
        pthread_mutex_unlock(&mutex);

        pthread_t tid;
        pthread_create(&tid, NULL, detect_spam, (void *)message);
        pthread_detach(tid);
    }
    return NULL;
}

int main() {
    pthread_t receiver_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&receiver_thread, NULL, receive_messages, NULL);

    pthread_join(receiver_thread, NULL);
    pthread_mutex_destroy(&mutex);

    printf("Exiting Spam Detection System...\n");
    return 0;
}