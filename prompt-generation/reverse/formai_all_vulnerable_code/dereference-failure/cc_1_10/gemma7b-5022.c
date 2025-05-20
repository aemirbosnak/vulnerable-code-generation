//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, time_t start, time_t end) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->start_time = start;
    new_task->end_time = end;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void schedule() {
    time_t now = time(NULL);

    Task* current = head;
    while (current) {
        if (now >= current->start_time && now <= current->end_time) {
            printf("Task: %s, Start Time: %s, End Time: %s\n", current->name, current->start_time, current->end_time);
        }
        current = current->next;
    }
}

int main() {
    add_task("Wake up", 8 * 60, 9 * 60);
    add_task("Breakfast", 9 * 60, 10 * 60);
    add_task("Work", 10 * 60, 18 * 60);
    add_task("Lunch", 13 * 60, 14 * 60);
    add_task("Rest", 16 * 60, 17 * 60);
    add_task("Dinner", 19 * 60, 20 * 60);

    schedule();

    return 0;
}