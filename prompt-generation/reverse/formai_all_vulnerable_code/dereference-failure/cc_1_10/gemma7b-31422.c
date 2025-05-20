//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <time.h>

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newTask;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);
    Task* current = head;

    while (current) {
        int scheduledTime = current->priority * now;
        if (scheduledTime == now) {
            printf("%s is running now!\n", current->name);
            current = current->next;
        } else if (scheduledTime < now) {
            printf("%s has finished running.\n", current->name);
            current = current->next;
        } else {
            break;
        }
    }
}

int main() {
    addTask("Task 1", 1);
    addTask("Task 2", 2);
    addTask("Task 3", 3);

    scheduleTasks();

    return 0;
}