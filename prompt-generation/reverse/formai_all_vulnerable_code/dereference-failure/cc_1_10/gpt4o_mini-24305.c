//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define LOG_SIZE 256
#define NUM_LOGS 10

typedef struct {
    char** logs;
    int index;
    pthread_mutex_t lock;
} LogBuffer;

void* generate_logs(void* arg) {
    LogBuffer* log_buffer = (LogBuffer*)arg;
    for (int i = 0; i < NUM_LOGS; i++) {
        char* log_entry = (char*)malloc(LOG_SIZE);
        
        // Simulate log generation
        snprintf(log_entry, LOG_SIZE, "Log Entry %d: %s", i, "This is a log message.");
        
        pthread_mutex_lock(&log_buffer->lock);
        log_buffer->logs[log_buffer->index] = log_entry;
        log_buffer->index = (log_buffer->index + 1) % NUM_LOGS;
        pthread_mutex_unlock(&log_buffer->lock);
        
        sleep(rand() % 3); // Random delay between log generations
    }
    return NULL;
}

void* analyze_logs(void* arg) {
    LogBuffer* log_buffer = (LogBuffer*)arg;
    
    for (int i = 0; i < NUM_LOGS; i++) {
        pthread_mutex_lock(&log_buffer->lock);
        
        // Only read and analyze if there's a log available
        if (log_buffer->logs[i] != NULL) {
            printf("Analyzing: %s\n", log_buffer->logs[i]);
            free(log_buffer->logs[i]); // Free the memory after analyzing
            log_buffer->logs[i] = NULL; // Mark as processed
        }

        pthread_mutex_unlock(&log_buffer->lock);

        sleep(1); // Sleep for a bit before next analysis
    }
    return NULL;
}

int main() {
    LogBuffer log_buffer;
    log_buffer.logs = (char**)malloc(NUM_LOGS * sizeof(char*));
    log_buffer.index = 0;
    pthread_mutex_init(&log_buffer.lock, NULL);

    // Initialize log entries to NULL
    for (int i = 0; i < NUM_LOGS; i++) {
        log_buffer.logs[i] = NULL;
    }

    // Create threads for log generation and analysis
    pthread_t log_gen_thread, log_analyze_thread;
    pthread_create(&log_gen_thread, NULL, generate_logs, (void*)&log_buffer);
    pthread_create(&log_analyze_thread, NULL, analyze_logs, (void*)&log_buffer);

    // Wait for threads to finish
    pthread_join(log_gen_thread, NULL);
    pthread_join(log_analyze_thread, NULL);

    // Clean up
    pthread_mutex_destroy(&log_buffer.lock);
    free(log_buffer.logs);

    return 0;
}