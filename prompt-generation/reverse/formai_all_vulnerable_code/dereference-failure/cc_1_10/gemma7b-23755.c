//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* CreateTask(char* name, int priority, time_t start_time, time_t end_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;
    return new_task;
}

void AddTask(Task* head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* new_task = CreateTask(name, priority, start_time, end_time);
    if (head == NULL) {
        head = new_task;
    } else {
        new_task->next = head;
        head = new_task;
    }
}

void ScheduleTasks(Task* head) {
    time_t current_time = time(NULL);
    Task* current_task = head;
    while (current_task) {
        if (current_time >= current_task->start_time && current_time < current_task->end_time) {
            printf("Task: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", current_task->name, current_task->priority, current_task->start_time, current_task->end_time);
        }
        current_task = current_task->next;
    }
}

int main() {
    Task* head = NULL;
    AddTask(head, "Task 1", 1, 10, 20);
    AddTask(head, "Task 2", 2, 15, 25);
    AddTask(head, "Task 3", 3, 20, 30);
    AddTask(head, "Task 4", 4, 25, 35);
    AddTask(head, "Task 5", 5, 30, 40);

    ScheduleTasks(head);

    return 0;
}