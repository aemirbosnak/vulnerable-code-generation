//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: secure
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int seconds;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int seconds) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->seconds = seconds;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    time_t nextTaskTime = now + head->seconds;

    while (head) {
        if (now < nextTaskTime) {
            sleep(head->seconds - (int)(now - nextTaskTime));
            printf("%s completed!\n", head->name);
            nextTaskTime = now + head->seconds;
        } else {
            head = head->next;
        }
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Task 1", 5);
    addTask(&head, "Task 2", 10);
    addTask(&head, "Task 3", 15);

    scheduleTasks(head);

    return 0;
}