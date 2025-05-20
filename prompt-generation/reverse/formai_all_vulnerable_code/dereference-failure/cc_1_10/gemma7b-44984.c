//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SCHED_SIZE 10

typedef struct Task {
    char name[20];
    void (*func)(void);
    struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, void (*func)(void))
{
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->func = func;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        head->next = new_task;
        head = new_task;
    }
}

void scheduler()
{
    Task* current = head;

    while (current) {
        sleep(1);
        printf("Executing task: %s\n", current->name);
        current->func();
        printf("Task %s completed.\n", current->name);
        current = current->next;
    }
}

void task_one()
{
    printf("I am task one!\n");
}

void task_two()
{
    printf("I am task two!\n");
}

int main()
{
    add_task("Task One", task_one);
    add_task("Task Two", task_two);

    scheduler();

    return 0;
}