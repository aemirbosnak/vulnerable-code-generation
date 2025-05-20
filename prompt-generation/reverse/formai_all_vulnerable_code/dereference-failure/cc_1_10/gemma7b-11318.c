//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct task_t {
    char name[20];
    int priority;
    int execution_time;
    struct task_t* next;
} task_t;

void insert_task(task_t* head, char* name, int priority, int execution_time) {
    task_t* new_task = malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        task_t* last_task = head;
        while (last_task->next) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    }
}

void schedule_tasks(task_t* head) {
    time_t now = time(NULL);
    task_t* current_task = head;

    while (current_task) {
        if (current_task->execution_time <= now) {
            printf("%s is running...\n", current_task->name);
            sleep(current_task->execution_time);
            printf("%s has finished running.\n", current_task->name);
            free(current_task);
            current_task = head;
        } else {
            current_task = current_task->next;
        }
    }

    printf("All tasks have been completed.\n");
}

int main() {
    task_t* head = NULL;

    insert_task(head, "Task 1", 1, 5);
    insert_task(head, "Task 2", 2, 3);
    insert_task(head, "Task 3", 3, 2);
    insert_task(head, "Task 4", 4, 4);

    schedule_tasks(head);

    return 0;
}