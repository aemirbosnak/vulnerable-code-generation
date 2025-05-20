//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* head = NULL;

void schedule_task(char* name, time_t start_time, time_t end_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
}

void display_schedule() {
    Task* temp = head;
    printf("Tasks scheduled:\n");
    while (temp) {
        printf("Name: %s, Start Time: %d, End Time: %d\n", temp->name, temp->start_time, temp->end_time);
        temp = temp->next;
    }
}

int main() {
    schedule_task("Wake up", 7, 9);
    schedule_task("Breakfast", 9, 10);
    schedule_task("Work", 10, 18);
    schedule_task("Lunch", 13, 14);
    schedule_task("Gym", 16, 17);
    schedule_task("Dinner", 19, 20);
    schedule_task("Relax", 20, 22);

    display_schedule();

    return 0;
}