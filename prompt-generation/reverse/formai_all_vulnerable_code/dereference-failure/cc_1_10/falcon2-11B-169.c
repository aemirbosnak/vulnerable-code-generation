//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a task
typedef struct task_s {
    char* name;
    void (*callback)(void);
    unsigned int frequency;
    struct task_s* next;
} task_t;

// Structure to represent the task scheduler
typedef struct scheduler_s {
    task_t* head;
} scheduler_t;

// Function to add a new task to the task scheduler
void add_task(scheduler_t* scheduler, char* name, void (*callback)(void), unsigned int frequency) {
    task_t* new_task = (task_t*) malloc(sizeof(task_t));
    new_task->name = name;
    new_task->callback = callback;
    new_task->frequency = frequency;
    new_task->next = scheduler->head;
    scheduler->head = new_task;
}

// Function to delete a task from the task scheduler
void delete_task(scheduler_t* scheduler, char* name) {
    task_t* current = scheduler->head;
    task_t* previous = NULL;

    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current!= NULL) {
        if (previous == NULL) {
            scheduler->head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to display all tasks in the task scheduler
void display_tasks(scheduler_t* scheduler) {
    task_t* current = scheduler->head;

    while (current!= NULL) {
        printf("Task Name: %s\n", current->name);
        printf("Callback: %s\n", (current->callback == NULL)? "None" : "Function");
        printf("Frequency: %u\n", current->frequency);
        printf("---------------------------------------\n");
        current = current->next;
    }
}

// Function to trigger all tasks in the task scheduler
void trigger_tasks(scheduler_t* scheduler) {
    task_t* current = scheduler->head;

    while (current!= NULL) {
        if (current->callback!= NULL) {
            current->callback();
        }
        current = current->next;
    }
}

int main() {
    scheduler_t scheduler;
    scheduler.head = NULL;

    printf("Task Scheduler\n");
    printf("-------------------------\n");

    char task_name[100];
    void (*task_callback)(void);
    unsigned int task_frequency;

    while (1) {
        printf("Add Task:\n");
        printf("Name: ");
        scanf("%s", task_name);
        printf("Callback: ");
        scanf("%s", task_name);
        printf("Frequency: ");
        scanf("%u", &task_frequency);

        task_callback = strcmp(task_name, "None") == 0? NULL : task_name;

        add_task(&scheduler, task_name, task_callback, task_frequency);

        printf("Delete Task:\n");
        printf("Name: ");
        scanf("%s", task_name);
        delete_task(&scheduler, task_name);

        printf("Display Tasks:\n");
        display_tasks(&scheduler);

        printf("Trigger Tasks:\n");
        trigger_tasks(&scheduler);
    }

    return 0;
}