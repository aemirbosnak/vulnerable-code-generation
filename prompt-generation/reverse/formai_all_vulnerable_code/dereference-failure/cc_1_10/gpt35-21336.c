//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LOGS 10000
#define MAX_LINE_SIZE 1024

struct log_entry {
    char* timestamp;
    char* message;
};

struct log_entry logs[MAX_LOGS];
int num_logs = 0;
pthread_mutex_t logs_mutex = PTHREAD_MUTEX_INITIALIZER;

void* process_logs(void* thread_id) {
    int id = *(int*)thread_id;
    printf("Thread %d started processing logs...\n", id);

    // Simulate some processing time
    usleep(100000);

    // Read and process logs
    int start = id * (num_logs / MAX_THREADS);
    int end = (id + 1) * (num_logs / MAX_THREADS);
    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&logs_mutex);
        printf("Thread %d processing log %d...\n", id, i);
        // Process log
        // For this example, we will just print the log message
        printf("%s: %s\n", logs[i].timestamp, logs[i].message);
        pthread_mutex_unlock(&logs_mutex);
    }

    printf("Thread %d finished processing logs.\n", id);
    pthread_exit(NULL);
}

int main() {
    FILE* fp = fopen("logs.txt", "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read logs
    char line[MAX_LINE_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        char* timestamp = strtok(line, ":");
        char* message = strtok(NULL, ":");
        message[strcspn(message, "\r\n")] = 0; // Remove newline character

        logs[num_logs].timestamp = strdup(timestamp);
        logs[num_logs].message = strdup(message);
        num_logs++;
    }

    // Spawn threads to process logs
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, process_logs, &thread_ids[i])) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}