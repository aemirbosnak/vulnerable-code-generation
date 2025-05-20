//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <time.h>

#define NUM_TASKS 5

struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
};

void addTask(struct Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    struct Task* newTask = malloc(sizeof(struct Task));
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

void scheduleTasks(struct Task* head) {
    time_t current_time = time(NULL);
    struct Task* currentTask = head;

    while (currentTask) {
        if (current_time >= currentTask->start_time && current_time < currentTask->end_time) {
            printf("Executing task: %s\n", currentTask->name);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    struct Task* tasks = NULL;
    addTask(&tasks, "Task 1", 1, 10, 15);
    addTask(&tasks, "Task 2", 2, 12, 17);
    addTask(&tasks, "Task 3", 3, 14, 19);
    addTask(&tasks, "Task 4", 4, 16, 21);
    addTask(&tasks, "Task 5", 5, 18, 23);

    scheduleTasks(tasks);

    return 0;
}