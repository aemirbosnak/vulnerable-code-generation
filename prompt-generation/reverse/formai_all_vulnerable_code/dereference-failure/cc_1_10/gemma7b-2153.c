//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int start_time;
    int end_time;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, int start_time, int end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("%s is running...\n", currentTask->name);
            sleep(currentTask->end_time - currentTask->start_time);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 1, 10, 20);
    addTask(&head, "Task 2", 2, 15, 25);
    addTask(&head, "Task 3", 3, 20, 30);

    scheduleTasks(head);

    return 0;
}