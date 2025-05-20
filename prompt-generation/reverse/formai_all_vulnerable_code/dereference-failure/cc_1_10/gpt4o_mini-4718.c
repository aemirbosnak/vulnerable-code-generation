//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[50];
    int interval; // Interval in seconds
    time_t next_run_time;
    struct Task* next;
} Task;

typedef struct Scheduler {
    Task* head;
    pthread_mutex_t lock;
} Scheduler;

Scheduler* create_scheduler() {
    Scheduler* scheduler = malloc(sizeof(Scheduler));
    scheduler->head = NULL;
    pthread_mutex_init(&scheduler->lock, NULL);
    return scheduler;
}

void add_task(Scheduler* scheduler, const char* name, int interval) {
    pthread_mutex_lock(&scheduler->lock);
    Task* new_task = malloc(sizeof(Task));
    strncpy(new_task->name, name, sizeof(new_task->name) - 1);
    new_task->interval = interval;
    new_task->next_run_time = time(NULL) + interval;
    new_task->next = scheduler->head;
    scheduler->head = new_task;
    pthread_mutex_unlock(&scheduler->lock);
}

void remove_task(Scheduler* scheduler, const char* name) {
    pthread_mutex_lock(&scheduler->lock);
    Task** current = &scheduler->head;
    while (*current) {
        if (strcmp((*current)->name, name) == 0) {
            Task* to_remove = *current;
            *current = to_remove->next;
            free(to_remove);
            break;
        }
        current = &(*current)->next;
    }
    pthread_mutex_unlock(&scheduler->lock);
}

void run_task(Task* task) {
    printf("Running task: %s\n", task->name);
    // Simulate task execution time
    sleep(1);
}

void* scheduler_thread(void* arg) {
    Scheduler* scheduler = (Scheduler*) arg;
    while (1) {
        pthread_mutex_lock(&scheduler->lock);
        Task* current = scheduler->head;
        time_t current_time = time(NULL);
        while (current) {
            if (current_time >= current->next_run_time) {
                run_task(current);
                current->next_run_time = current_time + current->interval;
            }
            current = current->next;
        }
        pthread_mutex_unlock(&scheduler->lock);
        sleep(1);
    }
    return NULL;
}

void destroy_scheduler(Scheduler* scheduler) {
    pthread_mutex_lock(&scheduler->lock);
    Task* current = scheduler->head;
    while (current) {
        Task* to_remove = current;
        current = current->next;
        free(to_remove);
    }
    pthread_mutex_unlock(&scheduler->lock);
    pthread_mutex_destroy(&scheduler->lock);
    free(scheduler);
}

int main() {
    Scheduler* scheduler = create_scheduler();
    pthread_t thread_id;

    add_task(scheduler, "Task1", 2);
    add_task(scheduler, "Task2", 5);
    add_task(scheduler, "Task3", 3);

    // Start the scheduler in a separate thread
    pthread_create(&thread_id, NULL, scheduler_thread, scheduler);

    // Main program loop for demonstration; add tasks dynamically
    char command[100];
    while (1) {
        printf("Enter command (add <name> <interval>, remove <name>, exit): ");
        fgets(command, sizeof(command), stdin);
        char action[10];
        char name[50];
        int interval;

        if (sscanf(command, "%s %s %d", action, name, &interval) == 3 && strcmp(action, "add") == 0) {
            add_task(scheduler, name, interval);
        } else if (sscanf(command, "%s %s", action, name) == 2 && strcmp(action, "remove") == 0) {
            remove_task(scheduler, name);
        } else if (strcmp(command, "exit\n") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    // Cleanup
    destroy_scheduler(scheduler);
    pthread_cancel(thread_id);
    return 0;
}