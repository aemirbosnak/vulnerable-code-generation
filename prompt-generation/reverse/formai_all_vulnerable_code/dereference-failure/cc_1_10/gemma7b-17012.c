//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
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

void scheduleTasks(Task* head) {
    time_t currentTime = time(NULL);
    time_t nextTime = currentTime + 60;
    Task* currentTask = head;

    while (currentTask) {
        if (currentTime >= currentTask->priority) {
            printf("%s has begun!\n", currentTask->name);
            currentTime = nextTime;
            nextTime += 60;
        }
        currentTask = currentTask->next;
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Breakfast", 8);
    insertTask(&head, "Work", 12);
    insertTask(&head, "Dinner", 6);

    scheduleTasks(head);

    return 0;
}