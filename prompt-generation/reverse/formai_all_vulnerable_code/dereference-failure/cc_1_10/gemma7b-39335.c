//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_TIME 5

typedef struct task_t {
    char name[20];
    int (*function)(void);
    struct task_t* next;
} task_t;

void task_add(task_t** head, char* name, int (*function)(void)) {
    task_t* new_task = malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    new_task->function = function;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void task_scheduler(task_t* head) {
    time_t now = time(NULL);
    task_t* current = head;

    while (current) {
        if (time(NULL) - now >= TASK_TIME) {
            (current->function)();
            now = time(NULL);
        }
        current = current->next;
    }
}

int task_one(void) {
    printf("I am task one!\n");
    return 0;
}

int task_two(void) {
    printf("I am task two!\n");
    return 0;
}

int main() {
    task_t* head = NULL;

    task_add(&head, "Task One", task_one);
    task_add(&head, "Task Two", task_two);

    task_scheduler(head);

    return 0;
}