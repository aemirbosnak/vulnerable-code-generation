//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    char name[100];
    int time;
    struct Task* next;
} Task;

Task* newTask(char name[], int time) {
    Task* task = (Task*)malloc(sizeof(Task));
    strcpy(task->name, name);
    task->time = time;
    task->next = NULL;
    return task;
}

void addTask(Task** head, char name[], int time) {
    Task* task = newTask(name, time);
    if (*head == NULL) {
        *head = task;
    } else {
        Task* curr = *head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = task;
    }
}

void removeTask(Task** head, char name[]) {
    Task* curr = *head;
    Task* prev = NULL;
    while (curr!= NULL && strcmp(curr->name, name)!= 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Task not found\n");
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void printTasks(Task* head) {
    Task* curr = head;
    while (curr!= NULL) {
        printf("%s %d\n", curr->name, curr->time);
        curr = curr->next;
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 10);
    addTask(&head, "Task 2", 20);
    printTasks(head);

    removeTask(&head, "Task 1");
    printTasks(head);

    return 0;
}