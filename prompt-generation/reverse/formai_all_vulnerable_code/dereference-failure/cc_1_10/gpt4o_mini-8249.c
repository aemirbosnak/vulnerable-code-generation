//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct {
    char name[50];
    char description[100];
    int priority; // Higher number means higher priority
    time_t scheduled_time;
} Task;

typedef struct {
    Task *tasks[MAX_TASKS];
    int count;
} Scheduler;

Scheduler *create_scheduler() {
    Scheduler *scheduler = (Scheduler *)malloc(sizeof(Scheduler));
    if (!scheduler) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    scheduler->count = 0;
    return scheduler;
}

void add_task(Scheduler *scheduler, const char *name, const char *description, int priority, time_t scheduled_time) {
    if (scheduler->count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }
    
    Task *new_task = (Task *)malloc(sizeof(Task));
    if (!new_task) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(new_task->name, name);
    strcpy(new_task->description, description);
    new_task->priority = priority;
    new_task->scheduled_time = scheduled_time;

    scheduler->tasks[scheduler->count++] = new_task;
    printf("Task '%s' added successfully.\n", name);
}

void view_tasks(Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < scheduler->count; i++) {
        Task *task = scheduler->tasks[i];
        printf("Task %d: %s\n", i + 1, task->name);
        printf("Description: %s\n", task->description);
        printf("Priority: %d\n", task->priority);
        printf("Scheduled Time: %s", ctime(&(task->scheduled_time)));
        printf("-----------------------\n");
    }
}

int compare_tasks(const void *a, const void *b) {
    Task *taskA = *(Task **)a;
    Task *taskB = *(Task **)b;

    return taskB->priority - taskA->priority; // Sorting based on priority (highest first)
}

void execute_tasks(Scheduler *scheduler) {
    if (scheduler->count == 0) {
        printf("No tasks available to execute.\n");
        return;
    }

    // Sort tasks by priority
    qsort(scheduler->tasks, scheduler->count, sizeof(Task *), compare_tasks);

    printf("\nExecuting Scheduled Tasks:\n");
    for (int i = 0; i < scheduler->count; i++) {
        Task *task = scheduler->tasks[i];
        printf("Executing Task: %s\n", task->name);
        printf("Description: %s\n", task->description);
        printf("Priority: %d\n", task->priority);
        printf("Scheduled Time: %s", ctime(&(task->scheduled_time)));
        printf("-----------------------\n");
        
        free(task); // Free the memory after execution
    }

    scheduler->count = 0; // Reset task count
}

void free_scheduler(Scheduler *scheduler) {
    for (int i = 0; i < scheduler->count; i++) {
        free(scheduler->tasks[i]);
    }
    free(scheduler);
}

int main() {
    Scheduler *scheduler = create_scheduler();
    int choice;

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1: {
                char name[50];
                char description[100];
                int priority;
                time_t scheduled_time = time(NULL);

                printf("Enter Task Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

                printf("Enter Task Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove trailing newline

                printf("Enter Task Priority (1-10): ");
                scanf("%d", &priority);
                getchar(); // to consume the newline character

                add_task(scheduler, name, description, priority, scheduled_time);
                break;
            }
            case 2:
                view_tasks(scheduler);
                break;
            case 3:
                execute_tasks(scheduler);
                break;
            case 4:
                free_scheduler(scheduler);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}