//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority) {
    Task* newNode = (Task*)malloc(sizeof(Task));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void printTasks(Task* head) {
    while (head) {
        printf("%s (priority: %d)\n", head->name, head->priority);
        head = head->next;
    }
}

void scheduleTasks(Task* head) {
    time_t currentTime = time(NULL);
    int i = 0;

    for (head = head; head; head = head->next) {
        int scheduledTime = head->priority * 10;
        if (currentTime >= scheduledTime) {
            printf("Executing task: %s\n", head->name);
            free(head);
            i++;
        }
    }

    if (i == 0) {
        printf("No tasks to execute.\n");
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 5);
    insertTask(&head, "Task 2", 3);
    insertTask(&head, "Task 3", 7);
    insertTask(&head, "Task 4", 1);
    insertTask(&head, "Task 5", 2);

    scheduleTasks(head);

    return 0;
}