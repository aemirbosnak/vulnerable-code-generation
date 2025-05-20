//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int executionTime;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, int executionTime) {
    Task* newNode = (Task*)malloc(sizeof(Task));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->executionTime = executionTime;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Task* current = head;
        Task* previous = NULL;
        while (current) {
            if (newNode->priority < current->priority) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }
        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

void executeTasks(Task* head) {
    time_t currentTime = time(NULL);
    Task* current = head;
    while (current) {
        if (currentTime >= current->executionTime) {
            printf("%s is executed\n", current->name);
            current->executionTime = currentTime + 1;
        }
        current = current->next;
    }
}

int main() {
    Task* head = NULL;
    head = insertTask(head, "Task 1", 1, 10);
    head = insertTask(head, "Task 2", 2, 20);
    head = insertTask(head, "Task 3", 3, 30);

    executeTasks(head);

    return 0;
}