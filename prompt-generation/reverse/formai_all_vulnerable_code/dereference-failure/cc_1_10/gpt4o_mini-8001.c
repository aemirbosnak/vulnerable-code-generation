//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_LOG_SIZE 1024
#define MAX_CLIENTS 5

typedef struct {
    char log[MAX_LOG_SIZE];
} LogEntry;

typedef struct {
    LogEntry entries[MAX_CLIENTS];
    int count;
    pthread_mutex_t lock;
} LogContainer;

LogContainer logContainer;

void *clientThread(void *arg) {
    int clientId = *((int *)arg);
    char logMessage[MAX_LOG_SIZE];

    // Simulate sending logs from clients
    for (int i = 0; i < 3; i++) {
        snprintf(logMessage, sizeof(logMessage), "Client %d: Event %d\n", clientId, i + 1);

        pthread_mutex_lock(&logContainer.lock);
        if (logContainer.count < MAX_CLIENTS) {
            strcpy(logContainer.entries[logContainer.count].log, logMessage);
            logContainer.count++;
            printf("Client %d sent log: %s", clientId, logMessage);
        }
        pthread_mutex_unlock(&logContainer.lock);
        sleep(rand() % 2 + 1); // Simulate variable transmission time
    }

    return NULL;
}

void *logProcessorThread(void *arg) {
    while (1) {
        pthread_mutex_lock(&logContainer.lock);
        
        // Process logs if we have any
        if (logContainer.count > 0) {
            printf("Processing logs...\n");
            for (int i = 0; i < logContainer.count; i++) {
                printf("Log: %s", logContainer.entries[i].log);
            }
            logContainer.count = 0; // Clear after processing
        }
        pthread_mutex_unlock(&logContainer.lock);
        sleep(2); // Process logs every 2 seconds
    }
    return NULL;
}

int main() {
    pthread_t clients[MAX_CLIENTS];
    pthread_t processor;

    // Initialize log container
    logContainer.count = 0;
    pthread_mutex_init(&logContainer.lock, NULL);

    // Create log processor thread
    pthread_create(&processor, NULL, logProcessorThread, NULL);

    // Create client threads
    for (int i = 0; i < MAX_CLIENTS; i++) {
        int *clientId = malloc(sizeof(*clientId));
        *clientId = i + 1; // Client IDs start from 1
        pthread_create(&clients[i], NULL, clientThread, clientId);
    }

    // Wait for client threads to finish
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(clients[i], NULL);
    }

    // Wait for the processor thread to finish
    // (Here we simply terminate this thread for the example's sake)
    pthread_cancel(processor);
    pthread_join(processor, NULL);

    // Cleanup
    pthread_mutex_destroy(&logContainer.lock);
    return 0;
}