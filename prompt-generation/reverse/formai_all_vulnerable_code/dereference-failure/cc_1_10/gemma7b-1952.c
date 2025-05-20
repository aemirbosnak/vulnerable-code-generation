//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int start_time;
    int end_time;
    struct Task* next;
} Task;

Task* CreateTask(char* name, int priority, int start_time, int end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;
    return newTask;
}

void AddTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        newTask->next = head;
        head = newTask;
    }
}

void ScheduleTasks(Task* head) {
    while (head) {
        printf("%s, Priority: %d, Start Time: %d, End Time: %d\n", head->name, head->priority, head->start_time, head->end_time);
        sleep(head->start_time);
        printf("Task %s completed!\n", head->name);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;
    Task* newTask1 = CreateTask("Task 1", 1, 5, 10);
    AddTask(head, newTask1);
    Task* newTask2 = CreateTask("Task 2", 2, 3, 8);
    AddTask(head, newTask2);
    ScheduleTasks(head);
    return 0;
}