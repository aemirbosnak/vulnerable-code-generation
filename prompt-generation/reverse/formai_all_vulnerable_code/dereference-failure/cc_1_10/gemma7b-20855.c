//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int start_hour, start_minute, end_hour, end_minute;
    struct Task* next;
} Task;

Task* createTask(char* name, int start_hour, int start_minute, int end_hour, int end_minute) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->start_hour = start_hour;
    newTask->start_minute = start_minute;
    newTask->end_hour = end_hour;
    newTask->end_minute = end_minute;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task* head, char* name, int start_hour, int start_minute, int end_hour, int end_minute) {
    Task* newTask = createTask(name, start_hour, start_minute, end_hour, end_minute);
    if (head == NULL) {
        head = newTask;
    } else {
        newTask->next = head;
        head = newTask;
    }
}

void printSchedule(Task* head) {
    while (head) {
        printf("%s: %d:%d - %d:%d\n", head->name, head->start_hour, head->start_minute, head->end_hour, head->end_minute);
        head = head->next;
    }
}

int main() {
    Task* schedule = NULL;
    addTask(schedule, "Wake up", 7, 0, 8, 0);
    addTask(schedule, "Breakfast", 8, 0, 9, 0);
    addTask(schedule, "School", 9, 0, 16, 0);
    addTask(schedule, "Lunch", 12, 0, 1, 0);
    addTask(schedule, "Study", 1, 0, 4, 0);
    addTask(schedule, "Dinner", 5, 0, 6, 0);
    addTask(schedule, "Sleep", 6, 0, 7, 0);

    printSchedule(schedule);

    return 0;
}