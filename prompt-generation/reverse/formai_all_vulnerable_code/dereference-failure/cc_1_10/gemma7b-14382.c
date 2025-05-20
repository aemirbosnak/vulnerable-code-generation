//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int time_slot;
    struct task* next;
} task;

void create_task(char* name, int time_slot) {
    task* new_task = (task*)malloc(sizeof(task));
    strcpy(new_task->name, name);
    new_task->time_slot = time_slot;
    new_task->next = NULL;

    return;
}

void schedule_tasks(task* head) {
    time_t now = time(NULL);
    time_t next_slot = now + 60;
    task* current_task = head;

    while (current_task) {
        if (current_task->time_slot >= next_slot) {
            printf("%s is starting now!\n", current_task->name);
            next_slot = current_task->time_slot + 60;
        }
        current_task = current_task->next;
    }

    return;
}

int main() {
    task* head = NULL;

    create_task("Wake up", 8);
    create_task("Breakfast", 9);
    create_task("School", 10);
    create_task("Lunch", 12);
    create_task("Homework", 13);
    create_task("Dinner", 18);
    create_task("Watch TV", 19);

    schedule_tasks(head);

    return 0;
}