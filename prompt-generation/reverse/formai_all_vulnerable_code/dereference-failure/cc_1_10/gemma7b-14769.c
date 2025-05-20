//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
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
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newTask;
    }

    return head;
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (currentTask->priority == now) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(1);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* scheduler = NULL;

    insertTask(scheduler, "Task 1", 5);
    insertTask(scheduler, "Task 2", 3);
    insertTask(scheduler, "Task 3", 2);
    insertTask(scheduler, "Task 4", 4);

    scheduleTasks(scheduler);

    return 0;
}