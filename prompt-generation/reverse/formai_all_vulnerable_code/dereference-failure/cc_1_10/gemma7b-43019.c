//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    time_t next_execution = now + head->duration;

    while (head) {
        printf("Task: %s, Execution Time: %ld\n", head->name, next_execution);

        head = head->next;
        next_execution += head->duration;
    }
}

int main() {
    Task* head = NULL;

    // Create a few tasks
    Task* task1 = malloc(sizeof(Task));
    strcpy(task1->name, "Task 1");
    task1->duration = 10;

    Task* task2 = malloc(sizeof(Task));
    strcpy(task2->name, "Task 2");
    task2->duration = 15;

    Task* task3 = malloc(sizeof(Task));
    strcpy(task3->name, "Task 3");
    task3->duration = 20;

    Task* task4 = malloc(sizeof(Task));
    strcpy(task4->name, "Task 4");
    task4->duration = 25;

    Task* task5 = malloc(sizeof(Task));
    strcpy(task5->name, "Task 5");
    task5->duration = 30;

    // Link the tasks together
    head = task1;
    task1->next = task2;
    task2->next = task3;
    task3->next = task4;
    task4->next = task5;

    // Schedule the tasks
    scheduleTasks(head);

    return 0;
}