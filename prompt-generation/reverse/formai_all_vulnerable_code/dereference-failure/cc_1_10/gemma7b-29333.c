//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

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
        int taskTime = current->priority * 60;
        if (now >= taskTime) {
            printf("%s has completed!\n", current->name);
            free(current);
            current = head;
        } else {
            current = current->next;
        }
    }

    printf("No tasks to complete.\n");
}

int main() {
    addTask("Wash dishes", 1);
    addTask("Do laundry", 2);
    addTask("Buy groceries", 3);
    addTask("Study", 4);

    scheduleTasks();

    return 0;
}