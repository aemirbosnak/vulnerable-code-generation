//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority) {
    Task* newNode = (Task*)malloc(sizeof(Task));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Task* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    return head;
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            currentTask = currentTask->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* scheduler = NULL;

    insertTask(scheduler, "Task 1", 10);
    insertTask(scheduler, "Task 2", 8);
    insertTask(scheduler, "Task 3", 12);
    insertTask(scheduler, "Task 4", 9);

    scheduleTasks(scheduler);

    return 0;
}