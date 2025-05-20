//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: romantic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int duration) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    time_t nextTaskTime = now + head->duration;

    while (head) {
        if (now >= nextTaskTime) {
            printf("Executing task: %s\n", head->name);
            sleep(head->duration);
            nextTaskTime = now + head->duration;
        } else {
            break;
        }
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Dinner", 60);
    addTask(&head, "Movie Night", 90);
    addTask(&head, "Shopping", 30);

    scheduleTasks(head);

    return 0;
}