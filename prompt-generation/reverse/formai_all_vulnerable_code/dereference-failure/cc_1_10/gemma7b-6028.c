//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, time_t start, time_t end) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start;
    newTask->end_time = end;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task** head, char* name, int priority, time_t start, time_t end) {
    Task* newTask = createTask(name, priority, start, end);
    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void printTasks(Task* head) {
    while (head) {
        printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", head->name, head->priority, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    Task* taskHead = NULL;
    addTask(&taskHead, "Task 1", 1, 10, 20);
    addTask(&taskHead, "Task 2", 2, 15, 25);
    addTask(&taskHead, "Task 3", 3, 20, 30);
    addTask(&taskHead, "Task 4", 4, 25, 35);
    addTask(&taskHead, "Task 5", 5, 30, 40);

    printTasks(taskHead);

    return 0;
}