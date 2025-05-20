//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char description[100];
    int processing_time;  // in seconds
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
    pthread_mutex_t mutex;
} TaskQueue;

void* process_task(void* arg) {
    Task* task = (Task*) arg;
    printf("Starting task %d: %s (will take %d seconds)\n", task->id, task->description, task->processing_time);
    sleep(task->processing_time);  // Simulate task processing time
    printf("Completed task %d: %s\n", task->id, task->description);
    free(task);  // Free allocated memory for task
    return NULL;
}

void add_task(TaskQueue* queue, int id, const char* description, int processing_time) {
    pthread_mutex_lock(&queue->mutex);
    if (queue->count < MAX_TASKS) {
        Task* task = (Task*) malloc(sizeof(Task));
        task->id = id;
        strncpy(task->description, description, sizeof(task->description) - 1);
        task->processing_time = processing_time;
        task->description[sizeof(task->description) - 1] = '\0';  // Ensure null termination

        queue->tasks[queue->count] = *task;
        queue->count++;
        pthread_t thread;
        pthread_create(&thread, NULL, process_task, task);
        pthread_detach(thread);  // Detach the thread to avoid memory leaks
    } else {
        printf("Task queue is full. Cannot add task %d.\n", id);
    }
    pthread_mutex_unlock(&queue->mutex);
}

TaskQueue* create_task_queue() {
    TaskQueue* queue = (TaskQueue*) malloc(sizeof(TaskQueue));
    queue->count = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    return queue;
}

void destroy_task_queue(TaskQueue* queue) {
    for (int i = 0; i < queue->count; i++) {
        // No need to free tasks here since they are processed in threads
    }
    pthread_mutex_destroy(&queue->mutex);
    free(queue);
}

int main() {
    TaskQueue* queue = create_task_queue();
    
    add_task(queue, 1, "Download file", 3);
    add_task(queue, 2, "Process data", 5);
    add_task(queue, 3, "Generate report", 2);
    add_task(queue, 4, "Send email", 4);
    
    // Sleep long enough to let all tasks complete before exiting
    sleep(10);
    
    destroy_task_queue(queue);
    return 0;
}