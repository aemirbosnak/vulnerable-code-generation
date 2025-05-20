//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_NOT_FOUND -1

typedef struct {
    int id;
    char description[100];
    int completed;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
    pthread_mutex_t lock;
} TaskManager;

TaskManager *create_task_manager() {
    TaskManager *manager = malloc(sizeof(TaskManager));
    manager->count = 0;
    pthread_mutex_init(&manager->lock, NULL);
    return manager;
}

void destroy_task_manager(TaskManager *manager) {
    pthread_mutex_destroy(&manager->lock);
    free(manager);
}

int add_task(TaskManager *manager, const char *description) {
    pthread_mutex_lock(&manager->lock);
    if (manager->count >= MAX_TASKS) {
        pthread_mutex_unlock(&manager->lock);
        return -1;
    }

    Task new_task = {manager->count, "", 0};
    strncpy(new_task.description, description, sizeof(new_task.description) - 1);
    manager->tasks[manager->count++] = new_task;
    pthread_mutex_unlock(&manager->lock);
    return new_task.id;
}

void *process_task(void *arg) {
    TaskManager *manager = (TaskManager *)arg;
    
    while (1) {
        pthread_mutex_lock(&manager->lock);
        int found = TASK_NOT_FOUND;
        
        for (int i = 0; i < manager->count; ++i) {
            if (!manager->tasks[i].completed) {
                found = i;
                manager->tasks[i].completed = 1; // Mark task as completed
                break;
            }
        }
        
        pthread_mutex_unlock(&manager->lock);
        
        if (found != TASK_NOT_FOUND) {
            printf("Processing Task %d: %s\n", manager->tasks[found].id, manager->tasks[found].description);
            sleep(1); // Simulating task processing time
        } else {
            break; // No more tasks to process
        }
    }
    
    return NULL; 
}

void start_processing_tasks(TaskManager *manager, int thread_count) {
    pthread_t threads[thread_count];
    
    for (int i = 0; i < thread_count; ++i) {
        pthread_create(&threads[i], NULL, process_task, (void *)manager);
    }

    for (int i = 0; i < thread_count; ++i) {
        pthread_join(threads[i], NULL);
    }
}

void show_tasks(TaskManager *manager) {
    pthread_mutex_lock(&manager->lock);
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < manager->count; i++) {
        printf("ID: %d, Description: %s, Completed: %s\n", 
               manager->tasks[i].id, 
               manager->tasks[i].description, 
               manager->tasks[i].completed ? "Yes" : "No");
    }
    pthread_mutex_unlock(&manager->lock);
}

int main() {
    TaskManager *manager = create_task_manager();
    
    add_task(manager, "Task 1: Write report");
    add_task(manager, "Task 2: Attend meeting");
    add_task(manager, "Task 3: Send email updates");
    add_task(manager, "Task 4: Code review");
    add_task(manager, "Task 5: Update documentation");
    
    show_tasks(manager);
    
    start_processing_tasks(manager, 3); // Start processing with 3 threads
    
    printf("\nAll tasks have been processed!\n");
    show_tasks(manager);
    
    destroy_task_manager(manager);
    return 0;
}