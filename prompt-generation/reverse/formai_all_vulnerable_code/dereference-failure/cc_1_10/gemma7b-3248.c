//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
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

Task* head = NULL;

void addTask(char* name, int priority, int start_time, int end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
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

void displayTasks() {
    Task* currentTask = head;
    while (currentTask) {
        printf("%s (%d) - Start: %d, End: %d\n", currentTask->name, currentTask->priority, currentTask->start_time, currentTask->end_time);
        currentTask = currentTask->next;
    }
}

void scheduleTasks() {
    time_t now = time(NULL);
    Task* currentTask = head;
    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("%s is running...\n", currentTask->name);
            sleep(1);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    addTask("Task 1", 1, 10, 20);
    addTask("Task 2", 2, 15, 25);
    addTask("Task 3", 3, 20, 30);

    displayTasks();

    scheduleTasks();

    return 0;
}