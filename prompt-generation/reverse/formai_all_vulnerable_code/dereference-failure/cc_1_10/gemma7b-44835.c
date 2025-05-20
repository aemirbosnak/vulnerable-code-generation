//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: unmistakable
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int duration;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int duration) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        head->next = newTask;
        head = newTask;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    int hour_now = tm_now->tm_hour;

    for (Task* currentTask = head; currentTask; currentTask = currentTask->next) {
        int hour_start = currentTask->duration / 24;
        int minute_start = (currentTask->duration % 24) * 60 / 60;

        if (hour_start == hour_now && minute_start == 0) {
            printf("Starting task: %s\n", currentTask->name);
            sleep(currentTask->duration);
            printf("Task completed: %s\n", currentTask->name);
        }
    }
}

int main() {
    addTask("Task 1", 10);
    addTask("Task 2", 15);
    addTask("Task 3", 20);
    addTask("Task 4", 5);
    addTask("Task 5", 30);

    scheduleTasks();

    return 0;
}