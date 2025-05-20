//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority, time_t scheduled_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);
    Task* current = head;

    while (current) {
        if (current->scheduled_time <= now) {
            printf("Executing task: %s\n", current->name);
            sleep(5); // Simulate execution time
        }
        current = current->next;
    }
}

int main() {
    addTask("Task 1", 1, time(NULL) + 3600);
    addTask("Task 2", 2, time(NULL) + 1800);
    addTask("Task 3", 1, time(NULL) + 600);
    addTask("Task 4", 2, time(NULL) + 900);

    scheduleTasks();

    return 0;
}