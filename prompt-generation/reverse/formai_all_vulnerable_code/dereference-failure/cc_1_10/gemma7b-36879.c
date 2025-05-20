//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, int time_slot) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->time_slot = time_slot;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task** head, char* name, int priority, int time_slot) {
    Task* newTask = createTask(name, priority, time_slot);
    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t currentTime = time(NULL);
    time_t nextTimeSlot = currentTime + head->time_slot;

    while (head) {
        if (currentTime >= head->time_slot) {
            printf("Task: %s, Priority: %d\n", head->name, head->priority);
            head = head->next;
        } else {
            break;
        }
    }

    printf("Next time slot: %ld\n", nextTimeSlot);
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 1, 10);
    addTask(&head, "Task 2", 2, 20);
    addTask(&head, "Task 3", 3, 30);

    scheduleTasks(head);

    return 0;
}