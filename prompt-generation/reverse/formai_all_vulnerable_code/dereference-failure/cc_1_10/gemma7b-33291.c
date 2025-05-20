//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 5

typedef struct Task {
    char name[20];
    int priority;
    int estimated_execution_time;
    struct Task* next;
} Task;

Task* insert_task(Task* head, char* name, int priority, int estimated_execution_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_execution_time = estimated_execution_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* current = head;
        Task* previous = NULL;
        while (current) {
            if (new_task->priority < current->priority) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }

        if (previous) {
            previous->next = new_task;
        } else {
            head = new_task;
        }
    }

    return head;
}

void execute_tasks(Task* head) {
    time_t start_time = time(NULL);

    while (head) {
        printf("Executing task: %s\n", head->name);
        sleep(head->estimated_execution_time);
        head = head->next;
    }

    time_t end_time = time(NULL);
    printf("Total execution time: %ld seconds\n", end_time - start_time);
}

int main() {
    Task* head = NULL;

    insert_task(head, "Task 1", 1, 5);
    insert_task(head, "Task 2", 2, 3);
    insert_task(head, "Task 3", 3, 2);
    insert_task(head, "Task 4", 4, 4);
    insert_task(head, "Task 5", 5, 3);

    execute_tasks(head);

    return 0;
}