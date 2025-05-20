//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_WORKERS 5
#define MAX_DATA_SIZE 50

// Structure to hold the task data
typedef struct {
    int task_id;
    char data[MAX_DATA_SIZE];
} Task;

// Structure to hold worker context
typedef struct {
    int worker_id;
    Task *task;
} WorkerContext;

// Function to simulate task processing
void* process_task(void* context) {
    WorkerContext *worker_context = (WorkerContext *)context;
    
    printf("Worker %d started processing Task ID: %d\n", 
            worker_context->worker_id, worker_context->task->task_id);
    
    // Simulate some processing time
    sleep(2);
    
    printf("Worker %d finished processing Task ID: %d with data: %s\n", 
            worker_context->worker_id, worker_context->task->task_id, 
            worker_context->task->data);
    
    // Free the allocated task memory
    free(worker_context->task);
    free(worker_context);
    
    return NULL;
}

int main() {
    pthread_t workers[MAX_WORKERS];
    
    for (int i = 0; i < MAX_WORKERS; i++) {
        Task *task = (Task *)malloc(sizeof(Task));
        if (task == NULL) {
            fprintf(stderr, "Memory allocation failed for task\n");
            exit(EXIT_FAILURE);
        }
        
        task->task_id = i + 1;
        snprintf(task->data, MAX_DATA_SIZE, "Processing data for task %d", task->task_id);
        
        WorkerContext *context = (WorkerContext *)malloc(sizeof(WorkerContext));
        if (context == NULL) {
            fprintf(stderr, "Memory allocation failed for worker context\n");
            free(task);
            exit(EXIT_FAILURE);
        }

        context->worker_id = i + 1;
        context->task = task;
        
        // Create worker threads
        if (pthread_create(&workers[i], NULL, process_task, (void *)context) != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(task);
            free(context);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for all workers to finish
    for (int i = 0; i < MAX_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }
    
    printf("All tasks have been processed successfully.\n");
    return 0;
}