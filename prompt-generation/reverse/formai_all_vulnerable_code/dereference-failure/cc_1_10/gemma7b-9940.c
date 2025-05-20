//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->start_time = start_time;
    newTask->end_time = end_time;
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

    Task* currentTask = head;
    while (currentTask) {
        if (now >= currentTask->start_time && now < currentTask->end_time) {
            printf("Task: %s, Start Time: %s, End Time: %s\n", currentTask->name, currentTask->start_time, currentTask->end_time);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    addTask("Wake up", 7 * 60 * 0, 8 * 60 * 0);
    addTask("Breakfast", 8 * 60 * 0, 9 * 60 * 0);
    addTask("School", 9 * 60 * 0, 16 * 60 * 0);
    addTask("Lunch", 13 * 60 * 0, 14 * 60 * 0);
    addTask("Homework", 14 * 60 * 0, 16 * 60 * 0);
    addTask("Dinner", 18 * 60 * 0, 19 * 60 * 0);
    addTask("Watch TV", 19 * 60 * 0, 20 * 60 * 0);

    scheduleTasks();

    return 0;
}