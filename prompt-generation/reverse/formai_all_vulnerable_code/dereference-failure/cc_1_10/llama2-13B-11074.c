//LLAMA2-13B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[20];
    char description[MAX_DESCRIPTION_LEN];
    time_t due_time;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, char *description, time_t due_time) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    strcpy(new_task->description, description);
    new_task->due_time = due_time;
    if (num_tasks == MAX_TASKS) {
        printf("Error: Maximum number of tasks reached!\n");
        return;
    }
    tasks[num_tasks++] = *new_task;
}

void print_schedule() {
    printf("Schedule:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task: %s\nDescription: %s\nDue Time: %s\n",
               tasks[i].name, tasks[i].description, ctime(&tasks[i].due_time));
    }
}

void run_schedule() {
    for (int i = 0; i < num_tasks; i++) {
        if (time(NULL) >= tasks[i].due_time) {
            printf("Task %s completed at %s\n", tasks[i].name, ctime(&tasks[i].due_time));
            break;
        }
    }
}

int main() {
    char name[20];
    char description[MAX_DESCRIPTION_LEN];
    time_t due_time;

    // Add some tasks
    add_task("Buy milk", "Don't forget to buy milk on your way home", time(NULL) + 300);
    add_task("Pick up dry cleaning", "Make sure to pick up your dry cleaning before 5pm", time(NULL) + 200);
    add_task("Call mom", "Don't forget to call your mom today", time(NULL) + 400);

    // Print the schedule
    print_schedule();

    // Run the schedule
    run_schedule();

    return 0;
}