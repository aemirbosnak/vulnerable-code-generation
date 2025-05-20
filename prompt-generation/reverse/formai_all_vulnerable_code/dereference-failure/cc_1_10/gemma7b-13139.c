//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void insertTask(Task* head, char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newTask;
    }
}

void printTasks(Task* head) {
    while (head) {
        printf("%s (priority: %d)\n", head->name, head->priority);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(head, "Wake up", 1);
    insertTask(head, "Breakfast", 2);
    insertTask(head, "School", 3);
    insertTask(head, "Lunch", 2);
    insertTask(head, "Coding", 4);
    insertTask(head, "Dinner", 2);
    insertTask(head, "Sleep", 1);

    printTasks(head);

    return 0;
}