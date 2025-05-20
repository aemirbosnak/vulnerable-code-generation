//FormAI DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int interval;
    int next_execution_time;
    void (*task)();
} Task;

Task tasks[MAX_TASKS];
int num_of_tasks = 0;

void add_task(char name[], int interval, void (*task)()) {
    if (num_of_tasks >= MAX_TASKS) {
        printf("Max task limit reached, can't add more tasks.\n");
        return;
    }
    Task new_task = {
        .interval = interval,
        .next_execution_time = interval,
        .task = task
    };
    for (int i = 0; i < MAX_NAME_LENGTH; i++)
        new_task.name[i] = name[i];
    tasks[num_of_tasks++] = new_task;
}

void delete_task(char name[]) {
    for (int i = 0; i < num_of_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            for (int j = i; j < num_of_tasks - 1; j++)
                tasks[j] = tasks[j + 1];
            num_of_tasks--;
            printf("Task %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Task %s doesn't exist.\n", name);
}

void execute_tasks() {
    for (int i = 0; i < num_of_tasks; i++) {
        if (tasks[i].next_execution_time == 0) {
            tasks[i].task(); // Execute task
            tasks[i].next_execution_time = tasks[i].interval;
        } else {
            tasks[i].next_execution_time--;
        }
    }
}

void task1() {
    printf("This is task 1.\n");
}

void task2() {
    printf("This is task 2.\n");
}

void task3() {
    printf("This is task 3.\n");
}

int main() {
    add_task("Task 1", 2, task1);
    add_task("Task 2", 3, task2);
    add_task("Task 3", 4, task3);

    printf("Tasks added successfully.\n\n");

    int time = 10;

    printf("Executing tasks for %d seconds:\n\n", time);

    for (int i = 0; i < time; i++) {
        execute_tasks();
        printf("--------------------\n");
    }

    delete_task("Task 2");

    printf("\nAfter deleting the task:\n\n");

    for (int i = 0; i < time; i++) {
        execute_tasks();
        printf("--------------------\n");
    }

    return 0;
}