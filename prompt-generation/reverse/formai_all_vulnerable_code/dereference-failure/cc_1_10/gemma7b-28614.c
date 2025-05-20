//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int estimated_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->estimated_time = estimated_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;
    Task* currentTask = head;

    while (currentTask) {
        int estimatedTime = currentTask->estimated_time;
        int remainingTime = estimatedTime - (int)now;

        if (remainingTime > 0) {
            printf("Task: %s, Estimated Time: %d minutes, Remaining Time: %d minutes\n", currentTask->name, estimatedTime, remainingTime);
            i++;
        }
        currentTask = currentTask->next;
    }

    if (i == 0) {
        printf("No tasks to schedule.\n");
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Laundry", 1, 20);
    insertTask(&head, "Groceries", 3, 30);
    insertTask(&head, "School", 2, 40);
    insertTask(&head, "Dinner", 4, 50);
    insertTask(&head, "Movie", 5, 60);

    scheduleTasks(head);

    return 0;
}