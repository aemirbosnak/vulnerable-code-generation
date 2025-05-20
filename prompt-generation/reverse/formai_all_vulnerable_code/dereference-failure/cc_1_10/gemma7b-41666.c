//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_SCHEDULE_SIZE 20

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

typedef struct Schedule {
    Task** tasks;
    int size;
    int next_slot;
} Schedule;

Schedule* createSchedule() {
    Schedule* schedule = (Schedule*)malloc(sizeof(Schedule));
    schedule->tasks = (Task**)malloc(MAX_SCHEDULE_SIZE * sizeof(Task*));
    schedule->size = 0;
    schedule->next_slot = 0;
    return schedule;
}

void addTask(Schedule* schedule, char* name, int priority, int estimated_time) {
    Task* task = (Task*)malloc(sizeof(Task));
    strcpy(task->name, name);
    task->priority = priority;
    task->estimated_time = estimated_time;
    task->next = NULL;

    schedule->tasks[schedule->size++] = task;
    schedule->next_slot++;
}

void printSchedule(Schedule* schedule) {
    for (int i = 0; i < schedule->size; i++) {
        printf("%s (priority: %d, estimated time: %d)\n", schedule->tasks[i]->name, schedule->tasks[i]->priority, schedule->tasks[i]->estimated_time);
    }
}

int main() {
    Schedule* schedule = createSchedule();

    addTask(schedule, "Task 1", 1, 10);
    addTask(schedule, "Task 2", 2, 15);
    addTask(schedule, "Task 3", 3, 20);
    addTask(schedule, "Task 4", 4, 25);

    printSchedule(schedule);

    return 0;
}