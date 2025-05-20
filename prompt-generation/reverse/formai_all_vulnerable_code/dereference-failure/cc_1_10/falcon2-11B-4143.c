//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 100
#define MAX_TASK_PRIORITY 10

typedef struct {
    char task_name[MAX_TASK_NAME];
    int task_priority;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void create_task(char* task_name, int priority) {
    if (num_tasks >= MAX_TASKS) {
        printf("Task list is full. Cannot create more tasks.\n");
        return;
    }

    Task new_task;
    strcpy(new_task.task_name, task_name);
    new_task.task_priority = priority;

    tasks[num_tasks] = new_task;
    num_tasks++;
}

void sort_tasks() {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = 0; j < num_tasks - i - 1; j++) {
            if (tasks[j].task_priority > tasks[j + 1].task_priority) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

void print_tasks() {
    printf("Task List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s (%d)\n", tasks[i].task_name, tasks[i].task_priority);
    }
}

int main() {
    srand(time(NULL));

    char task1_name[MAX_TASK_NAME];
    char task2_name[MAX_TASK_NAME];
    int task1_priority = rand() % MAX_TASK_PRIORITY + 1;
    int task2_priority = rand() % MAX_TASK_PRIORITY + 1;

    create_task(task1_name, task1_priority);
    create_task(task2_name, task2_priority);

    sort_tasks();
    print_tasks();

    return 0;
}